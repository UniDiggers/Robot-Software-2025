#include <Wire.h>
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

void fullstop();
void refresh();
void timer_switch();

Screen screen;
Movement movement;
Strategy strategy;
TOF tof;
Timer globaltimer = Timer(&fullstop, 100, seconds);
Timer updatetimer = Timer(&timer_switch, 1, seconds);
DFPlayer player;
SERVO servo;

bool SWITCH = false;
char team;

void fullstop(){
    //strategy.fullstop();
    updatetimer.stop();
    globaltimer.stop();

}

void refresh(){
  // a afficher tt les secondes
  SWITCH = false;
}

void timer_switch(){
  SWITCH = true;
}


void setup()
{
  // Initialisation UART
  Serial.begin(115200);

  // Initialisation I2C
  Wire.begin(I2C::SDA, I2C::SCL); // I2C screen
  Wire.setClock(400000); // Set I2C clock to 400kHz

  // Initialisation des boutons
  pinMode(STATE::TEAM, INPUT_PULLUP);
  pinMode(STATE::TIR, INPUT_PULLUP);

  //Initialisation des périphériques
  screen.setup(); // Setup screen
  tof.setup(highSpeed); // Setup ToF
  servo.setup(); // Setup servos  
  player.setup();
  //STATE = false;
  //strategy.setup();

  // Initialisation du timer
  globaltimer.start();
  updatetimer.start();

}

void loop(){
  //SCREEN REFRESH - 1x/sec
  // if(SWITCH){
  //   refresh();
  // }

  delay(1);
}
