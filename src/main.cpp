#include <Wire.h>
#include <Arduino.h>

#include "tof.h"
#include "test_i2c.h"
#include "screen.h"
#include "team.h"
#include "stepper.h"
//#include "dabble.h"
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


  //Config NEMA17
  nema_setup(stepper1, 20000, 22000, 5000);
  nema_setup(stepper2, 20000, 22000, 5000);

  //Dabble
  //dabble_setup();

  //BLE
  setup_BLE();

  Serial.println("All setup tested.");
}

void loop() {
  // nema_position(stepper1, 20000);
  // nema_position(stepper2, 20000);
  // nema_start(stepper1, stepper2);
  // Serial.println("Go to 10000");
  // nema_position(stepper1, 0);
  // nema_position(stepper2, 0);
  // nema_start(stepper1, stepper2);
  // Serial.println("Go to 0");
  //dabble_loop();
  delay(1000);

}


