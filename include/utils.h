#pragma once

static const int stepperNb = 2;

#define ERROR(reason) Serial.println("[ERROR] " + String(__FILE__) + ":" + String(__LINE__) + ": " + reason)

enum TofMode
{
    longRange, // 0
    longRangeAccuracy,
    longRanceSpeed,
    highSpeed,
    highAccuracy
};