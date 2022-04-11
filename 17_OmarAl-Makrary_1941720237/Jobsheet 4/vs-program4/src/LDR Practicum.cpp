#include <Arduino.h>
#define sensorLDR A0
int sensorValue;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Example Using Sensor LDR");
  delay(3000);
}

void loop()
{
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorLDR);
  Serial.print("Sensor LDR Value : ");
  Serial.println(sensorValue);
  delay(1000);
}