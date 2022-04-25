#include <Arduino.h>
// #define LED D0

void setup()
{
  serial.begin(115200);
}

void loop()
{
  serial.println("hello word");
  delay(1000);
}