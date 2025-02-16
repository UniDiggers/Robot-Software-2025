#pragma once

#include <Arduino.h>

#include "QuentbinksBoard.h"
#include "utils.h"

#include "Action.h"

#include "Movement.h"
#include "Timer.h"

#include "Servo.h"

static const int DEFAULT_GAME_DURATION = 100;

class Strategy
{
private:
    char team;
    uint64_t mac_adress;
    pamiID currentPAMI;
    pamiID selectCurrentPAMI();
    Movement movement;
    SERVO servo;
    
public:
    Strategy();
    void selectTeam();
    void init();
    void setup();
    void game();
    void fullstop();
    void execAction(Action action);
};