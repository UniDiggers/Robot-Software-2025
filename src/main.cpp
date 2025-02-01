#include <Wire.h>
#include <Arduino.h>

#include "buzzer.h"
#include "Movement.h"
#include "screen.h"
#include "tof.h"

#include "BLE.h"
#include "wallpaper.h"

#include "QuentbinksBoard.h"
#include "utils.h"

#define DEBUG 1

Screen screen;
Buzzer buzzer1;
Movement movement;
TOF tof;
Timer timer;

char team;

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

  timer.start();
  
  // Initialisation des composants
  if (!screen.setup())
    Serial.println("Screen setup failed");
  
  if (!tof.setup(highAccuracy))
    Serial.println("TOF setup failed");

  // Initialisation de l'équipe
  if (digitalRead(PIN::TEAM) == LOW)
    team = 'b';
  else
    team = 'y';

  // BLE
  setup_BLE();
  Serial.println("BLE Activated.");
  //buzzer1.ringtoneBLE();

  Serial.println("All setup tested.");
  screen.drawHome();
}

void loop()
{
  // Display TOF
  screen.tofDraw(tof.getDistance());
  screen.timerDraw(timer.getRemainingTime());
  screen.update();
}
