#include <Arduino.h>

#include "Movement.h"
#include "screen.h"
#include "tof.h"
#include "timer.h"
#include "strategy.h"
#include "DFPlayer.h"
#include "servo.h"

#include "wallpaper.h"

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

  Serial.println("Starting...");


  // Initialisation I2C - ordre très important ! 
  screen.begin();
  Wire.begin(I2C::SDA, I2C::SCL); 

  //Initialisation des périphériques
  screen.setup('b'); // Setup screen
  tof.setup(highSpeed); // Setup ToF
  //servo.setup(); // Setup servos  
  player.setup();
  strategy.setup();

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
