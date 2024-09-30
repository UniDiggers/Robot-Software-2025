#include <Wire.h>
#include <Arduino.h>

#include "tof.h"
#include "test_i2c.h"
#include "screen.h"
#include "team.h"

#define DEBUG 1

#define SDA 1
#define SCL 2

void setup(){

  Serial.begin(115200);
  delay(500);
  Serial.println("\nStart Program :");
  Wire.begin(SDA,SCL);
  delay(500);
  
  // Initialisation wich check all the components
  if(!i2c_setup()){
    Serial.println("I2C not working");
    //EXIT_FAILURE;
  }
  else{
    Serial.println("I2C working");
  }
  if(!tof_setup()){
    Serial.println("ToF not working");
    //EXIT_FAILURE;
  }
  else{
    Serial.println("ToF working");
  }

  if(!screen_setup()){
    Serial.println("Screen not working");
    //EXIT_FAILURE;
  }
  else{
    Serial.println("Screen working\n");
  }

  //Choose Team
  team_setup();

  //Print Home Page
  home_screen();
  delay(2000);


}

void loop() {
  //Print distance on screen
  //tof_screen()
}


