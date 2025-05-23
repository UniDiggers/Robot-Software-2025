#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <Arduino.h>

//https://javl.github.io/image2cpp/

// enum avec les noms des wallpapers
// double tableau avec identifications des wallpapers par index

// 'home', 128x64px
const unsigned char home [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x5c, 0xdb, 0x0e, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x08, 0x55, 0x0a, 0x00, 
	0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x48, 0xd1, 0x06, 0x00, 
	0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x48, 0x51, 0x0a, 0x00, 
	0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x48, 0xd1, 0x0a, 0x00, 
	0x10, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xfc, 0xff, 0x0f, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x80, 0xff, 0x0f, 0xff, 0x1f, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x80, 0xff, 0x0f, 0xff, 0x1f, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x89, 0x04, 0x12, 0x09, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf0, 0x87, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcf, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcf, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcf, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x01, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcb, 0x07, 0x00, 0x00, 0x3e, 0xfd, 0x01, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0xf8, 0xcd, 0x03, 0x00, 0x00, 0x3c, 0xfb, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0xf8, 0xce, 0x03, 0x00, 0x00, 0x3c, 0xf7, 0x01, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0x78, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xef, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xb8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xdf, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xd8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xbf, 0x01, 0x38, 0x00, 0xb8, 0xdd, 0x06, 0x00, 
	0x00, 0x00, 0xe8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0x7f, 0x01, 0x38, 0x00, 0x90, 0x54, 0x05, 0x00, 
	0x00, 0x00, 0xf8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xff, 0x01, 0x38, 0x00, 0x90, 0x5d, 0x04, 0x00, 
	0x00, 0x00, 0xf8, 0xcb, 0x03, 0x00, 0x00, 0x3c, 0xfd, 0x01, 0x38, 0x00, 0x90, 0x54, 0x04, 0x00, 
	0x00, 0x00, 0xf8, 0xcd, 0x03, 0x00, 0x00, 0x3c, 0xfb, 0x01, 0x38, 0x00, 0x90, 0x55, 0x04, 0x00, 
	0x00, 0x00, 0xf8, 0xfe, 0x03, 0x00, 0x00, 0xfc, 0xf7, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x78, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xef, 0x01, 0x38, 0x00, 0xf8, 0xff, 0x07, 0x00, 
	0x00, 0x00, 0xb8, 0xff, 0x03, 0x00, 0x00, 0xfc, 0xdf, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xd8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xbf, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xe8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0x7f, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcb, 0x03, 0x00, 0x00, 0x3c, 0xfd, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xcd, 0x03, 0x00, 0x00, 0x3c, 0xfb, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xce, 0x03, 0x00, 0x00, 0x3c, 0xf7, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x78, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xef, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xb8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xdf, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xd8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xbf, 0x01, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xe8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0x7f, 0x01, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0xf8, 0xcf, 0x03, 0x00, 0x00, 0x3c, 0xff, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0xf8, 0xcf, 0x07, 0x00, 0x00, 0x3e, 0xff, 0x01, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0xf0, 0xc7, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x38, 0x00, 0x80, 0xeb, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x38, 0x00, 0x00, 0xa1, 0x00, 0x00, 
	0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x38, 0x00, 0x00, 0x69, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x38, 0x00, 0x00, 0xa9, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x01, 0x38, 0x00, 0x00, 0xa9, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x01, 0x38, 0x00, 0x80, 0xff, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif