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

void fullstop();
void refresh();
void timer_switch();

Screen screen;
Buzzer buzzer1;
Movement movement;
Strategy strategy;
TOF tof;
Timer globaltimer = Timer(&fullstop, 100, seconds);
Timer updatetimer = Timer(&timer_switch, 1, seconds);
DFPlayer player;

bool SWITCH = false;
char team;

void fullstop(){
    //strategy.fullstop();
    updatetimer.stop();
    globaltimer.stop();

}

void refresh(){
  screen.drawHome();
  screen.tofDraw(tof.getDistance());
  screen.timerDraw(globaltimer.getRemainingTime());
  screen.teamDraw(team);
  screen.update();
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
  pinMode(PIN::TEAM, INPUT_PULLUP);
  pinMode(PIN::TIR, INPUT_PULLUP);
  Wire.begin(PIN::I2C::SDA, PIN::I2C::SCL); // I2C screen

  // Initialisation du timer
  globaltimer.start();
  updatetimer.start();

  // Initialisation du DFPlayer
  bool STATE = player.setup();

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

  // Musique
  player.Play(STATE, CRAZY_FROG, VOLUME, 0);
  


  //strategy.setup();
}

void loop(){
  
  
  // DABBLE
  //dabble_loop(movement, strategy);

  // SCREEN REFRESH - 1x/sec
  // if(SWITCH){
  //   refresh();
  // }
  
  // TEST MOVEMENT
  // movement.RotationOnCenter(right, 400, 360);
  // movement.run();
  // movement.RotationOnCenter(left, 400, 360);
  // movement.run();

  movement.RotationOnWheel(right, 400, 360);
  movement.run();
  movement.RotationOnWheel(left, 400, 360);
  movement.run();
  


  delay(2000);
    
  

}
