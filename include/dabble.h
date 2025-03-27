#ifndef DABBLE_H

#include <DabbleESP32.h>
#include <strategy.h>

//Dablle begin
int speed_dabble  = 500;
int accel_dabble = speed_dabble/2;
int offset_dabble = 500;

bool setup_dabble(){
    Dabble.begin("ESP32 PAMI");
    return true;
}

void dabble_loop(Movement &movement, Strategy &strategy){
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
    movement.SetSpeed(left, speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(right, speed_dabble, speed_dabble, accel_dabble);
    Serial.println("UP");
  }
  if (GamePad.isDownPressed()){
    movement.SetSpeed(left, -speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(right, -speed_dabble, speed_dabble, accel_dabble);
    Serial.println("DOWN");
  }
  if (GamePad.isLeftPressed()){
    movement.SetSpeed(right, speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(left, 0, 0, 0);
    Serial.println("LEFT");
  }
  if (GamePad.isRightPressed()){
    movement.SetSpeed(left, speed_dabble, speed_dabble, accel_dabble);
    movement.SetSpeed(right, 0, 0, 0);
    Serial.println("RIGHT");
  }
  if(GamePad.isStartPressed()){
    strategy.execAction(Action(raiseArm));
    delay(100);

  }
  if(GamePad.isSelectPressed()){
    strategy.execAction(Action(lowerArm));
    delay(100);
  }
}

#endif