#pragma once

#include <Arduino.h>

#include "PAMIBOARD.h"
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
    void init();
    uint64_t setup();
    void game();
    void fullstop();
    void execAction(Action action);
};