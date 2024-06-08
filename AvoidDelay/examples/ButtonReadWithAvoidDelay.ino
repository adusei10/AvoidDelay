#include <AvoidDelay.h>

const int Pin = A0;

// Create an instance of AvoidDelay with a specified number of timers
AvoidDelay timer(1);

void setup() {

  Serial.begin(9600);

  pinMode(Pin,INPUT_PULLUP);

  timer.begin();
  
  loop2();
}


void loop() {
  // Update the timers in the loop
  timer.update();
}

void loop2() {

  setDelay(timer, 250, {
    int val = digitalRead(Pin);
    if (val == LOW) {
      Serial.println("Pressed");
    } else {
      Serial.println("Released");
    }
  });
  
}
