#include "strategy.h"

#include "strategies/strat.h"

#include "servo.h"
#include "screen.h"

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
}

void Strategy::init(){
    //init placement
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
            movement.moveBy(left, action.param1, -action.param2, -action.param3, action.param4); 
            movement.moveBy(right, action.param1, -action.param2, -action.param3, action.param4);
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
            servo.moveServo(left, 0); // Assuming servo index 0 is for the arm
            servo.moveServo(right, 0); // Assuming servo index 1 is for the other arm
            delay(1500);
            servo.moveServo(left, 90); // Assuming servo index 0 is for the arm
            servo.moveServo(right, 90); // Assuming servo index 1 is for the other arm
            delay(1500);
            }
        default:
            ERROR("wrong action type");
            break;
    }


}

void Strategy::game()
{
    for (const auto& action : actions[currentPAMI])
    {
        execAction(action);
    }

    fullstop();
}



void Strategy::fullstop()
{
    movement.fullstop();
    for(;;);
}