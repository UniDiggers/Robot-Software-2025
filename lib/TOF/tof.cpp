//https://github.com/pololu/vl53l1x-arduino/blob/master/examples/ContinuousMultipleSensors/ContinuousMultipleSensors.ino
#include "utils.h"
#include "tof.h"

uint8_t TOF::reset(){

    uint8_t check_sensors = 0;

    // Disable/reset all sensors by driving their XSHUT pins low.
    for (uint8_t i = 0; i < sensorCount; i++){
        pinMode(xshutPins[i], OUTPUT);
        digitalWrite(xshutPins[i], LOW);

        // Define ready pins
        pinMode(readyPins[i], INPUT_PULLUP);
    }

    // Enable, initialize, and start each sensor, one by one.
    for (uint8_t i = 0; i < sensorCount; i++){
        // Stop driving this sensor's XSHUT low. This should allow the carrier
        // board to pull it high. (We do NOT want to drive XSHUT high since it is
        // not level shifted.) Then wait a bit for the sensor to start up.
        pinMode(xshutPins[i], INPUT);
        delay(10);
        

        // Set the timeout
        sensors[i].setTimeout(timeout);

        // to detect errors
        if (!sensors[i].init()){
            ERROR("Failed to detect and initialize sensor " + String(i));
        }
        else{
            // Each sensor must have its address changed to a unique value other than
            // the default of 0x29 (except for the last one, which could be left at
            // the default). To make it simple, we'll just count up from 0x2A.
            sensors[i].setAddress(0x2A + i);
            Serial.print("TOF" +String(i) + " adress : " + String(0x2A + i, HEX) + "\n");
            check_sensors++;
        } 
    }

    // Abort if no sensors were found.
    if(check_sensors == 0){
        ERROR("No ToF sensor detected, can't avoid crash");
        EXIT_FAILURE;
    }
    return check_sensors; // Return the number of sensors initialized successfully
}



bool TOF::setup(uint8_t mode){

    if (!reset()){
        return false;
    }

    for(uint8_t i = 0; i < sensorCount; i++){
        switch(mode){
            case longRange:
                sensors[i].setSignalRateLimit(mcps);
                sensors[i].setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, preRange);
                sensors[i].setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, finalRange);
                break;
            case longRangeAccuracy:
                sensors[i].setSignalRateLimit(mcps);
                sensors[i].setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, preRange);
                sensors[i].setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, finalRange);
                sensors[i].setMeasurementTimingBudget(highTimingBudget);
                break;
            case longRanceSpeed:
                sensors[i].setSignalRateLimit(mcps);
                sensors[i].setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, preRange);
                sensors[i].setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, finalRange);
                sensors[i].setMeasurementTimingBudget(lowTimingBudget);
                break;
            case highSpeed:
                sensors[i].setMeasurementTimingBudget(lowTimingBudget);
                break;
            case highAccuracy:
                sensors[i].setMeasurementTimingBudget(highTimingBudget);
                break;
            default:
                return false;
        }
    }
    return true;
}

uint16_t TOF::getDistance(uint8_t sensorIndex)
{
    // Vérifier si l'index du capteur est valide
    if (sensorIndex >= sensorCount) {
        return 0; // Index de capteur invalide
    }
    
    // Vérifier si le capteur est prêt en lisant le READY pin
    if (digitalRead(readyPins[sensorIndex]) == HIGH) {
        // Capteur prêt, lire la distance
        int distance = sensors[sensorIndex].readRangeContinuousMillimeters();
        
        if (sensors[sensorIndex].timeoutOccurred()) {
            return 1; // Timeout détecté
        }
        
        return distance;
    }
    
    return 2; // Capteur pas encore prêt
}