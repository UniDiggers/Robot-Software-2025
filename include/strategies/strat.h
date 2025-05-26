#pragma once

#include <vector>
#include "Action.h"

using namespace std;

static const int pamiNb = 5;

vector<Action> _rockstar = {
    Action(LowerArm),
    
};

vector<Action> _pami1 = {
    Action(LowerArm),
    
};

vector<Action> _pami2 = {
    Action(LowerArm),
};

vector<Action> _pami3 = {
    Action(LowerArm),
};

vector<Action> _the_original = {
    Action(LowerArm),
};

vector<Action> actions[pamiNb] = {_rockstar, _pami1, _pami2, _pami3, _the_original};