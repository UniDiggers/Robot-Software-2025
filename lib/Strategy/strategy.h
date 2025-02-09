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
    const char* PAMI;
    uint64_t mac_adress;
    Movement movement;

public:
    Strategy();
    void get_UID();
    void selectTeam();
    void PAMI_reference();
    void init();
    void game();
    void fullstop();
};