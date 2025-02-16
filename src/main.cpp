#include <Wire.h>
#include <Arduino.h>

#include "buzzer.h"
#include "Movement.h"
#include "screen.h"
#include "tof.h"
#include "timer.h"
#include "strategy.h"

#include "wallpaper.h"
#include "dabble.h"

#include "QuentbinksBoard.h"
#include "utils.h"

#define DEBUG 1

void fullstop();

Screen screen;
Buzzer buzzer1;
Movement movement;
Strategy strategy;
TOF tof;
Timer timer = Timer(100, &fullstop, false);



char team;

void fullstop()
{
    strategy.fullstop();
}


void setup()
{

  // Initialisation UART
  Serial.begin(115200);
  delay(500);

  // Initialisation I2C
  pinMode(PIN::TEAM, INPUT_PULLUP);
  pinMode(PIN::TIR, INPUT_PULLUP);
  Wire.begin(PIN::I2C::SDA, PIN::I2C::SCL); // I2C screen
  delay(500);

  // Initialisation des composants
  if (!screen.setup())
    Serial.println("Screen setup failed");
  
  if (!tof.setup(highAccuracy))
    Serial.println("TOF setup failed");



  //screen.drawHome();


  setup_dabble();
  strategy.setup();
  
}

void loop()
{
  // Display TOF
  //screen.tofDraw(tof.getDistance());
  //screen.timerDraw(timer.getRemainingTime());
  //screen.update();
  //Serial.println(timer.getRemainingTime());
  

  dabble_loop(movement, strategy);
    
  

}
