#pragma once

enum ActionType
{
    MoveForward,
    MoveBackward,
    CurveLeft,
    CurveRight,
    RotationOnCenterLeft,
    RotationOnCenterRight,
    RotationOnWheelLeft,
    RotationOnWheelRight,
    RaiseArm,
    LowerArm,
    Stop,
    Sound,
    Wait,
    Party,
};

enum pamiID {
    rockstar_y,
    rockstar_b,
    pami1_y,
    pami1_b,
    pami2_y,
    pami2_b,
    pami3_y,
    pami3_b,
    temp,
};

class Action
{
public:
    ActionType type;
    float param1; 
    float param2;
    float param3;
    float param4;
    
    Action(ActionType _type, float _param1 = 0, float _param2 = 0, float _param3 = 0, float _param4 = 0)
    {
        type = _type;
        param1 = _param1;
        param2 = _param2;
        param3 = _param3;
        param4 = _param4;
    }
};



