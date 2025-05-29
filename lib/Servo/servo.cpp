#include "servo.h"

bool SERVO::setup(){

    for(uint8_t i = 0; i < 5; i++){
        pinMode(SERVOS::SERVOS[i], OUTPUT);
        tab_servo[i].setPeriodHertz(50); // Standard 50hz servo
        tab_servo[i].attach(SERVOS::SERVOS[i], 500, 2400); // Attach servo on pin with min and max pulse widths
        tab_servo[i].write(0); // Initialize servo to 0 degrees
    }
    return true;
}

bool SERVO::moveServo(uint8_t index, uint8_t angle){
    tab_servo[index].write(angle);
    return true;
}

