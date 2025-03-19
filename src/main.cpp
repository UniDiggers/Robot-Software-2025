#include <Wire.h>
#include <Arduino.h>

#include "buzzer.h"
#include "Movement.h"
#include "screen.h"
#include "tof.h"
#include "timer.h"
#include "strategy.h"
#include "DFPlayer.h"

#include "wallpaper.h"
#include "dabble.h"

#include "QuentbinksBoard.h"
#include "utils.h"

#define DEBUG 1

void fullstop();
void refresh();

Screen screen;
Buzzer buzzer1;
Movement movement;
Strategy strategy;
TOF tof;
Timer endtimer = Timer(100, &fullstop, false);
Timer updatetimer = Timer(1, &refresh, true);

DFPlayer player;




char team;

void fullstop(){
    strategy.fullstop();
}

void refresh(){
  // Display
  screen.drawHome();
  screen.tofDraw(tof.getDistance());
  screen.timerDraw(endtimer.getRemainingTime());
  screen.update();
}


void setup()
{

  // Initialisation UART
  Serial.begin(115200);
  //delay(500);

  // Initialisation I2C
  pinMode(PIN::TEAM, INPUT_PULLUP);
  pinMode(PIN::TIR, INPUT_PULLUP);
  Wire.begin(PIN::I2C::SDA, PIN::I2C::SCL); // I2C screen
  //delay(500);

  // Initialisation du DFPlayer
  bool STATE = player.setup();
  STATE = false;
  
  // Initialisation de l'écran
  if (!screen.setup()){
    Serial.println("Screen setup failed");
    player.Play(STATE, SCREEN_NOK, VOLUME, 1500);
  }

  // Initialisation du capteur ToF
  if (!tof.setup(highAccuracy)){
    Serial.println("TOF setup failed");
    player.Play(STATE, TOF_NOK, VOLUME, 1500);
  }
  else
    player.Play(STATE, TOF_OK, VOLUME, 1500);

  // Initialisation de l'équipe
  if (digitalRead(PIN::TEAM) == LOW){
      team = 'b';
      player.Play(STATE, TEAM_BLUE, VOLUME, 1500);
  }
  else if (digitalRead(PIN::TEAM) == HIGH){
      team = 'y';
      player.Play(STATE, TEAM_YELLOW, VOLUME, 1500);
  }
  else
      Serial.println("Error: team selection failed");

  // Initialisation du bluetooth
  if(!setup_dabble()){
    Serial.println("Bluetooth setup failed");
    player.Play(STATE, BLUETOOTH_NOK, VOLUME, 1500);
  }
  else
    player.Play(STATE, BLUETOOTH_OK, VOLUME, 1500);


  //player.Play(STATE, MICKEY2, 20, 30000);
  strategy.setup();
  player.Play(STATE, CRAZY_FROG, VOLUME, 0);
  
  // Initialisation du timer
  endtimer.start();
  //updatetimer.start();
}

void loop(){
  
  

  dabble_loop(movement, strategy);
  
    
  

}
