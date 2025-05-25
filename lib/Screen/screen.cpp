#include "screen.h"

Screen::Screen() : display(nullptr) {}

void Screen::begin() {
    if (display) delete display;
    display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
    if (!display->begin(SSD1306_SWITCHCAPVCC, 0x3c)) { 
        Serial.println(F("SSD1306 allocation failed"));
        while (1);
    }
    display->clearDisplay();
    display->display();
}

void Screen::setup(char team) {
    display->clearDisplay();
    displayHomeBitmap();
    draw_team(team);
    display->display();
}

void Screen::draw(uint8_t timer, int distance1, int distance2, bool tir, char team, bool espnow) {
    display->clearDisplay();
    draw_tof(distance1, distance2);
    draw_espnow(espnow);
    draw_timer(timer);
    draw_tir(tir);
    draw_team(team);
    display->display();
}

void Screen::draw_team(char team) {
    display->fillRect(TEAM_X, TEAM_Y - 8, 28, 10, SSD1306_BLACK);
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);
    display->setCursor(TEAM_X, TEAM_Y);
    if(team == 'b')
        display->print("Blue");
    else if(team == 'y')
        display->print("Yellow");
    else
        display->print("?");
}

void Screen::displayHomeBitmap() {
    display->drawBitmap(0, 0, home, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
}

void Screen::draw_tof(int distance1, int distance2) {
    char buf1[5], buf2[5];
    display->fillRect(TOF0_X, TOF0_Y - 8, TOF1_X + 18 - TOF0_X, 10, SSD1306_BLACK);
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);

    display->setCursor(TOF0_X, TOF0_Y);
    if(distance1 > 999)
        display->print("OUT");
    else {
        snprintf(buf1, sizeof(buf1), "%03d", distance1);
        display->print(buf1);
    }

    display->setCursor(TOF1_X, TOF1_Y);
    if(distance2 > 999)
        display->print("OUT");
    else {
        snprintf(buf2, sizeof(buf2), "%03d", distance2);
        display->print(buf2);
    }
}

void Screen::draw_espnow(bool espnow) {
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);
    if(!espnow) {
        display->setCursor(ESPNOW_X, ESPNOW_Y);
        display->print("/");
    }
}

void Screen::draw_timer(int timer) {
    display->fillRect(TIMER_X, TIMER_Y - 8, 28, 10, SSD1306_BLACK);
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);
    display->setCursor(TIMER_X, TIMER_Y);
    display->print(timer);
}

void Screen::draw_tir(bool tir) {
    display->fillRect(TIR_X, TIR_Y - 8, 28, 10, SSD1306_BLACK);
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);
    display->setCursor(TIR_X, TIR_Y);
    if(tir)
        display->print("ready");
    else
        display->print("no");
}