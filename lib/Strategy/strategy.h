#pragma once

#include <Arduino.h>

#include "QuentbinksBoard.h"
#include "utils.h"

#include "Action.h"

#include "Movement.h"
#include "Timer.h"

static const int DEFAULT_GAME_DURATION = 100;

class Strategy
{
private:
    char team;
    uint64_t mac_adress;
    pamiID currentPAMI;
    pamiID selectCurrentPAMI();
    Movement movement;
    void execAction(Action action);


public:
    Strategy();
    void selectTeam();
    void init();
    void setup();
    void game();
    void fullstop();
};