#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "QuentbinksBoard.h"
#include "wallpaper.h"
#include "Timer.h"

static const int OLED_RESET = -1;
static const int ScreenWidth = 128;
static const int ScreenHeight = 64;
static const int ScreenAddr = 0x3C;

class Screen
{
private:
    int addr = ScreenAddr, width = ScreenWidth, height = ScreenHeight, resetPin = ScreenAddr;
    Adafruit_SSD1306 display;


public:
    Screen(int addr = ScreenAddr, int width = ScreenWidth, int height = ScreenHeight, int resetPin = OLED_RESET);
    bool setup();
    void drawHome();
    void tofDraw(int distance);
    void timerDraw(int time);
    void teamDraw(char team);
    void update();
};
