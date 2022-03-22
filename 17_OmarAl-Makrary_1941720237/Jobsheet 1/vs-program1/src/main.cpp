#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:

  //practicum 1
  // Serial.begin(115200); // setbaudrate 115200

  //practicum 2
  pinMode(D4, OUTPUT);

}

void loop()
{
  // put your main code here, to run repeatedly:

  //practicum 1
  // Serial.println("Hello World"); // show the following string to the serial monitor
  // delay(1000);                   // delay 1000 ms

  //practicum 2
  digitalWrite(D4, HIGH);
  delay(1000);
  digitalWrite(D4, LOW);
  delay(1000);
}
