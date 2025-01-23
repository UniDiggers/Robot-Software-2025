#pragma once

#include <VL53L0X.h>
#include <Wire.h>

#include "utils.h"

class TOF
{
private:
    int timeout = 500;
    int preRange = 18, finalRange = 14;
    int highTimingBudget = 200000, lowTimingBudget = 20000; // ms
    float mcps = 0.1;
    VL53L0X tof;

public:
    bool setup(int mode = longRangeAccuracy);
    int getDistance();
};