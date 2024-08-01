#ifndef TOF_H
#define TOF_H

#include <VL53L0X.h>
#include <Wire.h>

// ToF Decalaration
VL53L0X sensor;

// 3 Working Styles - Choose only one !
#define LONG_RANGE_MODE false
#define LONG_RANGE_ACCURACY false
#define LONG_RANGE_SPEED false
#define HIGH_SPEED false
#define HIGH_ACCURACY true


/*
- higher speed at the cost of lower accuracy OR
- higher accuracy at the cost of lower speed
*/


bool tof_setup(){
    sensor.setTimeout(500);
    if (!sensor.init()){
        Serial.println("Failed to connect ToF sensor.");
        return false;
    }

    //LONG_RANGE_MODE
    if(LONG_RANGE_MODE == true){
        // lower the return signal rate limit (default is 0.25 MCPS)
        sensor.setSignalRateLimit(0.1);
        // increase laser pulse periods (defaults are 14 and 10 PCLKs)
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
    }
        
    //LONG_RANGE_ACCURACY
    if(LONG_RANGE_ACCURACY == true){
        // lower the return signal rate limit (default is 0.25 MCPS)
        sensor.setSignalRateLimit(0.1);
        // increase laser pulse periods (defaults are 14 and 10 PCLKs)
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
        // increase timing budget to 200 ms
        sensor.setMeasurementTimingBudget(200000);
    }
        

    //LONG_RANGE_SPEED
    if(LONG_RANGE_SPEED == true){
        // set signal rate limit to 0.1 MCPS (million counts per second)
        sensor.setSignalRateLimit(0.1);
        // set Vcsel period to 18 (default is 14)
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
        // reduce timing budget to 20 ms (default is about 33 ms)
        sensor.setMeasurementTimingBudget(20000);
    }
        
    //HIGH_SPEED
    if(HIGH_SPEED == true){
        // reduce timing budget to 20 ms (default is about 33 ms)
        sensor.setMeasurementTimingBudget(20000);
    }

    //HIGH_ACCURACY
    if(HIGH_ACCURACY == true){
        // increase timing budget to 200 ms
        sensor.setMeasurementTimingBudget(200000);
    }
    
    return true;
}

int get_distance(){
    int distance = sensor.readRangeSingleMillimeters();
    if(sensor.timeoutOccurred()){ 
        return -1;
    }
    return distance;
}
  
#endif 