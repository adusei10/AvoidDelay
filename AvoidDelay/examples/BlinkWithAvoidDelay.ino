#include <AvoidDelay.h>
// Define the LED pin
const int ledPin = 13;
// Create an instance of AvoidDelay with a specified number of timers
AvoidDelay timer(1);

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  timer.begin();

  loop2();
}


void loop() {
  // Update the timers in the loop
  timer.update();
}

void loop2() {

  setDelay(timer, 500, {
    digitalWrite(ledPin, !digitalRead(ledPin));
  });
  
}
