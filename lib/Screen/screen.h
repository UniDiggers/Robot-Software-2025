#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include "PAMIBOARD.h"
#include "wallpaper.h"

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
#define NUMBER_X 45
#define NUMBER_Y 32


class Screen {
public:
    Screen();
    void setup(uint8_t number, char team);
    void draw(uint8_t timer, int distance1, int distance2, bool tir, char team);
    void draw_team(char team);
    void begin();

private:
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
    void displayHomeBitmap();
    void draw_tof(int distance1, int distance2);
    void draw_timer(int timer);
    void draw_tir(bool tir);
    void draw_number(uint8_t number);
};
