#include "servo.h"

// Servo object
Servo lservo;
Servo rservo;

bool SERVO::setup(){

    //Servo
    pinMode(PIN::LSERVO, OUTPUT);
    pinMode(PIN::RSERVO, OUTPUT);

    lservo.setPeriodHertz(50); // Standard 50hz servo
    rservo.setPeriodHertz(50); // Standard 50hz servo

    lservo.attach(PIN::LSERVO, 500, 2400); // Attach left servo on pin 35 with min and max pulse widths
    rservo.attach(PIN::RSERVO, 500, 2400); // Attach right servo on pin 36 with min and max pulse widths

    return true;
}

bool SERVO::moveLServo(int angle){
    lservo.write(angle);
    return true;
}

bool SERVO::moveRServo(int angle){
    rservo.write(angle);
    return true;
}

bool SERVO::moveAllServo(int angle){
    lservo.write(angle);
    rservo.write(180 - angle);
    return true;
}