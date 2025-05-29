#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "utils.h"

struct {
    bool tir;
    char team;
} comm;

void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    memcpy(&comm, incomingData, sizeof(comm));
}

void setupESPNow()
{
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK)
    {
        ERROR("ESP-NOW initialization failed");
    }

    esp_now_register_recv_cb(onDataRecv);

    comm = {
        .tir = false,
        .team = 'b'
    };
}

void disableESPNow()
{
    esp_now_deinit();           // Désactive ESP-NOW
    WiFi.mode(WIFI_OFF);        // Coupe le WiFi pour économiser l'énergie
}