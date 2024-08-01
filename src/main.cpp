#include <Wire.h>
#include <Arduino.h>

#include "tof.h"
#include "test_i2c.h"
#include "screen.h"
#include "team.h"

#define DEBUG true

void setup() {

  Serial.begin(115200);
  Serial.println("\n\n\nStart Program :");
  Wire.begin(1,2);
  
  // Initialisation wich check all the components
  if(!i2c_setup()){
    Serial.println("I2C not working");
    EXIT_FAILURE;
  }
  if(DEBUG){
    Serial.println("I2C working");
  }
  if(!tof_setup()){
    Serial.println("ToF not working");
    EXIT_FAILURE;
  }
  if(DEBUG){
    Serial.println("ToF working");
  }
  if(!screen_setup()){
    Serial.println("Screen not working");
    EXIT_FAILURE;
  }
  if(DEBUG){
    Serial.println("Screen working");
  }

  //Choose Team
  team_setup();

  //Print Home Page
  home_screen();
  delay(2000);
  
}

void loop() {
  //Print distance on screen
  tof_screen();
}


