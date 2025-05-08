#pragma once

#include <Wire.h>
#include <U8g2lib.h>

#include "PAMIBOARD.h"
#include "wallpaper.h"


class Screen
{
private:
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2 = U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
    uint8_t ScreenWidth = 128;
    uint8_t ScreenHeight = 64;
    char ScreenAddr = 0x3C;
    
public:
    bool setup();
    void displayBitmap(const uint8_t *bitmap);
    
};
