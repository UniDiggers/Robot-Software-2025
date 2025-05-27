#pragma once

#include <vector>
#include "Action.h"

using namespace std;

static const int pamiNb = 5;

vector<Action> _rockstar = {
    Action(MoveForward, 500, 500, 500, 500),
    // Action(RotationOnWheelRight, 500, 45),
    Action(RotationOnCenterRight, 500, 45),
    Action(MoveForward, 500, 500, 500, 500),
};

vector<Action> _pami1 = {
    Action(MoveForward, 500, 500, 500, 500),
    
};

vector<Action> _pami2 = {
    Action(MoveForward, 500, 500, 500, 500),
};

vector<Action> _pami3 = {
    Action(MoveForward, 500, 500, 500, 500),
};

vector<Action> _the_original = {
    Action(MoveForward, 500, 500, 500, 500),
};

vector<Action> actions[pamiNb] = {_rockstar, _pami1, _pami2, _pami3, _the_original};