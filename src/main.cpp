#include <Wire.h>
#include <Arduino.h>

#include "tof.h"
#include "test_i2c.h"
#include "screen.h"

#define DEBUG true

TOF /* extern */ sensor(0); // New TOF object with default profile
Screen screen; // New Screen object

void setup()
{
  Serial.begin(115200);
  Serial.println("Start Program :");
  Wire.begin(1,2);
  
  // Initialization which check all the components
  if(!i2c())
  {
    Serial.println("I2C not detected, exiting...");
    exit(EXIT_FAILURE);
  }

  if(DEBUG)
  {
    Serial.println("I2C working");
    Serial.println("ToF working");
    Serial.println("Screen working");
  }

  // Print Home Page
  screen.drawHome();
  delay(2000);
}

void loop() {
  screen.drawDistance(sensor.getDistance());
  Serial.println(sensor.getDistance());
}


