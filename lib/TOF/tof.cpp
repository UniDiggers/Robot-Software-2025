#include "tof.h"

TOF::TOF(int profile) // Constructor
{
    sensor.setTimeout(500);
    if (!sensor.init())
    {
        Serial.println("Failed to connect ToF sensor, exiting...");
        exit(EXIT_FAILURE);
    }

    // Options available for every profiles
    sensor.setSignalRateLimit(0.1);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
    
    if (profile == PROFILE_DEFAULT)
        sensor.setMeasurementTimingBudget(20000);
    else if (profile == PROFILE_SPEED)
        sensor.setMeasurementTimingBudget(200000);
    else
    {
        Serial.println("Error : invalid profile, exiting...");
        exit(EXIT_FAILURE);
    }
}

int TOF::getDistance()
{
    int distance = sensor.readRangeSingleMillimeters();
    if (sensor.timeoutOccurred())
        return -1;
    return distance;
}