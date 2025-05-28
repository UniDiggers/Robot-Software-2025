#include <Arduino.h>

#include "Movement.h"
#include "screen.h"
#include "tof.h"
#include "Timer.h"
#include "strategy.h"
#include "DFPlayer.h"
#include "servo.h"
#include "led.h"

#include "wallpaper.h"
#include "pami.h"

#include "PAMIBOARD.h"
#include "utils.h"
#include <Wire.h>

// --- Draft stuff ---
const bool debug = false;

// --- Proto ---
void fullstop();
void refresh();

// --- Objects ---
Screen screen;
Strategy strategy;
TOF tof;
Timer globaltimer(&fullstop, 85, seconds), updatetimer(&refresh, 1, seconds);
DFPlayer player;
SERVO servo;

void fullstop()
{
    updatetimer.stop();
    globaltimer.stop();
    strategy.fullstop();
}

void refresh()
{
    return;
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting...");

    screen.begin(); // Screen must be setup before screen
    
    Wire.begin(I2C::SDA, I2C::SCL);

    setupESPNow(); // Prepare communication

    int id = strategy.setup();

    screen.setup(id, comm.team);
    
    tof.setup(highSpeed);
    player.setup();

    setup_LED();

    if (!debug)
    {
        using namespace Colors;
        
        setLEDColor(RED);
        while (comm.tir == false)
        {
            DEBUG("Waiting for tirette");
        }

        setLEDColor(ORANGE);
        while (comm.tir)
        {
            DEBUG("Waiting for tirette removal");
        }

        setLEDColor(GREEN);
    }

    globaltimer.start(); // Strating the waiting timer

    player.Play(true, CRAZY_FROG, 30); // Play specified track
}

void loop()
{
    //strategy.game();
    DEBUG("End loop");
}