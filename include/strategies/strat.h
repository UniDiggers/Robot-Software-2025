#pragma once

#include <vector>
#include "Action.h"

using namespace std;

static const int pamiNb = 9;

const int SPEED  = 2700;
const int ACCEL = 1500;

// strat jaune
vector<Action> _rockstar_y = { // pami jaune
    Action(Wait, 6000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 90 /* angle °*/),
    Action(MoveForward, 1180 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 90 /* angle °*/),
    Action(MoveBackward, -400, 250, 250, 250),
    Action(MoveForward, 370 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
};

vector<Action> _pami1_y = { //pami chill 1
    Action(Wait, 4000 /* time ms */),  
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 45 /* angle °*/),
    Action(Wait, 750),
    Action(MoveForward, 480 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL/*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 45 /* angle °*/),
    Action(MoveForward, 800 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
};

vector<Action> _pami2_y = { // pami chill 2
    Action(Wait, 2000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 45 /* angle °*/),
    Action(MoveForward, 400 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 45 /* angle °*/),
    Action(MoveForward, 1050 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
};

vector<Action> _pami3_y = { // pami NRV 3
    Action(MoveForward, 200 /* distance mm*/, SPEED + 200 /*speed*/, SPEED + 200 /*MAX speed*/, ACCEL + 300 /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 45 /* angle °*/),
    Action(MoveForward, 300 /* distance mm*/, SPEED + 200 /*speed*/, SPEED + 200 /*MAX speed*/, ACCEL + 300/*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 45 /* angle °*/),
    Action(MoveForward, 1500 /* distance mm*/, 2 * SPEED /*speed*/, 2 * SPEED /*MAX speed*/, 1.5 * ACCEL/*Accel*/),
};



// strat bleu
vector<Action> _rockstar_b = { // pami jaune
    Action(Wait, 6000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 90 /* angle °*/),
    Action(MoveForward, 1180 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 90 /* angle °*/),
    Action(MoveBackward, -400, 250, 250, 250),
    Action(MoveForward, 370 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
};

vector<Action> _pami1_b = { //pami chill 1
    Action(Wait, 4000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 45 /* angle °*/),
    Action(Wait, 750),
    Action(MoveForward, 480 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL/*Accel*/),
    Action(RotationOnCenterRight, SPEED, 45 /* angle °*/),
    Action(MoveForward, 800 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
};

vector<Action> _pami2_b = { // pami chill 2
    Action(Wait, 2000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 45 /* angle °*/),
    Action(MoveForward, 400 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 45 /* angle °*/),
    Action(MoveForward, 1050 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
};

vector<Action> _pami3_b = { // pami NRV 3
    Action(MoveForward, 200 /* distance mm*/, SPEED + 200 /*speed*/, SPEED + 200 /*MAX speed*/, ACCEL + 300 /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 45 /* angle °*/),
    Action(MoveForward, 300 /* distance mm*/, SPEED + 200 /*speed*/, SPEED + 200 /*MAX speed*/, ACCEL + 300 /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 45 /* angle °*/),
    Action(MoveForward, 1500 /* distance mm*/, 2 * SPEED /*speed*/, 2 * SPEED /*MAX speed*/, 1.5 * ACCEL/*Accel*/),
};


vector<Action> _temp_ = {
};

vector<Action> actions[pamiNb] = {_rockstar_y, _rockstar_b, 
                                    _pami1_y, _pami1_b ,
                                    _pami2_y, _pami2_b,
                                    _pami3_y, _pami3_b,
                                    _temp_};