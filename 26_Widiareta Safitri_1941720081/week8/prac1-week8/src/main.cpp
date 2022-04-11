#include <Arduino.h>
#define sensorLDR A0
int nilaiSensor;

void setup() {
  Serial.begin(9600);
  Serial.println("The example of Sensor LDR usage");
  delay(3000);
}

void loop() {
  nilaiSensor = analogRead(sensorLDR);
  Serial.print("Sensor Value: ");
  Serial.println(nilaiSensor);
  delay(1000);
}