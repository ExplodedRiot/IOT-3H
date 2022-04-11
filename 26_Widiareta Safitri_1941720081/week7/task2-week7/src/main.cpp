#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7     // SD3 pin signal sensor DHT
#define RED_LED D2   // set red led in pin d4
#define GREEN_LED D3 // set gree led in pin d5
#define BLUE_LED D4  // set blue led in pin d6

byte temperature = 0;
byte humidity = 0;

SimpleDHT11 dht11(D7); // instan sensor dht11

void TemperatureCategory()
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

  if ((int)temperature <= 24)
  {
    Serial.println("==============================");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    Serial.println("Temperatur    : Cold");
    Serial.println("LED           : RED");
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

  else if ((int)temperature > 24 && (int)temperature <= 37)
  {
    Serial.println("===============================");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    Serial.println("Temperatur    : Normal");
    Serial.println("LED           : GREEN");
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
    Serial.println("===============================");
  }

  else
  {
    Serial.println("==============================");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    Serial.println("Temperatur    : Hot");
    Serial.println("LED           : BLUE");
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
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Simple DHT");
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  delay(1000);
}

void loop()
{
  TemperatureCategory();
  Serial.println("");
  delay(4000);
}