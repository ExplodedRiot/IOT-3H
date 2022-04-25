#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
// #include <SimpleDHT.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Network credentials
const char *ssid = "TP-Link_9144";
const char *password = "Tole1234";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// Week Days
String weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
// Month names
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);


#define DHTTYPE DHT11
DHT dht(D1, DHTTYPE); // instan sensor dht11

#define RED_LED D5
#define GREEN_LED D6
#define BLUE_LED D7


String tempNow = "temperature";
String timeNow = "time";

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();
  timeClient.setTimeOffset(25200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  Wire.begin(D2, D3);
  lcd.init();
  lcd.backlight();
}


void getTemp(){

  float c = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(c) || isnan(f))
  {
    lcd.setCursor(0, 0);
    lcd.print("Err Temp");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if(c<20){

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
  }

  else if(c<28){
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
  }

  else if(c>=28){
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }

  tempNow = String(c) + char(0b11011111) + "C " + String(f) + char(0b11011111) + "F";
  Serial.println();
  Serial.print("Celcius Temp      : ");
  Serial.print(c);
  Serial.print(" *C, ");
  Serial.println();
  Serial.print("Fahrenheit Temp   : ");
  Serial.print(f);
  Serial.print(" *F, ");
  Serial.println();
  lcd.setCursor(0, 0);
  lcd.print(tempNow);
}

void getTime(){
  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();
  String formattedTime = timeClient.getFormattedTime();
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentSecond = timeClient.getSeconds();
  String weekDay = weekDays[timeClient.getDay()];
  struct tm *ptm = gmtime((time_t *)&epochTime);
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon + 1;
  String currentMonthName = months[currentMonth - 1];
  int currentYear = ptm->tm_year + 1900;
  String currentDate = String(monthDay) + "-" + String(currentMonth) + "-" + String(currentYear);

  timeNow = currentDate + " " + String(currentHour) + ":" + String(currentMinute);
  Serial.println(timeNow);
  Serial.println("------------------------------------");
  lcd.setCursor(0, 1);
  lcd.print(timeNow);
}

void loop() {
  getTemp();
  getTime();
  delay(3000);
}