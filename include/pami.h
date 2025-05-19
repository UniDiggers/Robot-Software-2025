#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "utils.h"

struct commMessage {
    bool tir;
    char team;
};

commMessage incomming;

void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    memcpy(&incomming, incomingData, sizeof(incomming));
}

void setupESPNow()
{
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK)
    {
        ERROR("ESP-NOW initialization failed");
    }

    esp_now_register_recv_cb(onDataRecv);

    incomming = {
        .tir = false,
        .team = 'b'
    };
}
