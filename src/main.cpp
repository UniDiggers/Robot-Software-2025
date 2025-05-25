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

#define TIR true

void fullstop();
void refresh();

Screen screen;
Movement movement;
Strategy strategy;
TOF tof;
Timer globaltimer = Timer(&fullstop, 85, seconds);
Timer updatetimer = Timer(&refresh, 1, seconds);
//DFPlayer player;
SERVO servo;

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
  //Serial.setDebugOutput(true);
  Serial.println("Starting...");

  // Initialisation I2C - ordre très important ! 
  Wire.begin(I2C::SDA, I2C::SCL); 
  
  if (TIR){
    // Initialisation ESPNow
    setupESPNow();

    //Initialisation des périphériques
    screen.begin();
    screen.setup(incomming.team); // Setup screen
    tof.setup(highAccuracy); // Setup ToF
    //player.setup();
    setup_LED(); 
    strategy.setup();

    // Attente tirette
    setLEDColor(Colors::_RED); 
    while(incomming.tir == false){  
      Serial.println("Waiting for tir");
    }

    // Tirette posée
    setLEDColor(Colors::_ORANGE);
    
    // Attente retirer tirette
    while(incomming.tir == true){
      Serial.println("Waiting for tir to be removed");
    }

    // Tirette retirée
    Serial.println("Tir removed");
    setLEDColor(Colors::_GREEN);
  }

  // Initialisation du timer
  globaltimer.start();

  // Son
  //player.Play(true, 1, 20); // Joue le son de démarrage
  Serial.println("Setup complete");
}

void loop(){

  int distance1 = tof.getDistance(1);
  int distance2 = tof.getDistance(0);
  uint8_t timer = globaltimer.getRemainingTime(seconds);
  bool espnow = true;
  bool tir = incomming.tir;
  char team = incomming.team;
  screen.draw(timer, distance1, distance2, tir, team, espnow); 
  delay(50);
  


}
