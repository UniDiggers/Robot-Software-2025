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
#include "remote.h"

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
  screen.drawHome();
  screen.tofDraw(tof.getDistance(0));
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

  // RemoteXY
  RemoteXY_Init(); // Initialize RemoteXY library

  // Initialisation I2C
  Wire.begin(I2C::SDA, I2C::SCL); // I2C screen
  Wire.setClock(400000); // Set I2C clock to 400kHz

  pinMode(STATE::TEAM, INPUT_PULLUP);
  pinMode(STATE::TIR, INPUT_PULLUP);

  // Initialisation du timer
  globaltimer.start();
  updatetimer.start();

  // Initialisation du DFPlayer
  bool STATE = player.setup();
  STATE = false;

  // Initialisation de l'écran
  if (!screen.setup()){
    Serial.println("Screen setup failed");
    player.Play(STATE, SCREEN_NOK, VOLUME);
  }

  // Initialisation du capteur ToF
  if (!tof.setup(highSpeed)){
    Serial.println("TOF setup failed");
    player.Play(STATE, TOF_NOK, VOLUME);
  }
  else
    player.Play(STATE, TOF_OK, VOLUME);

  // Initialisation de l'équipe
  if (digitalRead(STATE::TEAM) == LOW){
      team = 'b';
      RemoteXY.strings_team = 1;
      player.Play(STATE, TEAM_BLUE, VOLUME);
  }
  else if (digitalRead(STATE::TEAM) == HIGH){
      team = 'y';
      player.Play(STATE, TEAM_YELLOW, VOLUME);
      RemoteXY.strings_team = 0;
  }
  else
      Serial.println("Error: team selection failed");

  // Musique
  player.Play(STATE, CRAZY_FROG, VOLUME);
  
  servo.setup(); // Setup servos  

  //strategy.setup();
}

void loop(){
  //SCREEN REFRESH - 1x/sec
  // if(SWITCH){
  //   refresh();
  // }

  delay(1);
}
