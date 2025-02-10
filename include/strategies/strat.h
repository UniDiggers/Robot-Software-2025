#pragma once

#include <vector>
#include "Action.h"

using namespace std;

static const int pamiNb = 5;

vector<Action> _rockstar = {
    Action(gotoAbsolute, 400, 500),
    Action(gotoRelative, 150, 200),
    Action(rotateAbsolute, 150),
    Action(rotateLeft, 150),
    Action(rotateRight, 12),
    Action(raiseArm),
    Action(lowerArm),
};

vector<Action> _pami1 = {
    Action(gotoAbsolute, 400, 500),
    Action(gotoRelative, 150, 200),
    Action(rotateAbsolute, 150),
    Action(rotateLeft, 150),
    Action(rotateRight, 12),
    Action(raiseArm),
    Action(lowerArm),
};

vector<Action> _pami2 = {
    Action(gotoAbsolute, 400, 500),
    Action(gotoRelative, 150, 200),
    Action(rotateAbsolute, 150),
    Action(rotateLeft, 150),
    Action(rotateRight, 12),
    Action(raiseArm),
    Action(lowerArm),
};

vector<Action> _pami3 = {
    Action(gotoAbsolute, 400, 500),
    Action(gotoRelative, 150, 200),
    Action(rotateAbsolute, 150),
    Action(rotateLeft, 150),
    Action(rotateRight, 12),
    Action(raiseArm),
    Action(lowerArm),
};

vector<Action> _the_original = {
    Action(gotoAbsolute, 400, 500),
    Action(gotoRelative, 150, 200),
    Action(rotateAbsolute, 150),
    Action(rotateLeft, 150),
    Action(rotateRight, 12),
    Action(raiseArm),
    Action(lowerArm),
};

vector<Action> actions[pamiNb] = {_rockstar, _pami1, _pami2, _pami3, _the_original};