#pragma once

#include <ESP32Servo.h>

#include "utils.h"
#include "QuentbinksBoard.h"

class SERVO
{
private:
    

public:
    bool setup();
    bool moveLServo(int angle);
    bool moveRServo(int angle);
    bool moveAllServo(int angle);    
};