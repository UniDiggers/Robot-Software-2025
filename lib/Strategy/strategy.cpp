#include "strategy.h"

#include "strategies/strat.h"

#include "servo.h"
#include "screen.h"

#define TIME_START 85
#define count 100 // Timer count in seconds
hw_timer_t *Timer1 = NULL;

Strategy::Strategy() {}

pamiID Strategy::selectCurrentPAMI(char team){    
    switch(mac_adress)
    {
        case 22510497189568: // Real adress Rockstar
            if(team == 'y') {
                return rockstar_y;
            } else {
                return rockstar_b;
            }
            return rockstar_y;
        case 106034759749312: // PAMI1 BLEU
            if(team == 'y') {
                return pami1_y;
            } else {
                return pami1_b;
            }
        case 185199596949184: // PAMI2 BLEU
            if(team == 'y') {
                return pami2_y;
            } else {
                return pami2_b;
            }
        case 202791782993600: // PAMI3 NRV
            if(team == 'y') {
                return pami3_y;
            } else {
                return pami3_b;
            }
        // case 224782015549120: // Carte HS
        //     if(team == 'y') {
        //         return temp_y;
        //     } else {
        //         return temp_b;
        //     }
        default:
            Serial.println("PAMI UID Unknown.");
            return temp; // Shouldn't happen but just in case
    }
}

void Strategy::fullstop()
{
    movement.fullstop();
    Serial.println("Full stop called, stopping all actions.");
}

// Static pointer to access instance from static method
static Strategy* instance = nullptr;

// Static callback for timer
static void IRAM_ATTR onTimerStatic() {
    if (instance)
        instance->stopRequested = true; // Juste un flag !
}

int Strategy::setup(char team){
    // Select current PAMI
    mac_adress = ESP.getEfuseMac();
    Serial.println("PAMI UID : " + String(mac_adress));
    currentPAMI = selectCurrentPAMI(team);
    Serial.println("Current PAMI : " + String(currentPAMI));

    // Init servo
    servo.setup();

    Serial.println("Strat initialized.");
    return currentPAMI;
} // Added missing closing bracket

void Strategy::timer(){
    // Save instance pointer for the static callback
    instance = this;
    Timer1 = timerBegin(0, 80, true);
    timerAttachInterrupt(Timer1, &onTimerStatic, true);
    timerAlarmWrite(Timer1, count * 1000000, false);
    timerAlarmEnable(Timer1); 
}
int Strategy::getElapsedTime(){
    // Get the elapsed time since the timer started
    int elapsedTime = timerRead(Timer1) / 1000000; // Convert to seconds
    //Serial.println("Elapsed Time: " + String(elapsedTime) + " seconds");
    return elapsedTime;
}

void Strategy::execAction(Action action)
{
    switch (action.type)
    {
        case MoveForward:
            movement.moveBy(left, action.param1, action.param2, action.param3, action.param4); 
            movement.moveBy(right, action.param1, action.param2, action.param3, action.param4);
            movement.run();
            break;
        case MoveBackward:
            Serial.println("Moving Backward...");
            movement.moveBy(left, action.param1, action.param2, action.param3, action.param4); 
            movement.moveBy(right, action.param1, action.param2, action.param3, action.param4);
            movement.run();
            break;
        case CurveLeft:
            Serial.println("Curving Left...");
            movement.Curve(left, action.param1, action.param2, action.param3); 
            movement.run();
            break;
        case CurveRight:
            Serial.println("Curving Right...");
            movement.Curve(right, action.param1, action.param2, action.param3); 
            movement.run();
            break;
        case RotationOnCenterLeft:  
            movement.RotationOnCenter(left, action.param1, action.param2);
            movement.run();
            break;
        case RotationOnCenterRight:
            movement.RotationOnCenter(right, action.param1, action.param2);
            movement.run();
            break;
        case RotationOnWheelLeft:
            movement.RotationOnWheel(left, action.param1, action.param2);
            movement.run();
            break;
        case RotationOnWheelRight:
            movement.RotationOnWheel(right, action.param1, action.param2);
            movement.run();
            break;
        case RaiseArm:
            Serial.println("Raising Arms...");
            servo.moveServo(left, 90); // Assuming servo index 0 is for the arm
            servo.moveServo(right, 90); // Assuming servo index 1 is for the other arm
            break;
        case LowerArm:
            Serial.println("Lowering Arms...");
            servo.moveServo(left, 0); // Assuming servo index 0 is for the arm
            servo.moveServo(right, 0); // Assuming servo index 1 is for the other arm
            break;
        case Stop:
            Serial.println("Stopping...");
            fullstop();
            break;
        case Wait:
            Serial.println("Waiting...");
            delay(action.param1); // Wait for a specified time
            break;
        case Party:
            while(true){
                servo.moveServo(left, 0); 
                servo.moveServo(right, 0); 
                delay(1500);
                servo.moveServo(left, 90);
                servo.moveServo(right, 90); 
                delay(1500);
            }
        default:
            ERROR("wrong action type");
            break;
    }


}

void Strategy::LoopServos(){
    while(true){
        servo.moveServo(left, 0); 
        servo.moveServo(right, 0); 
        delay(1500);
        servo.moveServo(left, 90); 
        servo.moveServo(right, 90); 
        delay(1500);
    }
}

void Strategy::game()
{
    // Launch timer
    timer();

    int elapsedTime = getElapsedTime();
    
    while(elapsedTime < TIME_START){
        elapsedTime = getElapsedTime();
        Serial.println("Waiting for start... Elapsed time: " + String(elapsedTime) + " seconds");
        if (stopRequested) {
            if (Timer1) timerEnd(Timer1);
            fullstop();
            return;
        }
    }

    if(elapsedTime >= TIME_START){
        for (const auto& action : actions[currentPAMI])
        {
            if (stopRequested) {
                if (Timer1) timerEnd(Timer1);
                fullstop();
                return;
            }
            execAction(action);
        }
    }
    LoopServos(); // Loop servos to keep them active

}



