#include <Arduino.h>

#define RED_LED D0 // define the pin D0 or GPI016

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  digitalWrite(RED_LED, HIGH);   // turn on RED LED
  delay(1000);
  digitalWrite(RED_LED, LOW);    
  delay(1000);
}