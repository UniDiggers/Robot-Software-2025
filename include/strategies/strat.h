#pragma once

#include <vector>
#include "Action.h"

using namespace std;

static const int pamiNb = 9;

const int SPEED  = 2700;
const int ACCEL = 1500;
const int TEMPO = 84.5 * 1000;

// strat jaune
vector<Action> _rockstar_y = { // pami jaune
    Action(Wait, TEMPO /* time ms */), 
    Action(Wait, 5500 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 88 /* angle °*/),
    Action(MoveForward, 1180 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 90 /* angle °*/),
    Action(MoveForward, 327 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};

vector<Action> _pami1_y = { //pami chill 1
    Action(Wait, TEMPO /* time ms */), 
    Action(Wait, 3000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 50 /* angle °*/),
    Action(MoveForward, 480 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 40 /* angle °*/),
    Action(MoveForward, 900 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};

vector<Action> _pami2_y = { // pami chill 2
    Action(Wait, TEMPO /* time ms */), 
    Action(Wait, 1500 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 48 /* angle °*/),
    Action(MoveForward, 574 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 46 /* angle °*/),
    Action(MoveForward, 853 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};

vector<Action> _pami3_y = { // pami NRV 3
    Action(Wait, TEMPO - 1 /* time ms */), 
    Action(RotationOnCenterLeft, SPEED, 70 /* angle °*/),
    Action(MoveForward, 462 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 36 /* angle °*/),
    Action(MoveForward, 1400 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};



// strat bleu
vector<Action> _rockstar_b = { // pami jaune
    Action(Wait, TEMPO /* time ms */), 
    Action(Wait, 5500 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 88 /* angle °*/),
    Action(MoveForward, 1180 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterLeft, SPEED, 90 /* angle °*/),
    Action(MoveForward, 327 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};

vector<Action> _pami1_b = { //pami chill 1
    Action(Wait, TEMPO /* time ms */), 
    Action(Wait, 3000 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 50 /* angle °*/),
    Action(MoveForward, 480 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 40 /* angle °*/),
    Action(MoveForward, 900 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};

vector<Action> _pami2_b = { // pami chill 2
    Action(Wait, TEMPO /* time ms */), 
    Action(Wait, 1500 /* time ms */), 
    Action(MoveForward, 20 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 48 /* angle °*/),
    Action(MoveForward, 574 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 46 /* angle °*/),
    Action(MoveForward, 853 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};

vector<Action> _pami3_b = { // pami NRV 3
    Action(Wait, TEMPO - 1 /* time ms */), 
    Action(RotationOnCenterRight, SPEED, 70 /* angle °*/),
    Action(MoveForward, 462 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(RotationOnCenterRight, SPEED, 36 /* angle °*/),
    Action(MoveForward, 1400 /* distance mm*/, SPEED /*speed*/, SPEED /*MAX speed*/, ACCEL /*Accel*/),
    Action(Party),
};


vector<Action> _temp_ = {
    Action(Party),
};

vector<Action> actions[pamiNb] = {_rockstar_y, _rockstar_b, 
                                    _pami1_y, _pami1_b ,
                                    _pami2_y, _pami2_b,
                                    _pami3_y, _pami3_b,
                                    _temp_};