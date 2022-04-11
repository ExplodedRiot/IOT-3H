#include <Arduino.h>
#include <SimpleDHT.h>

#define sensorLDR A0
#define RED_LED D5
#define BLUE_LED D7
#define pinDHT 7

byte temperature = 0;
byte humidity = 0;
int sensorValue;
SimpleDHT11 dht11(D1);

void setup()
{
    Serial.begin(9600);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    Serial.println("Assignment 1");
    delay(3000);
}

void TemperatureLight()
{
    Serial.println("=======================================================");
    int err = SimpleDHTErrSuccess;

    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
    {
        Serial.print("Failed to read from DHT sensor, err=");
        Serial.println(err);
        delay(2000);
        return;
    }

    Serial.print((int)temperature);
    Serial.print(" *C, ");
    Serial.print((int)humidity);
    Serial.println(" H");
    sensorValue = analogRead(sensorLDR);
    Serial.print("Sensor LDR Value : ");
    Serial.println(sensorValue);

    if ((int)temperature >= 26 && sensorValue == 60)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(BLUE_LED, HIGH);
        Serial.println(":Hot Temperature and Bright Light");
    }
    else if ((int)temperature <= 25 && sensorValue == 1024)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(BLUE_LED, LOW);
        Serial.println(":Cold Temperature and Dim Light");
    }else{
        digitalWrite(RED_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);
    }
    Serial.println("=======================================================");

    delay(2000);
}

void loop()
{
    TemperatureLight();
}