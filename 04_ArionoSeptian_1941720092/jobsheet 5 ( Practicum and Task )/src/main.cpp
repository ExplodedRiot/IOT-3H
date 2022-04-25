// Practicum
//  #include <Arduino.h>
//  #include <DHT.h>
//  #define DHTTYPE DHT11 DHT
//  dht(D7, DHTTYPE);
//  void setup()
//  {
//    Serial.begin(115200);
//    Serial.println("Menggunakan DHT11");
//    dht.begin();
//  }
//  void loop()
//  {
//    delay(2000);
//    float h = dht.readHumidity();
//    float t = dht.readTemperature();
//    float f = dht.readTemperature(true);
//    if (isnan(h) || isnan(t) || isnan(f))
//    {
//      Serial.println("Failed to read from DHT sensor!");
//      return;
//    }
//    float hif = dht.computeHeatIndex(f, h);
//    float hic = dht.computeHeatIndex(t, h, false);
//    Serial.print(F("Humidity: "));
//    Serial.print(h);
//    Serial.print(F("% Temperature: "));
//    Serial.print(t);
//    Serial.print(F("°C "));
//    Serial.print(f);
//    Serial.print(F("°F Heat index: "));
//    Serial.print(hic);
//    Serial.print(F("°C "));
//    Serial.print(hif);
//    Serial.println(F("°F"));
//  }

// Task 1
// #include <Arduino.h>
// #include <Adafruit_Sensor.h> #include
// <DHT.h>
// #define DHTTYPE DHT11 DHT
//     dht(D1, DHTTYPE);
// void setup()
// {
//   // put your setup code here, to run once:
//   Serial.begin(115200);
//   Serial.println("Menggunakan DHT11");
//   dht.begin();
// }
// void loop()
// {
//   // put your main code here, to run repeatedly:
//   delay(2000);
//   float t = dht.readTemperature();
//   if (isnan(t))
//   {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }
//   float k = t + 273.15;
//   float r = 0.8 * t;
//   Serial.print("Temperature : ");
//   Serial.print(t);
//   Serial.print(F("°C || "));
//   Serial.print(k);
//   Serial.print(F("K || "));
//   Serial.print(r);
//   Serial.println(F("°R"));
// }

// Task3
#include <Arduino.h>
#include <Adafruit_Sensor.h> #include
<DHT.h>
#define DHTTYPE DHT11
#define DHTPIN D1
#define RED_LED D6
#define GREEN_LED D7
#define BLUE_LED D5 DHT
    dht(DHTPIN, DHTTYPE);
unsigned long DHT_millis = 0;
char buff[100];
float h = 0, t = 0;
void setup()
{
  Serial.begin(115200);
Serial.println("Tugas Simulasi Pendeteksi Suhu dan Kelembapan
dengan LED");
dht.begin(); pinMode(RED_LED,
OUTPUT); pinMode(GREEN_LED,
OUTPUT); pinMode(BLUE_LED,
OUTPUT);
}
void loop()
{
  // Melakukan pembacaan sensor DHT11 menggunakan millis
  unsigned long DHT_current = millis();
  if (DHT_current -
          DHT_millis >=
      2000)
  {
    DHT_millis = DHT_current;
    h =
        dht.readHumidity();
    t = dht.readTemperature();
    Serial.println("========SCANNING DHT11!========");
  }
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Suhu : ");
  dtostrf(t,
          2, 2, buff);
  Serial.print(buff);
  Serial.print("C || Kelembapan : ");
  dtostrf(h, 2, 2, buff);
  Serial.print(buff); Serial.print("
|| "); if(t < 29) {
Serial.println("Suhu Kota Dingin");
digitalWrite(GREEN_LED, LOW); digitalWrite(RED_LED,
HIGH); digitalWrite(BLUE_LED, HIGH);
}
else if (t >= 29 && t <= 34)
{ Serial.println("Suhu
Kota Normal"); digitalWrite(BLUE_LED, LOW);
digitalWrite(GREEN_LED, HIGH);
digitalWrite(RED_LED, HIGH);
}
else
{
  Serial.println("Suhu Kota Panas");
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED,
               HIGH);
  digitalWrite(GREEN_LED, HIGH);
}
delay(100);
}