#include "Movement.h"

Movement::Movement()
{
    for (int i = 0; i < stepperNb; i++)
    {
        stepper[i].setSpeed(defaultSpeed);
        stepper[i].setMaxSpeed(defaultSpeed);
        stepper[i].setAcceleration(defaultAccel);
    }
}

void Movement::setParameters(int stepperIndex, int speed, int maxSpeed, int accel)
{
    stepper[stepperIndex].setSpeed(speed);
    stepper[stepperIndex].setMaxSpeed(maxSpeed);
    stepper[stepperIndex].setAcceleration(accel);
}

void Movement::moveBy(int stepperIndex, int target)
{
    stepper[stepperIndex].move(target/mmPerStep);
    Serial.println(target/mmPerStep);
}

void Movement::run()
{
    for (int i = 0; i < stepperNb; i++)
        stepper[i].run();
}

void Movement::SetSpeed(int stepperIndex, int speed, int maxSpeed, int accel){
    setParameters(stepperIndex, speed, maxSpeed, accel);
    for (int i = 0; i < stepperNb; i++)
        stepper[i].runSpeed();
}