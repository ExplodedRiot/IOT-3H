#include <Arduino.h>

#define RED_LED D0

void setup() {
  Serial.begin(115200);// setbaudrate 115200
  pinMode(BUILTIN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT); //set GP102 atau D4 nyala
}

void loop() {
  Serial.println("Nyalakan LED"); //tamppilan buat di serial monitor
  digitalWrite(RED_LED, HIGH);// menampilkan string ke serial monitor
  delay(1000);// jeda 1000 ms
  Serial.println("Nyalakan LED");
  digitalWrite(RED_LED, LOW);
  delay(1000); 
}