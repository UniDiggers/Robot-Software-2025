#pragma once

#include <VL53L0X.h>
#include <Wire.h>

#include "PAMIBOARD.h"
#include "utils.h"

const uint8_t sensorCount = 2; 

class TOF
{
private:
    int timeout = 500;
    uint8_t preRange = 18, finalRange = 14;
    int highTimingBudget = 200000, lowTimingBudget = 20000; // ms
    float mcps = 0.1;
    VL53L0X sensors[sensorCount];

public:
    uint8_t reset();
    bool setup(uint8_t mode);
    uint16_t getDistance(uint8_t sensorIndex);
};