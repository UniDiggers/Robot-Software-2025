#include <Wire.h>
#include <Arduino.h>

#include "buzzer.h"
#include "Movement.h"
#include "screen.h"
#include "tof.h"

#include "wallpaper.h"
#include <DabbleESP32.h>

#include "QuentbinksBoard.h"
#include "utils.h"

#define DEBUG 1
#define INCLUDE_GAMEPAD_MODULE

void fullstop();

Screen screen;
Buzzer buzzer1;
Movement movement;
TOF tof;
Timer timer = Timer(100, &fullstop, false);



char team;

void fullstop()
{
  buzzer1.ringtoneBLE();
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

  Dabble.begin("ESP32 PAMI");
  //timer.start();
  
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


  Serial.println("BLE Activated.");
  //buzzer1.ringtoneBLE();

  Serial.println("All setup tested.");
  //screen.drawHome();
}

void loop()
{
  // Display TOF
  //screen.tofDraw(tof.getDistance());
  //screen.timerDraw(timer.getRemainingTime());
  //screen.update();
  //Serial.println(timer.getRemainingTime());

  Dabble.processInput();

  if (GamePad.isUpPressed()){
    movement.SetSpeed(0, 3000, 3000, 2000);
    movement.SetSpeed(1, 3000, 3000, 2000);
    Serial.println("UP");
  }
  if (GamePad.isDownPressed()){
    movement.SetSpeed(0, -3000, 3000, 2000);
    movement.SetSpeed(1, -3000, 3000, 2000);
    Serial.println("DOWN");
  }
  if (GamePad.isLeftPressed()){
    movement.SetSpeed(1, 3000, 3000, 2000);
    movement.SetSpeed(0, -0, 0, 0);
    Serial.println("LEFT");
  }
  if (GamePad.isRightPressed()){
    movement.SetSpeed(0, 3000, 3000, 2000);
    movement.SetSpeed(1, 0, 0, 0);
    Serial.println("RIGHT");
  }
    
  

}
