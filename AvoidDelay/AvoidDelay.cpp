#include "AvoidDelay.h"
#include <Arduino.h>

AvoidDelay::AvoidDelay(int maxTimers) : maxTimers(maxTimers), timerCount(0) {
    timers = new Timer[maxTimers];
}
void AvoidDelay::begin(){
    Serial.begin(9600);
}
void AvoidDelay::setInterval(unsigned long interval, TimerCallback callback) {
    if (timerCount < maxTimers) {
        timers[timerCount].interval = interval;
        timers[timerCount].callback = callback;
        timers[timerCount].previousMillis = 0;
        timerCount++;
    }
    if(timerCount>maxTimers){
       Serial.println("Increase the timers to match the number of events");
    }
}

void AvoidDelay::update() {
    unsigned long currentMillis = millis();
    for (int i = 0; i < timerCount; i++) {
        if (currentMillis - timers[i].previousMillis >= timers[i].interval) {
            timers[i].previousMillis = currentMillis;
            timers[i].callback();
        }
    }
}
