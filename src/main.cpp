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


char team;

void setup()
{
  Serial.begin(115200);
  delay(500);
  pinMode(PIN::TEAM, INPUT_PULLUP);
  pinMode(PIN::TIR, INPUT_PULLUP);
  Wire.begin(PIN::I2C::SDA, PIN::I2C::SCL); // I2C screen
  
  if (!screen.setup())
    Serial.println("Screen setup failed");
  
  if (!tof.setup(highAccuracy))
    Serial.println("TOF setup failed");

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
 
}
