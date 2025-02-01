#include "screen.h"

Screen::Screen(int addr, int width, int height, int resetPin)
{
    display = Adafruit_SSD1306(width, height, &Wire, resetPin);
}

bool Screen::setup()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, addr))
    {
        Serial.println(F("SSD1306 allocation failed"));
        return false;
    }

    display.clearDisplay();
    return true;
}

void Screen::drawHome()
{
    display.clearDisplay();
    display.drawBitmap(0, 0, home, 128, 64, 1);
    display.display();
}

void Screen::tofDraw(int distance)
{
    char strDistance[10];
    sprintf(strDistance, "%d", distance);

    if (distance == -1 || distance > 2000)
        strcpy(strDistance, "OUT");

    // Clear display
    display.clearDisplay();
    display.drawBitmap(0, 0, home, 128, 64, 1);

    display.setTextSize(0.5); // Draw 2X-scale text
    display.setTextColor(SSD1306_BLACK);
    //Display title
    display.setCursor(15, 10);
    display.println(F("Tof :"));

    // Display distance
    display.setCursor(15, 20);
    display.println(F(strDistance));
    display.display();
}