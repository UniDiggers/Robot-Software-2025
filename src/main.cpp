#include <Arduino.h>

#include "Movement.h"
#include "screen.h"
#include "tof.h"
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
#define TIR true

// --- Objects ---
Screen screen;
Strategy strategy;
TOF& tof = TOF::getInstance();
DFPlayer player;
SERVO servo;


void setup()
{

    Serial.begin(115200);
    Serial.println("Starting...");

    setupESPNow(); // Prepare communication

    screen.begin(); // Screen must be setup before screen
    
    delay(1000);
    int id = strategy.setup(comm.team);

    screen.setup(id, comm.team);
    
    tof.setup(highSpeed);
    player.setup();

    setup_LED();

    if (TIR)
    {
        using namespace Colors;
        
        setLEDColor(RED);
        DEBUG("Waiting for tirette");
        while (comm.tir == false)
        {
            Serial.println("Waiting for tirette...");
        }

        setLEDColor(ORANGE);
        DEBUG("Waiting for tirette removal");
        while (comm.tir)
        {
            Serial.println("Waiting for removal");
        }

        setLEDColor(GREEN);
    }


    player.Play(true, CRAZY_FROG, 20); // Play specified track
    disableESPNow(); 
}

void loop()
{
    strategy.game();
    DEBUG("End loop");
}