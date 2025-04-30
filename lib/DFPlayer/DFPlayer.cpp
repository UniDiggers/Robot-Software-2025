#include "DFPlayer.h"
#include <Arduino.h>

// Attention Serial0 ne doit pas être utilisé pour flasher
#define DFPLAYER_SERIAL Serial0

bool DFPlayer::setup() {
    DFPLAYER_SERIAL.begin(9600);

    bool initialized = player.begin(DFPLAYER_SERIAL);

    if (initialized) {
        Serial.println("DFPlayer Mini initialized");
        return true;
    } else {
        Serial.println("Connecting to DFPlayer Mini failed!");
        return false;
    }
}

// Vient scruter le timer principal pour eviter de jouer tous les sons en même temps
void DFPlayer::Play(bool state, uint8_t track, uint8_t volume) {
    if(state){
        player.volume(volume);
        player.play(track);
        //Serial.println("FILE : " + String(player.readCurrentFileNumber()));
    }
}

