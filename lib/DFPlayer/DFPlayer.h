#pragma once

#include <Arduino.h>
#include "utils.h"

#include "DFRobotDFPlayerMini.h"

static const uint8_t PIN_MP3_TX = 36; 
static const uint8_t PIN_MP3_RX = 37; 

#define BUSY 35
#define VOLUME 30

#define SCREEN_OK 1
#define SCREEN_NOK 2
#define TOF_OK 3
#define TOF_NOK 4
#define TEAM_YELLOW 5
#define TEAM_BLUE 6
#define BLUETOOTH_OK 7
#define BLUETOOTH_NOK 8
#define MICKEY1 9
#define MICKEY2 10
#define CRAZY_FROG 11


class DFPlayer{
    private:
        DFRobotDFPlayerMini player;
    public:
        bool setup();
        void Play(bool state, int track, int volume, int tempo);
};