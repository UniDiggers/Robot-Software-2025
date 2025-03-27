#pragma once

#include <AccelStepper.h>

#include "QuentbinksBoard.h"
#include "utils.h"

using namespace PIN::Steppers;

static const int defaultSpeed = 100;
static const int defaultAccel = 50;

enum direction
    {
        left,
        right
    };

class Movement
{
private:
    float wheelDiameter = 64.5; // mm
    int baseSteps = 200;
    int microstepping = 8; // 8th step on TMC2209
    float wheelPerimeter = 2 * PI * (wheelDiameter / 2);
    float mmPerStep = wheelPerimeter / (baseSteps * microstepping); // Adjusted for microstepping
    float width = 92; // largeur entre les 2 roues
    AccelStepper stepper[2] = {
        AccelStepper(1, STEP1, DIR1),
        AccelStepper(1, STEP3, DIR3)
    };

public:
    Movement();
    void setParameters(int stepperIndex, int speed, int maxSpeed, int accel);
    void moveBy(int stepperIndex, int target, int speed, int maxSpeed, int accel);
    void run();
    void SetSpeed(int stepperIndex, int speed, int maxSpeed, int accel);
    void fullstop();
    void Curve(direction way, int speed, float alpha, float radius);
    void RotationOnWheel(direction way, int speed, float alpha);
    void RotationOnCenter(direction way, int speed, float alpha);

    // New method to convert distance in mm to steps
    int convertDistanceToSteps(float distanceInMm)
    {
        return static_cast<int>(distanceInMm / mmPerStep);
    }
};;