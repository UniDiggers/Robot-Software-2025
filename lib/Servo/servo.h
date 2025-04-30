#pragma once

#include <ESP32Servo.h>

#include "utils.h"
#include "PAMIBOARD.h"



class SERVO
{
private:
    Servo tab_servo[5];

public:
    bool setup();
    bool moveServo(uint8_t index, uint8_t angle);    
};