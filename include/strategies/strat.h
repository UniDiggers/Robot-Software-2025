#pragma once

#include <vector>
#include "Action.h"

using namespace std;

vector<Action> actions = {

    // PAMI 1
    Action("PAMI 1",gotoAbsolute, 400, 500),
    Action("PAMI 1",gotoRelative, 150, 200),
    Action("PAMI 1",rotateAbsolute, 150),
    Action("PAMI 1",rotateLeft, 150),
    Action("PAMI 1",rotateRight, 12),
    Action("PAMI 1",raiseArm),
    Action("PAMI 1",lowerArm),

    // PAMI 2
    Action("PAMI 2",gotoAbsolute, 400, 500),
    Action("PAMI 2",gotoRelative, 150, 200),
    Action("PAMI 2",rotateAbsolute, 150),
    Action("PAMI 2",rotateLeft, 150),
    Action("PAMI 2",rotateRight, 12),
    Action("PAMI 2",raiseArm),
    Action("PAMI 2",lowerArm),

    // ...
};