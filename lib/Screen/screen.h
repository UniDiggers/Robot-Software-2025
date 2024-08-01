#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "wallpaper.h"

// Definition of the screen
const int width = 128;      // OLED display width, in pixels
const int height = 64;        // OLED display height, in pixels
const int reset_pin = -1;     // Reset pin # (or -1 if sharing Arduino reset pin)
const int address = 0x3C;   // ! Why not 0x3D for 128x64 like specified in the datasheet ?

class Screen
{
private:
    Adafruit_SSD1306 display;

public:
    Screen();
    void drawHome();
    void drawDistance(int distance);
};