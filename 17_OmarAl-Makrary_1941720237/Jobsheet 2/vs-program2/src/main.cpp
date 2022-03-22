#include <Arduino.h>

#define RED_LED D5 
#define GREEN_LED D6 
#define BLUE_LED D7

void setup() {
  //Practicum One

  // Serial.begin(115200);
  // pinMode(RED_LED,OUTPUT);
  // pinMode(GREEN_LED,OUTPUT);
  // pinMode(BLUE_LED,OUTPUT);
  // Serial.println("Contoh Program LED RGB");

  //Practicum Two

  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Contoh Program LED SOS");
}

void loop() {
  //Practicum One

  // rgbLED();

  //  Assignment

  digitalWrite(D4, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  //Practicum Two

  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); 
    delay(150);                  
    digitalWrite(RED_LED, LOW); 
    delay(100);                  
  }
  delay(100);

  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); 
    delay(400);                  
    digitalWrite(RED_LED, LOW); 
    delay(100);                  
  }
  delay(100);

  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); 
    delay(150);                  
    digitalWrite(RED_LED, LOW); 
    delay(100);                  
  }

  delay(5000);
}

//Practicum One

// void rgbLED(){

//   digitalWrite(RED_LED, HIGH); 
//   digitalWrite(GREEN_LED, LOW); 
//   digitalWrite(BLUE_LED, LOW); 
//   Serial.println("LED Merah nyala"); 
//   delay(1000); 

//   digitalWrite(RED_LED, LOW); 
//   digitalWrite(GREEN_LED, HIGH); 
//   digitalWrite(BLUE_LED, LOW); 
//   Serial.println("LED Hijau nyala"); 
//   delay(1000); 

//   digitalWrite(RED_LED, LOW); 
//   digitalWrite(GREEN_LED, LOW); 
//   digitalWrite(BLUE_LED, HIGH); 
//   Serial.println("LED Biru nyala"); 
//   delay(1000);
// }

