#pragma once

enum ActionType
{
    gotoAbsolute,
    gotoRelative,
    rotateAbsolute,
    rotateLeft,
    rotateRight,
    raiseArm,
    lowerArm,
};

class Action
{
public:
    const char* PAMI_type
    ActionType type;
    float param1; 
    float param2;
    
    Action(const char* PAMI_type, ActionType _type, float _param1 = 0, float _param2 = 0)
    {
        PAMI_type = _PAMI_type;
        type = _type;
        param1 = _param1;
        param2 = _param2;
    }
};