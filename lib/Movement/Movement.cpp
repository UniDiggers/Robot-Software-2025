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

void Movement::moveBy(int stepperIndex, int target, int speed, int maxSpeed, int accel)
{
    setParameters(stepperIndex, speed, maxSpeed, accel);
    stepper[stepperIndex].move(target/mmPerStep);
    stepper[stepperIndex].setCurrentPosition(0);
    Serial.println("mm :" + String(target) + "\nsteps : " + String(target/mmPerStep));
}


void Movement::run()
{
    Serial.println("Start running");
    do{
        Serial.println("Running");
        stepper[left].run();
        stepper[right].run();
        Serial.println("stepper1 : " + String(stepper[left].currentPosition()) + " stepper2 : " + String(stepper[right].currentPosition()));
        Serial.println("stepper1 : " + String(stepper[left].distanceToGo()) + " stepper2 : " + String(stepper[right].distanceToGo()));
    } while (stepper[left].run() || stepper[right].run());
    Serial.println("End running");
}

void Movement::SetSpeed(int stepperIndex, int speed, int maxSpeed, int accel){
    setParameters(stepperIndex, speed, maxSpeed, accel);
    for (int i = 0; i < stepperNb; i++)
        stepper[i].runSpeed();
}

void Movement::fullstop()
{
    for (int i = 0; i < stepperNb; i++)
        stepper[i].stop();

    // add moove function 
}


void Movement::Curve(direction way, int speed, float alpha , float radius){
    if(!way){ //left
        float distance_left = (alpha/180) * PI * (radius + width/2);
        float distance_right = (alpha/180) * PI * (radius - width/2);
        float speed_correction = distance_right * speed / distance_left; // right speed correction
        moveBy(left, distance_left, speed, speed, speed);
        moveBy(right, distance_right, speed_correction,speed_correction, speed);
    }
    if(way){ //right
        float distance_left = (alpha/180) * PI * (radius - width/2);
        float distance_right = (alpha/180) * PI * (radius + width/2);
        float speed_correction = distance_left * speed / distance_right; // left speed correction 
        moveBy(left, distance_left, speed_correction,speed_correction, speed);
        moveBy(right, distance_right, speed, speed, speed);
    }
    else{
        ERROR("No direction given : " + way);
    }
}

void Movement::RotationOnWheel(direction way, int speed, float alpha){
    if(way == 0){ //left
        float distance_right = (alpha/180) * PI * width;
        moveBy(right, distance_right, speed, speed, speed);

    }
    else if(way == 1){ //right
        float distance_left = (alpha/180) * PI * width;
        moveBy(left, distance_left, speed, speed, speed);
        
    }
    else{
        ERROR("No direction given : " + way);
    }
}

void Movement::RotationOnCenter(direction way, int speed, float alpha){
    if(!way){ //left
        float distance_right = (alpha/180) * PI * width/2;
        float distance_left = -distance_right;
        moveBy(left, distance_left, speed, speed, speed);
        moveBy(right, distance_right, speed, speed, speed);
    }
    else if(way){ //right
        float distance_left = (alpha/180) * PI * width/2;
        float distance_right = -distance_left;
        moveBy(left, distance_left, speed, speed, speed);
        moveBy(right, distance_right, speed, speed, speed);
    }
    else{
        ERROR("No direction given : " + way);
    }
}