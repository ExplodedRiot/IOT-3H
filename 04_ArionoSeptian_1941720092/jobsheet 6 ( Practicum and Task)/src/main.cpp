// Practicum
// #include <Arduino.h>
// #define sensorLDR D0 // untuk menggunaakn pin kabelnya
// int nilaiSensor;
// void setup()
// {
//   Serial.begin(115200); // untuk berkomunikasi dengan komputer
//   delay(500);           // untuk menjeda hasil
// }
// void loop()
// {                                      // perulangan
//   nilaiSensor = analogRead(sensorLDR); // untuk sensor membaca nilainya
//   Serial.print("Nilai Sensor : ");
//   Serial.println(nilaiSensor);
//}

// Task 1
// #include <Arduino.h>
// #define sensorLDR A0
// #define lampu D1
// int nilaiSensor;
// void setup()
// {
//   pinMode(lampu, OUTPUT); // untuk memilih mode output yang disimpan di var
//   Serial.begin(115200);   // Arduino berkuminkasi dengan LDR
//   delay(500);
// }
// void loop()
// {
//   nilaiSensor = analogRead(sensorLDR); // untuk menghidupkan sensor datanya
//   Serial.print("Nilai Sensor : ");
//   Serial.println(nilaiSensor);
//   if (nilaiSensor < 550)
//   {                            // untuk kondisi pada saat lampu hidup atau mati
//     digitalWrite(lampu, HIGH); // untuk menghidupkan lampu
//   }
//   else
//   {
//     digitalWrite(lampu, LOW); // untuk mematikan lampu
//   }
//   delay(500); // untuk menghentikan program sesuai dengan yang di kehendaki yaitu
//   selama 5 detik
// }
// Task 2
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define pinLDR A0
#define DHTTYPE DHT11
#define DHTPIN D1
#define LED_BLUE D4
#define LED_RED D2
DHT dht(DHTPIN, DHTTYPE);
unsigned long DHT_millis = 0, previousMillis = 0;
char buff[100];
float t = 0;
int h = 0, BLUE = HIGH;
void setup()
{
  Serial.begin(115200);
Serial.println("Tugas Simulasi Pendeteksi Suhu dan Kelembapan
dengan LED");
dht.begin();
pinMode(LED_BLUE, OUTPUT);
pinMode(LED_RED, OUTPUT);
}
void loop()
{
  // Melakukan pembacaan sensor DHT11 menggunakan millis
  unsigned long DHT_current = millis();
  if (DHT_current - DHT_millis >= 2000)
  {
    DHT_millis = DHT_current;
    h = dht.readHumidity();
    t = dht.readTemperature();
    Serial.println("========SCANNING DHT11!========");
  }
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  int ldr = 1024 - analogRead(pinLDR);
  Serial.print("LDR : ");
  Serial.print(ldr);
  Serial.print(" || ");
  Serial.print("Suhu : ");
  dtostrf(t, 2, 2, buff);
  Serial.print(buff);
  Serial.print("°C || Kelembapan : ");
  Serial.print(h);
  Serial.print("% || ");
  if (ldr > 512 && t < 30)
  {
    Serial.println("Cahaya Redup dan suhu dingin");
    digitalWrite(LED_RED, HIGH);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 300)
    {
      previousMillis = currentMillis;
      if (BLUE == LOW)
      {
        BLUE = HIGH;
      }
      else
      {
        BLUE = LOW;
      }
      digitalWrite(LED_BLUE, BLUE);
    }
  }
  else if (ldr < 512 && t > 30)
  {
    Serial.println("Cahaya Terang dan suhu panas");
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, HIGH);
  }
  else
  {
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_RED, HIGH);
    Serial.println("Tidak memenuhi kondisi");
  }
}
