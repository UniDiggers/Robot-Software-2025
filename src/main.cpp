#include <Wire.h>
#include <Arduino.h>

#include "tof.h"
#include "test_i2c.h"
#include "screen.h"
#include "team.h"
#include "stepper.h"

#define DEBUG 1

#define SDA 1
#define SCL 2

// Création des objets AccelStepper
AccelStepper stepper1(1, STEP1, DIR1);
AccelStepper stepper2(1, STEP2, DIR2);
AccelStepper stepper3(1, STEP3, DIR3);

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
  // home_screen();
  // delay(2000);

  //COnfig NEMA17
  nema_setup(stepper1, 10000, 11000, 5000);
  nema_setup(stepper2, 10000, 11000, 5000);
  nema_setup(stepper3, 10000, 11000, 5000);

  Serial.println("All Setup done");
}

void loop() {
  delay(5000);
  nema_position(stepper1, 10000);
  nema_position(stepper2, 10000);
  delay(2000);
  nema_position(stepper1, 0);
  nema_position(stepper2, 0);
  
}


