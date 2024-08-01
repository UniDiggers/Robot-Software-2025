#ifndef TEAM_H
#define TEAM_H

#include <Arduino.h>
#define BTN 0

bool team_setup(){
    pinMode(BTN, INPUT_PULLUP);
    if(digitalRead(BTN) == LOW){
        Serial.println("BLUE TEAM");
        return true;
    }
    else{
        Serial.println("YELLOW TEAM");
        return false;
    }
}


#endif