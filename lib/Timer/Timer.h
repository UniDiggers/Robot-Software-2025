#pragma once

#include <esp_timer.h>
#include <Arduino.h>

enum TimeUnit {
    minutes = 60 * 1000 * 1000,
    seconds = 1000 * 1000,
    millisec = 1000,
    microsec = 1
};

class Timer
{
public:
    Timer();
    Timer(void (*function)(), int duration, TimeUnit unit = seconds, int cbIteration = 1, bool _release = true);
    ~Timer();
    esp_err_t setup();
    esp_err_t start();
    esp_err_t stop();
    esp_err_t free();

    int getRemainingTimeBeforeCb();
    int getRemainingCb();

private:
    static void callback(void *arg);

    bool enabled = false;

    int timerDuration = 0;
    esp_timer_handle_t timer = nullptr;
    void (*fn)(void);
    int cnt = 0;
    int max;
    int startDate;
    bool release;
};