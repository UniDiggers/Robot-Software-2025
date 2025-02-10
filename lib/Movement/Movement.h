#pragma once

#include <AccelStepper.h>

#include "QuentbinksBoard.h"
#include "utils.h"

using namespace PIN::Steppers;

static const int defaultSpeed = 100;
static const int defaultAccel = 50;

class Movement
{
private:
    int wheelDiameter = 60; // mm
    int baseSteps = 200;
    float wheelPerimeter = 2 * PI * (wheelDiameter/2);
    float mmPerStep = wheelPerimeter / baseSteps;
    AccelStepper stepper[2] = {
        AccelStepper(1, STEP1, DIR1),
        AccelStepper(1, STEP3, DIR3)
    };

public:
    Movement();
    void setParameters(int stepperIndex, int speed, int maxSpeed, int accel);
    void moveBy(int stepperIndex, int target);
    void run();
    void SetSpeed(int stepperIndex, int speed, int maxSpeed, int accel);
    void fullstop();
};