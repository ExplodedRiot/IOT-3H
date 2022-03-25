#include <Arduino.h>

#define RED_LED D5   // Red color led
#define GREEN_LED D6 // Green color led
#define BLUE_LED D7  // Blue color led

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); // manage digital pins as the output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.println("Example of LED RGB Program");
}

void rgbLED()
{
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  Serial.println("Red LED turn on");
  delay(1000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  Serial.println("Green LED turn on");
  delay(1000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  Serial.println("Blue LED turn on");
  delay(1000);
}

void loop()
{
  rgbLED();
}