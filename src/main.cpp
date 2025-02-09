#include <Wire.h>
#include <Arduino.h>

#include "buzzer.h"
#include "Movement.h"
#include "screen.h"
#include "tof.h"
#include "timer.h"
#include "strategy.h"

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

//Dablle begin
int speed_dabble  = 500;
int accel_dabble = speed_dabble/2;
int offset_dabble = 500;

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

  Dabble.begin("ESP32 PAMI");
  
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


  //Increase Accel
  if(GamePad.isTrianglePressed()){
    accel_dabble += offset_dabble;
    Serial.println("Accel increased to " + String(accel_dabble));
    delay(500);
  }
  //Decrease Accel
  if(GamePad.isCrossPressed()){
    accel_dabble -= offset_dabble;
    Serial.println("Accel decreased to " + String(accel_dabble));
    delay(500);
  }

  //Decrease Speed
  if(GamePad.isSquarePressed()){
    speed_dabble -= offset_dabble;
    Serial.println("Speed decreased to " + String(speed_dabble));
    delay(500);
  }
  //Increase Speed
  if(GamePad.isCirclePressed()){
    speed_dabble += offset_dabble;
    Serial.println("Speed increased to " + String(speed_dabble));
    delay(500);
  }

  if (GamePad.isUpPressed()){
    movement.SetSpeed(0, speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(1, speed_dabble, speed_dabble, accel_dabble);
    Serial.println("UP");
  }
  if (GamePad.isDownPressed()){
    movement.SetSpeed(0, -speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(1, -speed_dabble, speed_dabble, accel_dabble);
    Serial.println("DOWN");
  }
  if (GamePad.isLeftPressed()){
    movement.SetSpeed(1, speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(0, 0, 0, 0);
    Serial.println("LEFT");
  }
  if (GamePad.isRightPressed()){
    movement.SetSpeed(0, speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(1, 0, 0, 0);
    Serial.println("RIGHT");
  }
    
  

}
