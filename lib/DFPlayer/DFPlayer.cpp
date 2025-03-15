#include "DFPlayer.h"

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

bool DFPlayer::setup() {
    softwareSerial.begin(9600);
    player.begin(softwareSerial);

    if (player.begin(softwareSerial)){
        Serial.println("DFPlayer Mini initialized");
        return true;
    }
    else{
        Serial.println("Connecting to DFPlayer Mini failed!");
        return false;
    }
    
}

void DFPlayer::Play(bool state, int track, int volume, int tempo) {
    if(state){
        player.volume(volume);
        player.play(track);
        delay(tempo);
    }
}

