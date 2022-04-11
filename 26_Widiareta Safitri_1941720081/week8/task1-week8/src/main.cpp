#include <Arduino.h>
#include <SimpleDHT.h>

// DHT Sensor
#define pinDHT 7   // SD3 pin signal sensor DHT

byte temperature = 0;
byte humidity = 0;

SimpleDHT11 dht11(D1); // instan sensor dht11

// LED RGB
#define RED_LED D5   
#define GREEN_LED D6
#define BLUE_LED D7

// LDR Sensor
#define sensorLDR A0
int nilaiSensor;


void TempLDR()
{
  int err = SimpleDHTErrSuccess;
  nilaiSensor = analogRead(sensorLDR);

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return;
  }


  if ((int)temperature <= 30 && nilaiSensor >= 500)
  {
    Serial.println("==============================");
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    Serial.println("Temperatur    : Cold");
    Serial.println("Light         : Dim");
    Serial.println("LED           : BLUE");
    Serial.print("Celcius Temp  : ");
    Serial.print((int)temperature);
    Serial.print(" *C, ");
    Serial.println();
    Serial.print("Light Value   : ");
    Serial.print((int)nilaiSensor);
    Serial.println();
    Serial.println("==============================");
  }


  else
  {
    Serial.println("==============================");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    Serial.println("Temperatur    : Hot");
    Serial.println("Light         : Bright");
    Serial.println("LED           : RED");
    Serial.print("Celcius Temp  : ");
    Serial.print(temperature);
    Serial.print(" *C, ");
    Serial.println();
    Serial.print("Light Value   : ");
    Serial.print((int)nilaiSensor);
    Serial.println();
    Serial.println("==============================");
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("TASK 1 : DHT11 SENSOR AND LDR SENSOR");
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  delay(1000);
}
void loop() {
  TempLDR();
  Serial.println("");
  delay(3000);
}