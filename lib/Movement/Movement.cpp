#include "Movement.h"


Movement::Movement()
{
    pinMode(Steppers::EN, OUTPUT);
    digitalWrite(Steppers::EN, HIGH); // Disable the stepper drivers
    for (int i = 0; i < stepperNb; i++)
    {
        stepper[i].setSpeed(defaultSpeed);
        stepper[i].setMaxSpeed(defaultSpeed);
        stepper[i].setAcceleration(defaultAccel);
    }
    stepper[right].setPinsInverted(true);
}

void Movement::setParameters(int stepperIndex, int speed, int maxSpeed, int accel)
{
    stepper[stepperIndex].setSpeed(speed);
    stepper[stepperIndex].setMaxSpeed(maxSpeed);
    stepper[stepperIndex].setAcceleration(accel);
}

void Movement::moveBy(int index, int target, int speed, int maxSpeed, int accel)
{
    setParameters(index, speed, maxSpeed, accel);
    stepper[index].setSpeed(speed);
    stepper[index].setCurrentPosition(0);
    stepper[index].move(target/mmPerStep);
    Serial.print("TARGET : " + String(target) + " mm, STEPS : " + String(target/mmPerStep) + " STEPPER INDEX : " + String(index) + "\n");
    Serial.println("SPEED : " + String(speed) + " MAXSPEED : " + String(maxSpeed) + " ACCEL : " + String(accel));
}


void Movement::run()
{
    digitalWrite(Steppers::EN, LOW); // Enable the stepper drivers
    unsigned long lastObstacleCheck = 0;
    const unsigned long obstacleCheckInterval = 35; // ms, à ajuster selon besoin

    do {
        stepper[left].run();
        stepper[right].run();

        unsigned long now = millis();
        if (now - lastObstacleCheck >= obstacleCheckInterval) {
            lastObstacleCheck = now;
            while(tof.getDistance(0) < OBSTACLE_DISTANCE && tof.getDistance(1) < OBSTACLE_DISTANCE) {
                Serial.println("Obstacle detected, stopping movement.");
                // Optionnel: arrêter les steppers ici si nécessaire
            }
        }
    } while (stepper[left].isRunning() || stepper[right].isRunning());
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