#include "Strategy.h"

#include "strat.h"

Strategy::Strategy() {}

void Strategy::get_UID(){ 
    mac_adress = ESP.getEfuseMac();
}


void Strategy::selectTeam()
{
    if (digitalRead(TEAM_PIN) == LOW)
        team = 'b';
    else if (digitalRead(TEAM_PIN) == HIGH)
        team = 'y';
    else
        ERROR("Unable to select team.");
}

void Strategy::PAMI_reference(){
    
    switch(mac_adress){
        case 193885460049968: // Real MAC adress (uint64_t format)
            PAMI = "The original";
            break;
        case 193885460049969: // Fake
            PAMI = "PAMI1"
            break;
        case 193885460049970: // Fake
            PAMI = "PAMI2"
            break;
        case 193885460049971: // Fake
            PAMI = "PAMI3"
            break;
        case 193885460049972: // Fake
            PAMI = "PAMI4"
            break;
        default:
            ERROR("PAMI UID Unknown.");
            break;
    }
}

void Strategy::init(){
    selectTeam();
    get_UID();
    PAMI_reference();
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
    for (const auto& action : actions)
    {
        if(action.PAMI_type == PAMI){
            execAction(action);
        }
        
    }

    fullstop();
}

void Strategy::fullstop()
{
    movement.fullstop();
}