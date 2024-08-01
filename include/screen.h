#ifndef SCREEN_H
#define SCREEN_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "wallpaper.h"
#include "tof.h"

//Definition of the screen
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/*
You MUST call display() after drawing commands !
*/

bool screen_setup(){
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        return false;
    }
    else{
        display.clearDisplay();
        return true;
    }  
}

void home_screen(){
    //Print Home Page
    display.clearDisplay();
    display.drawBitmap(0, 0, home, 128, 64, 1);
    display.display();
}

void tof_screen(){
    //Print distance on screen
    int distance = get_distance();
    char str_distance[10];
    sprintf(str_distance, "%d", distance);
    if(distance == -1 || distance > 2000){ 
        strcpy(str_distance, "OUT");
    }
    display.clearDisplay();
    display.drawBitmap(0, 0, tof, 128, 64, 1);
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(55, 35);
    display.println(F(str_distance));
    display.display();
}


#endif