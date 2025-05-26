#include "screen.h"

Screen::Screen() : u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, I2C::SCL, I2C::SDA) {}

void Screen::begin() {
    u8g2.begin();
}

void Screen::setup(uint8_t number, char team) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_5x7_tr);
    displayHomeBitmap();
    draw_team(team);
    draw_number(number);
    u8g2.sendBuffer();
    Serial.println("Screen initialized.");
}

void Screen::draw(uint8_t timer, int distance1, int distance2, bool tir, char team){
    draw_tof(distance1, distance2);
    draw_timer(timer);
    draw_tir(tir);
    draw_team(team);
    u8g2.sendBuffer();
}

void Screen::draw_number(uint8_t number){
    u8g2.setDrawColor(0);
    u8g2.drawBox(NUMBER_X, NUMBER_Y - 8, 28, 10);
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x7_tr);
    u8g2.setCursor(NUMBER_X, NUMBER_Y);
    u8g2.print(number);
}

void Screen::draw_team(char team) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(TEAM_X, TEAM_Y - 8, 28, 10);
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x7_tr);
    u8g2.setCursor(TEAM_X, TEAM_Y);
    if(team == 'b') 
        u8g2.print("Blue");
    else if(team == 'y') 
        u8g2.print("Yellow");
    else u8g2.print("?");
}

void Screen::displayHomeBitmap() {
    u8g2.clearBuffer();
    u8g2.drawXBMP(0, 0, 128, 64, home);
    u8g2.sendBuffer();
}

void Screen::draw_tof(int distance1, int distance2) {
    char buf1[4], buf2[4];
    u8g2.setDrawColor(0);
    u8g2.drawBox(TOF0_X, TOF0_Y - 8, TOF1_X + 18 - TOF0_X, 10);
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x7_tr);

    u8g2.setCursor(TOF0_X, TOF0_Y);
    if(distance1 > 999) 
        u8g2.print("OUT");
    else {
        snprintf(buf1, sizeof(buf1), "%03d", distance1);
        u8g2.print(buf1);
    }

    u8g2.setCursor(TOF1_X, TOF1_Y);
    if(distance2 > 999) 
        u8g2.print("OUT");
    else {
        snprintf(buf2, sizeof(buf2), "%03d", distance2);
        u8g2.print(buf2);
    }
}


void Screen::draw_timer(int timer) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(TIMER_X, TIMER_Y - 8, 28, 10);
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x7_tr);
    u8g2.setCursor(TIMER_X, TIMER_Y);
    u8g2.print(timer);
}

void Screen::draw_tir(bool tir) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(TIR_X, TIR_Y - 8, 28, 10);
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x7_tr);
    u8g2.setCursor(TIR_X, TIR_Y);
    if(tir) 
        u8g2.print("ready");
    else 
        u8g2.print("no");
}
