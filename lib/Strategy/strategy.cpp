#include "strategy.h"

#include "strategies/strat.h"

#include "servo.h"
#include "screen.h"

Strategy::Strategy() {}

pamiID Strategy::selectCurrentPAMI(){    
    switch(mac_adress)
    {
        
        case 22510497189568: // Real adress Rockstar
            return rockstar;
        case 185199596949184: // PAMI1 BLEU
            return pami1;
        case 224782015549120: // PAMI2 BLEU
            return pami2;
        case 202791782993600: // PAMI3 NRV
            return pami3;
        case 193885460049968: // Fake adress PAMI4
            return tempo;
        default:
            Serial.println("PAMI UID Unknown.");
            return tempo; // Shouldn't happen but just in case
    }
}

int Strategy::setup(){

    // Select current PAMI
    mac_adress = ESP.getEfuseMac();
    Serial.println("PAMI UID : " + String(mac_adress));
    currentPAMI = selectCurrentPAMI();
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