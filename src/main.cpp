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
#define TIR true

// --- Proto ---
void refresh();




// --- Objects ---
Screen screen;
Strategy strategy;
TOF& tof = TOF::getInstance();
DFPlayer player;
SERVO servo;

// // Timer 
// hw_timer_t *Timer1 = NULL;

// void IRAM_ATTR onTimer(){
//     strategy.fullstop();
// }

void refresh()
{
    return;
}

void setup()
{

    Serial.begin(115200);
    Serial.println("Starting...");

    setupESPNow(); // Prepare communication

    screen.begin(); // Screen must be setup before screen
    
    // Timer1 = timerBegin(0, 80, true);
    // timerAttachInterrupt(Timer1, &onTimer, true);
    // timerAlarmWrite(Timer1, 100 * 1000000, true);
    
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

    //timerAlarmEnable(Timer1); //Just Enable

    //player.Play(true, CRAZY_FROG, 30); // Play specified track
}

void loop()
{
    disableESPNow(); 
    strategy.game();
    DEBUG("End loop");
}