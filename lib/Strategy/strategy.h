#pragma once

#include <Arduino.h>

#include "PAMIBOARD.h"
#include "utils.h"

#include "Action.h"

#include "Movement.h"

#include "servo.h"

static const int DEFAULT_GAME_DURATION = 100;

class Strategy
{
private:
    char team;
    uint64_t mac_adress;
    pamiID currentPAMI;
    pamiID selectCurrentPAMI(char team);
    Movement movement;
    SERVO servo;
    
public:
    volatile bool stopRequested = false;
    Strategy();
    void init();
    int setup(char team);
    void game();
    void fullstop();
    void execAction(Action action);
    void timer();
    void IRAM_ATTR onTimer();
    int getElapsedTime();
    void LoopServos();
};