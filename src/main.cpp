#include <Arduino.h>

#include "Movement.h"
#include "screen.h"
#include "tof.h"
#include "timer.h"
#include "strategy.h"
#include "DFPlayer.h"
#include "servo.h"
#include "led.h"

#include "wallpaper.h"
#include "pami.h"

#include "PAMIBOARD.h"
#include "utils.h"
#include <Wire.h>

void fullstop();
void refresh();

Screen screen;
Movement movement;
Strategy strategy;
TOF tof;
Timer globaltimer = Timer(&fullstop, 100, seconds);
Timer updatetimer = Timer(&refresh, 1, seconds);
DFPlayer player;
SERVO servo;


char team;

void fullstop(){
    //strategy.fullstop();
    updatetimer.stop();
    globaltimer.stop();

}

void refresh(){
  // a afficher tt les secondes
  return;
}



void setup()
{
  // Initialisation UART
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  // Initialisation I2C - ordre très important ! 
  screen.begin();
  Wire.begin(I2C::SDA, I2C::SCL); 

  // Initialisation ESPNow
  setupESPNow();

  //Initialisation des périphériques
  screen.setup(incomming.team); // Setup screen
  tof.setup(highSpeed); // Setup ToF
  player.setup();
  setup_LED(); 
  strategy.setup();

  // Attente tirette
  while(incomming.tir != true){
    setLEDColor(Colors::RED);
  }

  // Tirette posée
  setLEDColor(Colors::ORANGE);
  
  // Attente retirer tirette
  while(incomming.tir == true){
    setLEDColor(Colors::ORANGE);
  }

  // Tirette retirée
  setLEDColor(Colors::GREEN);

  // Initialisation du timer
  globaltimer.start();


}

void loop(){

  int distance1 = tof.getDistance(1);
  int distance2 = tof.getDistance(0);
  uint8_t timer = globaltimer.getRemainingTime(seconds);
  bool espnow = false;
  bool tir = false;
  screen.draw(timer, distance1, distance2, tir, espnow);
}
