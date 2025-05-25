#pragma once
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "PAMIBOARD.h"
#include "wallpaper.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TOF0_X 29
#define TOF0_Y 9
#define TOF1_X 48
#define TOF1_Y 9
#define TIMER_X 105
#define TIMER_Y 16
#define TEAM_X 100
#define TEAM_Y 38
#define TIR_X 105
#define TIR_Y 61
#define ESPNOW_X 5
#define ESPNOW_Y 9

class Screen {
public:
    Screen();
    void begin();
    void setup(char team);
    void draw(uint8_t timer, int distance1, int distance2, bool tir, char team, bool espnow);
    void draw_team(char team);

private:
    Adafruit_SSD1306* display;
    void displayHomeBitmap();
    void draw_tof(int distance1, int distance2);
    void draw_espnow(bool espnow);
    void draw_timer(int timer);
    void draw_tir(bool tir);
};