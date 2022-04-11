#include <Arduino.h>

#define RED_LED D5
#define GREEN_LED D6
#define BLUE_LED D7

#define triggerPin D1
#define echoPin D2

void setup()
{
    Serial.begin(9600);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.println("Assignment 2");
    delay(3000);
}

void DistanceLight()
{
    Serial.println("=======================================================");
    long duration, distance;
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print(distance);
    Serial.println(" cm");
    if (distance == 1)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, LOW);
        Serial.println(":Blue Light on 1 cm");
    }
    else if (distance == 2)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, HIGH);
        Serial.println(":Green Light on 2 cm");
    }
    else if (distance == 3)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);
        Serial.println(":Red Light on 3 cm");
    }
    else if (distance > 3)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        Serial.println(":All LEDs on more than 3 cm");
    }
    else
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);
    }
    Serial.println("=======================================================");

    delay(2000);
}

void loop()
{
    DistanceLight();
}