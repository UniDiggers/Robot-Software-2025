#include "DFPlayer.h"
#include <Arduino.h>

// Remplacez `Serial1` par l'UART matériel que vous souhaitez utiliser
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

void DFPlayer::Play(bool state, int track, int volume, int tempo) {
    if (state) {
        player.volume(volume);
        player.play(track);
        Serial.println("FILE : " + String(player.readCurrentFileNumber()));
        delay(tempo);
    }
}

