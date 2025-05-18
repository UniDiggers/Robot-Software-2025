#include "Strategy.h"

#include "strategies/strat.h"

#include "servo.h"
#include "screen.h"

Strategy::Strategy() {}



 void Strategy::selectTeam()
{
    if (digitalRead(STATE::TEAM) == LOW){
        team = 'b';
        Serial.println("Team : Blue");
    }
    else if (digitalRead(STATE::TEAM) == HIGH){
        team = 'y';
        Serial.println("Team : Yellow");
    }
    else{
        Serial.println("Error: team selection failed");
    }
}

pamiID Strategy::selectCurrentPAMI(){    
    switch(mac_adress)
    {
        case 224782015549120: // Real adress Rockstar (PCB V2)
            return rockstar;
        case 193885460049969: // Fake adress PAMI1
            return pami1;
        case 193885460049970: // Fake adress PAMI2
            return pami2;
        case 193885460049971: // Fake adress PAMI3
            return pami3;
        case 193885460049968: // Fake adress PAMI4
            return the_original;
        default:
            Serial.println("PAMI UID Unknown.");
            return the_original; // Shouldn't happen but just in case
    }
}

void Strategy::setup(){

    // Select team
    selectTeam();

    // Select current PAMI
    mac_adress = ESP.getEfuseMac();
    Serial.println("PAMI UID : " + String(mac_adress));
    currentPAMI = selectCurrentPAMI();
    Serial.println("Current PAMI : " + String(currentPAMI));

    // Init servo
    servo.setup();
}

void Strategy::init(){
    //init placement
}

void Strategy::execAction(Action action)
{
    switch (action.type)
    {
        case gotoAbsolute:
            //movement.moveTo...
            break;
        case gotoRelative:
            //movement.moveBy...
            break;
        case rotateAbsolute:
            //movement.rotateTo...
            break;
        case rotateLeft:
            ///movement.rotateLeftBy...
        case rotateRight:
            //movement.rotateRightBy...
            break;
        case raiseArm:
            Serial.println("Raising Arms...");
            break;
        case lowerArm:
            Serial.println("Lowering Arms...");
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
}