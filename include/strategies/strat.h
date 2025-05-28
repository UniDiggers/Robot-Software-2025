#pragma once

#include <vector>
#include "Action.h"

using namespace std;

static const int pamiNb = 5;

//strat jaune
vector<Action> _rockstar = { //pami 0
    Action(Wait, 4500 /* time ms */), 
    Action(RotationOnCenterLeft, 500, 90 /* angle °*/),
    Action(MoveForward, 1180 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
    Action(RotationOnCenterRight, 500, 90 /* angle °*/),
    Action(MoveForward, 325 /* distance mm*/, 250 /*speed*/, 250 /*MAX speed*/, 500 /*Accel*/),
};

vector<Action> _pami1 = { //pami chill 1
    Action(Wait, 3000 /* time ms */), 
    Action(RotationOnCenterLeft, 500, 48 /* angle °*/),
    Action(MoveForward, 574 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
    Action(RotationOnCenterLeft, 500, 139 /* angle °*/),
    Action(MoveForward, 553 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
    
};

vector<Action> _pami2 = { // pami chill 2
    Action(Wait, 1500 /* time ms */), 
    Action(RotationOnCenterLeft, 500, 58 /* angle °*/),
    Action(MoveForward, 510 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
    Action(RotationOnCenterLeft, 500, 148 /* angle °*/),
    Action(MoveForward, 979 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
};

vector<Action> _pami3 = { // pami NRV 3
    Action(RotationOnCenterLeft, 500, 70 /* angle °*/),
    Action(MoveForward, 462 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
    Action(RotationOnCenterLeft, 500, 160 /* angle °*/),
    Action(MoveForward, 1300 /* distance mm*/, 500 /*speed*/, 500 /*MAX speed*/, 500 /*Accel*/),
};




vector<Action> _the_original = {
    Action(MoveForward, 500, 500, 500, 500),
};

vector<Action> actions[pamiNb] = {_rockstar, _pami1, _pami2, _pami3, _the_original};