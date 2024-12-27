#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_STATE false

#define BUZZER 5


void buzzer_setup(){
    pinMode(BUZZER, OUTPUT);

}


void BLE_ringtone(){
    for(int i = 0; i < 3; i++){
        digitalWrite(BUZZER, HIGH);
        delay(100);
        digitalWrite(BUZZER, LOW);
        delay(100);
    }
}

void BLE_notification(){
    for(int i = 0; i < 2; i++){
        digitalWrite(BUZZER, HIGH);
        delay(50);
        digitalWrite(BUZZER, LOW);
        delay(50);
    }
}

#endif

