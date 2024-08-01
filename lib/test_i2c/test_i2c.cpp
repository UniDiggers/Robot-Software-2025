#include "test_i2c.h"

bool i2c() {
    Serial.printf("%s", debug ? "\n\nI2C Scanner Start" : "");

    byte error, address;
    int nDevices = 0;

    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (!error) {
            if (debug) {
                Serial.print("I2C device found at address 0x");
                if (address < 16)
                    Serial.print("0");
                Serial.println(address, HEX);
            }

            nDevices++;
        }
        else if (error == 4 && debug) {
            Serial.print("Unknow error at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.println(address, HEX);
        }
    }

    if (!nDevices && debug)
        Serial.println("No I2C devices found\n");
    else if (debug)
        Serial.println("I2C Scanner End\n");

    return nDevices > 0;
}