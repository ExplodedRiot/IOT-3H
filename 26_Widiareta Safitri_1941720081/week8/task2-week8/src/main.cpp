#include <Arduino.h>

// LED RGB
#define RED_LED D5
#define GREEN_LED D6
#define BLUE_LED D7

// HC-SR04
#define triggerPin D1
#define echoPin D2

void setup()
{
  Serial.begin(115200);
  Serial.println("TASK 12: HC-SR04 Sensor");
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);
}

void readDistance(){
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance == 1){
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    Serial.println("LED             : BLUE");
    Serial.print("Distance        : ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
    Serial.println("==============================");
  }
  else if(distance == 2){
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    Serial.println("LED            : GREEN");
    Serial.print("Distance        : ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
    Serial.println("==============================");
  }
  else if(distance == 3){
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    Serial.println("LED             : RED");
    Serial.print("Distance        : ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
    Serial.println("==============================");
  }
  else {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    delay(500);

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay(500);

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(500);
    Serial.println("LED             : COLORFUL");
    Serial.print("Distance        : ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
    Serial.println("==============================");
  }
 
}

void loop()
{
  readDistance();
  delay(2000);
}