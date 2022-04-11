#include <Arduino.h>
#include <SimpleDHT.h>

#define RED_LED D5
#define GREEN_LED D6
#define BLUE_LED D7

#define pinDHT 7

byte temperature = 0;
byte humidity = 0;

SimpleDHT11 dht11(D1);

void TemperatureHumidity()
{
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Failed to read from DHT sensor, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  Serial.print((int)temperature);
  Serial.print(" *C, ");
  Serial.print((int)humidity);
  Serial.println(" H");

  if ((int)temperature >= 30)
  {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    Serial.println(":Hot Temperature");
  }
  else if ((int)temperature >= 20)
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    Serial.println(":Normal Temperature");
  }
  else
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    Serial.println(":Cold Temperature");
  }

  delay(5000);
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Simple DHT");
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  delay(5000);
}

void loop()
{
  TemperatureHumidity();
}