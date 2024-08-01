#include <VL53L0X.h>
#include <Wire.h>

const int PROFILE_DEFAULT = 0;
const int PROFILE_SPEED = 1;

class TOF
{
private:
    VL53L0X sensor;

public:
    TOF(int profile); // 0: PROFILE_DEFAULT, 1: PROFILE_SPEED
    int getDistance();
};

/*
    ### Define five profiles for the sensor ###

    - LONG_RANGE_MODE
        setSignalRateLimit : 0.1
        setVcselPulsePeriod :   VL53L0X::VcselPeriodPreRange, 18
                                VL53L0X::VcselPeriodFinalRange, 14

    - LONG_RANGE_ACCURACY
        setSignalRateLimit : 0.1
        setVcselPulsePeriod :   VL53L0X::VcselPeriodPreRange, 18
                                VL53L0X::VcselPeriodFinalRange, 14
        setMeasurementTimingBudget : 200000

    - LONG_RANGE_SPEED
        setSignalRateLimit : 0.1
        setVcselPulsePeriod :   VL53L0X::VcselPeriodPreRange, 18
                                VL53L0X::VcselPeriodFinalRange, 14
        setMeasurementTimingBudget : 20000

    - HIGH_SPEED
        setMeasurementTimingBudget : 20000

    - HIGH_ACCURACY
        setMeasurementTimingBudget : 200000
*/