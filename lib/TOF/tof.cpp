#include "tof.h"

bool TOF::setup(int mode)
{
    tof.setTimeout(timeout);

    if (!tof.init())
        return false;

    switch(mode)
    {
        case longRange:
            tof.setSignalRateLimit(mcps);
            tof.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, preRange);
            tof.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, finalRange);
            break;
        case longRangeAccuracy:
            tof.setSignalRateLimit(mcps);
            tof.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, preRange);
            tof.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, finalRange);
            tof.setMeasurementTimingBudget(highTimingBudget);
            break;
        case longRanceSpeed:
            tof.setSignalRateLimit(mcps);
            tof.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, preRange);
            tof.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, finalRange);
            tof.setMeasurementTimingBudget(lowTimingBudget);
            break;
        case highSpeed:
            tof.setMeasurementTimingBudget(lowTimingBudget);
            break;
        case highAccuracy:
            tof.setMeasurementTimingBudget(highTimingBudget);
            break;
        default:
            return false;
    }

    return true;
}

int TOF::getDistance()
{
    int distance = tof.readRangeSingleMillimeters();

    if (tof.timeoutOccurred())
        return -1;

    return distance;
}