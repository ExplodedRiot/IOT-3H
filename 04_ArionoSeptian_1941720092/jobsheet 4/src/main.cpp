#include <Arduino.h>

#define RED_LED D5 //led warna merah
#define GREEN_LED D6 //led warna hijau
#define BLUE_LED D7 //led warnah biru

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED,OUTPUT);//atur pin-pin digital sebagai output
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  Serial.println("Contoh Program LED RGB");
}

void rgbLED(){
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  Serial.println("LED Merah nyala");
  delay(1000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  Serial.println("LED Hijau nyala");
  delay(1000);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  Serial.println("LED Biru nyala");
  delay(1000);
}

void loop() {
  rgbLED();
}
// #include <Arduino.h>

// #define RED_LED D5   //led warna merah
// #define GREEN_LED D6 //led warna hijau
// #define BLUE_LED D7  //led warnah biru

// void setup()
// {
//   Serial.begin(115200);
//   pinMode(RED_LED, OUTPUT); //atur pin-pin digital sebagai output

//   Serial.println("Contoh Program LED SOS");
// }

// void loop()
// {
//   // 3 dits (3 titik atau huruf S)
//   for (int x = 0; x < 3; x++)
//   {
//     digitalWrite(RED_LED, HIGH); // LED nyala
//     delay(150);                  // delay selama 150ms
//     digitalWrite(RED_LED, LOW); // LED mati
//     delay(100);                  // delay selama 100ms
//   }
//   delay(100);

//   // 3 dahs (3 garis atau huruf O)
//   for (int x = 0; x < 3; x++)
//   {
//     digitalWrite(RED_LED, HIGH); // LED nyala
//     delay(400);                  // delay selama 400ms
//     digitalWrite(RED_LED, LOW); // LED mati
//     delay(100);                  // delay selama 100ms
//   }

//   // 100ms delay to cause slight gap between letters
//   delay(100);
//   // 3 dits again (3 titik atau huruf S)
//   for (int x = 0; x < 3; x++)
//   {
//     digitalWrite(RED_LED, HIGH); // LED nyala
//     delay(150);                  // delay selama 150ms
//     digitalWrite(RED_LED, LOW); // LED mati
//     delay(100);                  // delay selama 100ms
//   }

//   // wait 5 seconds before repeating the SOS signal
//   delay(5000);
// }

#include <Arduino.h>

#define RED_LED D5 //led warna merah
#define GREEN_LED D6 // led warna hijau
#define BLUE_LED D7 // led watna biru

void setup()
{

  Serial.begin(115200);
  pinMode(GREEN_LED, OUTPUT);//atur pin-pin digital sebagai output
  pinMode(D4, OUTPUT);
  Serial.println("Example LED SOS");
}

void loop()
{
  //  Ass
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(D4, HIGH);// LED nyala
    delay(150);  // delay selama 150ms
    digitalWrite(D4, LOW);// LED mati
    delay(100);// delay selama 100ms
  }
  delay(100);

  for (int x = 0; x < 3; x++)
  {
    digitalWrite(GREEN_LED, HIGH);// LED nyala
    delay(400);// delay selama 400ms
    digitalWrite(GREEN_LED, LOW);// LED mati
    delay(100);// delay selama 100ms
  }
  delay(100);
// 100ms delay to cause slight gap between letters
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(GREEN_LED, HIGH);// LED nyala
    delay(150);// delay selama 150ms
    digitalWrite(GREEN_LED, LOW);// LED mati
    delay(100);// delay selama 100ms
  }
// wait 5 seconds before repeating the SOS signal
  delay(5000);
}