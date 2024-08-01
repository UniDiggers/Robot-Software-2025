#include "screen.h"

Screen::Screen() // Definition of the screen could be passed as parameters
{   
    display = Adafruit_SSD1306(width, height, &Wire, reset_pin);

    if (!display.begin(SSD1306_SWITCHCAPVCC, address))
    {
        Serial.println("SSD1306 allocation failed, exiting...");
        exit(EXIT_FAILURE);
    }
    display.clearDisplay();
}

void Screen::drawHome()
{
    display.clearDisplay();
    display.drawBitmap(0, 0, home, width, height, 1);
    display.display();
}

void Screen::drawDistance(int distance)
{
    display.clearDisplay();
    display.drawBitmap(0, 0, tof, width, height, 1);
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(55, 35);

    if (distance == -1 || distance > 500)
        display.println("OUT");
    else
        display.println(String(distance));
    
    display.display();
}