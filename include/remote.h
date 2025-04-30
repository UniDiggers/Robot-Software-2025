/*
   -- ESP32 test --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"
#define REMOTEXY_ACCESS_PASSWORD "1234"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 523 bytes
  { 255,12,0,5,0,4,2,19,0,0,0,69,83,80,51,50,45,83,51,0,
  31,1,106,200,1,1,28,0,129,19,2,67,12,64,8,80,65,77,73,32,
  45,32,82,65,84,80,0,129,251,0,114,18,64,8,95,95,95,95,95,95,
  95,95,95,95,95,95,95,95,0,12,22,18,40,10,195,30,26,76,111,110,
  82,97,110,103,101,0,76,111,110,103,82,97,110,103,101,65,99,99,117,114,
  97,99,121,0,76,111,110,103,82,97,110,103,101,83,112,101,101,100,0,72,
  105,103,104,83,112,101,101,100,0,72,105,103,104,65,99,99,117,114,97,99,
  121,0,67,64,18,40,10,86,2,26,129,0,19,22,9,64,8,84,79,70,
  49,0,12,22,30,40,10,195,30,26,76,111,110,82,97,110,103,101,0,76,
  111,110,103,82,97,110,103,101,65,99,99,117,114,97,99,121,0,76,111,110,
  103,82,97,110,103,101,83,112,101,101,100,0,72,105,103,104,83,112,101,101,
  100,0,72,105,103,104,65,99,99,117,114,97,99,121,0,67,64,30,40,10,
  86,2,26,129,0,31,22,9,64,8,84,79,70,50,0,129,254,29,114,18,
  64,8,95,95,95,95,95,95,95,95,95,95,95,95,95,95,0,74,48,47,
  56,10,29,2,26,79,64,89,101,108,108,111,119,0,165,64,66,108,117,101,
  0,129,8,47,28,11,64,8,84,101,97,109,0,129,254,46,114,18,64,8,
  95,95,95,95,95,95,95,95,95,95,95,95,95,95,0,1,10,155,24,24,
  0,2,31,76,101,102,116,0,1,43,174,24,24,0,2,31,68,111,119,110,
  0,1,71,155,24,24,0,2,31,82,105,103,104,116,0,1,42,136,24,24,
  0,2,31,85,112,0,129,0,99,114,18,64,8,95,95,95,95,95,95,95,
  95,95,95,95,95,95,95,0,129,45,58,16,63,64,8,124,0,129,11,63,
  28,11,64,8,83,101,114,118,111,0,129,69,116,18,7,64,8,65,99,99,
  101,108,0,129,18,117,20,7,64,8,83,112,101,101,100,0,4,2,112,14,
  36,0,2,26,4,89,112,14,36,0,2,26,4,5,71,14,36,0,2,26,
  4,32,71,14,36,0,2,26,1,47,115,12,12,0,2,31,83,111,117,110,
  100,0,4,74,71,14,36,0,2,26,129,67,63,27,11,64,8,68,101,108,
  97,121,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t tof1_mode; // from 0 to 5
  uint8_t tof2_mode; // from 0 to 5
  uint8_t button_left; // =1 if button pressed, else =0
  uint8_t button_down; // =1 if button pressed, else =0
  uint8_t button_right; // =1 if button pressed, else =0
  uint8_t button_up; // =1 if button pressed, else =0
  int8_t slider_speed; // from 0 to 100
  int8_t slider_accel; // from 0 to 100
  int8_t slider_left; // from 0 to 100
  int8_t slider_right; // from 0 to 100
  uint8_t sound_starter; // =1 if button pressed, else =0
  int8_t slider_delay; // from 0 to 100

    // output variables
  int16_t tof1_value; // -32768 .. +32767
  int16_t tof2_value; // -32768 .. +32767
  uint8_t strings_team; // from 0 to 2

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)