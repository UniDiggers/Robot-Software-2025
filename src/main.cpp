#include <Wire.h>
#include <Arduino.h>



#include "tof.h"
#include "test_i2c.h"
#include "screen.h"
#include "team.h"
#include "stepper.h"
#include "BLE.h"

#define DEBUG 1

#define SDA 1
#define SCL 2

void setup(){
  
  Serial.begin(115200);
  delay(500); //Ne pas retirer 
  Serial.println("\nStart Program :");
  Wire.begin(SDA,SCL);
  delay(500); //Ne pas retirer 
  
  // Initialisation wich check all the components
  if(!i2c_setup()){
    Serial.println("I2C not working");
  }
  else{
    Serial.println("I2C working");
  }
  if(!tof_setup()){
    Serial.println("ToF not working");
  }
  else{
    Serial.println("ToF working");
  }

  if(!screen_setup()){
    Serial.println("Screen not working");
  }
  else{
    Serial.println("Screen working\n");
  }

  //Choose Team
  team_setup();

  //BLE
  setup_BLE();
  Serial.println("BLE Activated.");
  Serial.println("All setup tested.");
}



void loop() {
  if(parameter.reception){
    Serial.println("Start Motors");
    nema_setup(stepper1, parameter.vitesse, parameter.vitesse + 2000, parameter.acceleration);
    nema_setup(stepper3, parameter.vitesse, parameter.vitesse + 2000, parameter.acceleration);
    nema_position(stepper1, parameter.position1);
    nema_position(stepper3, parameter.position2);
    nema_start(stepper1, stepper3);
    parameter.reception = false;
  }
}


