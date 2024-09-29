#ifndef TEAM_H
#define TEAM_H

#include <Arduino.h>
#define BTN 7
#define LAUNCH 6

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

bool launchpull_setup(){
    pinMode(LAUNCH, INPUT_PULLUP);
    if(digitalRead(LAUNCH) == LOW){
        Serial.println("LAUNCH Started");
        return true;
    }
    else{
        Serial.println("LAUNCH Waiting");
        return false;
    }
}


#endif