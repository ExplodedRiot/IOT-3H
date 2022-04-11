#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7     // SD3 pin signal sensor DHT

byte temperature = 0;
byte humidity = 0;

SimpleDHT11 dht11(D7); // instan sensor dht11

void TemperatureHumidity()
{
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  float c = temperature;
  float k = temperature + 273.15;
  float r = 0.8 * temperature;


  Serial.println("==============================");
  Serial.print("Celcius Temp  : ");
  Serial.print(c);
  Serial.print(" *C, ");
  Serial.println();
  Serial.print("Kelvin Temp   : ");
  Serial.print(k);
  Serial.print(" *K, ");
  Serial.println();
  Serial.print("Reamur Temp   : ");
  Serial.print(r);
  Serial.print(" *R, ");
  Serial.println();
  Serial.print("Humidity      : ");
  Serial.print(humidity);
  Serial.print(" H, ");
  Serial.println();
  Serial.println("==============================");
  
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Simple DHT");
  delay(1000);
}

void loop()
{
  TemperatureHumidity();
  Serial.println("");
  delay(4000);
}