#pragma once

#define MAX_TIMERS 10 // Default maximum number of timers

// Macro to simplify interval setting
#define setDelay(timer, interval, code) \
    timer.setInterval(interval, []() { code })

typedef void (*TimerCallback)();

class AvoidDelay {
public:
    AvoidDelay(int maxTimers = MAX_TIMERS);

    void setInterval(unsigned long interval, TimerCallback callback);
    void update();
    void begin();

private:
    struct Timer {
        unsigned long previousMillis;
        unsigned long interval;
        TimerCallback callback;
    };

    Timer* timers;
    int maxTimers;
    int timerCount;
};
