#include "Timer.h"
#include "utils.h"

Timer::Timer() {}

Timer::Timer(void (*function)(), int duration, TimeUnit unit, int cbIteration, bool _release) : fn(function), max(cbIteration), release(_release)
{
    if (duration < 1 || cbIteration < 1)
    {
        return;
    }

    timerDuration = duration * unit;
}

Timer::~Timer()
{
    if (timer)
    {
        esp_timer_stop(timer);
        esp_timer_delete(timer);
    }
}

esp_err_t Timer::setup()
{
    esp_timer_create_args_t timerArgs = {
        .callback = &callback,
        .arg = this
        // TODO: "name" + instance nbr : timer1, timer2, ...
        // dispatch_method is task by default
    };

    return esp_timer_create(&timerArgs, &timer);
}

esp_err_t Timer::start()
{
    if (!enabled)
    {
        esp_err_t result = esp_timer_start_periodic(timer, timerDuration);
        if (result == ESP_OK)
        {
            startDate = micros();
            enabled = true;
        }
        return result;
    }
    else
        return ESP_ERR_INVALID_STATE;
}

esp_err_t Timer::stop()
{
    if (enabled)
    {
        esp_err_t result = esp_timer_stop(timer);
        if (result == ESP_OK)
        {
            enabled = false;
        }
        return result;
    }
    else
        return ESP_ERR_INVALID_STATE;    
}

esp_err_t Timer::free()
{
    if (enabled)
    {
        stop();
    }

    // WARN("Object still alive without timer");

    return esp_timer_delete(timer);
}

// TODO: reset = stop, delete, recreate

int Timer::getRemainingTimeBeforeCb()
{
    if (enabled)
        return timerDuration - (micros() - startDate);
    else return -1; // TODO: find alternative, -1 could be a returned value
}

int Timer::getRemainingCb()
{
    if (max >= 1)
        return max - cnt;
    else return -1;
}

void Timer::callback(void *arg)
{
    Timer *timerObj = (Timer*) arg;

    if (timerObj->cnt >= timerObj->max)
    {
        return;
    }

    timerObj->cnt++;
    timerObj->fn();

    // DEBUG("cnt = " + String(timerObj->cnt));

    if (timerObj->cnt == timerObj->max)
    {
        if (timerObj->release)
        {
            timerObj->free();
        }
    }
    else if (timerObj->max >= 2)
    {
        timerObj->startDate = micros();
    }
}