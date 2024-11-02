#ifndef DABBLE_H
#define DABBLE_H

#include <DabbleESP32.h>
#include "stepper.h"

void dabble_setup(){
    Dabble.begin("ESP32 Boosted Car");
}


void dabble_loop(){
    Dabble.processInput();
    if(GamePad.isUpPressed()){
        Serial.println("Up");
        nema_position(stepper1, 20000);
        nema_position(stepper2, 20000);
    }
    if(GamePad.isDownPressed()){
        Serial.println("Down");
        nema_position(stepper1, -20000);
        nema_position(stepper2, -20000);
    }
    if(GamePad.isLeftPressed()){
        Serial.println("Left");
        nema_position(stepper1, 20000);
    }
    if(GamePad.isRightPressed()){
        Serial.println("Right");
        nema_position(stepper2, 20000);
    }
    nema_start(stepper1, stepper2);
}

#endif 