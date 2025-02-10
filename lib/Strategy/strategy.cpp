#include "Strategy.h"

#include "strategies/strat.h"

Strategy::Strategy() {}



void Strategy::selectTeam()
{
    if (digitalRead(PIN::TEAM) == LOW)
        team = 'b';
    else if (digitalRead(PIN::TEAM) == HIGH)
        team = 'y';
    else
        Serial.println("Error: team selection failed");
}

pamiID Strategy::selectCurrentPAMI(){    
    switch(mac_adress)
    {
        case 193885460049973: // Fake adress Rockstar
            return rockstar;
        case 193885460049969: // Fake adress PAMI1
            return pami1;
        case 193885460049970: // Fake adress PAMI2
            return pami2;
        case 193885460049971: // Fake adress PAMI3
            return pami3;
        case 193885460049968: // Real adress (uint64_t format) test PAMI (modded)
            return the_original;
        default:
            Serial.println("PAMI UID Unknown.");
            return the_original; // Shouldn't happen but just in case
    }
}

void Strategy::setup(){
    selectTeam();
    mac_adress = ESP.getEfuseMac();
    currentPAMI = selectCurrentPAMI();
}

void Strategy::init(){
    //init
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