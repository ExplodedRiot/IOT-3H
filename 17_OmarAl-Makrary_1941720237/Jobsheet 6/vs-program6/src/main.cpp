#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define RED_LED D5
#define GREEN_LED D6
#define BLUE_LED D7

#define sensorLDR D0
int lightIntensity;

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

#define DHTType DHT11
DHT dht(D1, DHTType);
String tempNow = "temp";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
String timeNow = "time";
String weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const char *ssid = "P.TRIS";
const char *password = "mahmuditri";
const uint16_t port = 3000;
const char *host = "192.168.100.12";

WiFiClient client;

void connect_wifi()
{
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  delay(250);
}

void connect_server()
{
  while (!client.connect(host, port))
  {
    Serial.printf("\n[Connecting to %s ... ", host);
    delay(1000);
    return;
  }
  Serial.println("connected]");
  delay(1000);
}

void setup()
{
  Serial.begin(9600);

  Wire.begin(D2, D3);
  lcd.init();
  lcd.backlight();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  connect_wifi();
  connect_server();

  timeClient.begin();
  timeClient.setTimeOffset(25200);

  delay(3000);
}

void getTemp()
{
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(t) || isnan(f))
  {
    lcd.setCursor(0, 1);
    lcd.print("Err Temp");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  tempNow = String(t) + char(0b11011111) + "C " + String(f) + char(0b11011111) + "F";
  Serial.println(tempNow);
  lcd.setCursor(0, 1);
  lcd.print(tempNow);
}

void getTime()
{
  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();
  String formattedTime = timeClient.getFormattedTime();
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  // int currentSecond = timeClient.getSeconds();
  String weekDay = weekDays[timeClient.getDay()];
  struct tm *ptm = gmtime((time_t *)&epochTime);
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon + 1;
  String currentMonthName = months[currentMonth - 1];
  int currentYear = ptm->tm_year + 1900;
  String currentDate = String(monthDay) + "-" + String(currentMonth) + "-" + String(currentYear);

  timeNow = currentDate + " " + String(currentHour) + ":" + String(currentMinute);
  Serial.println(timeNow);
  lcd.setCursor(0, 1);
  lcd.print(timeNow);
}

void getLightIntensity()
{
  lightIntensity = analogRead(sensorLDR);
  lcd.setCursor(0, 1);
  if (lightIntensity == 0)
  {
    lcd.print("Bright Light:Day");
  }
  else
  {
    lcd.print("Dim Light:Night");
  }
}
void allLedOff(String message)
{
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void allLedOn(String message)
{
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void redLightOn(String message)
{
  digitalWrite(RED_LED, LOW);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void redLightOff(String message)
{
  digitalWrite(RED_LED, HIGH);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void greenLightOn(String message)
{
  digitalWrite(GREEN_LED, LOW);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void greenLightOff(String message)
{
  digitalWrite(GREEN_LED, HIGH);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void blueLightOn(String message)
{
  digitalWrite(BLUE_LED, LOW);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void blueLightOff(String message)
{
  digitalWrite(BLUE_LED, HIGH);
  lcd.setCursor(0, 1);
  lcd.print(message);
}
void loop()
{
  delay(1000);
  if (client.connected())
  {
    Serial.print("[Response:]");
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line.equalsIgnoreCase("temp"))
    {
      lcd.clear();
      getTemp();
    }
    else if (line.equalsIgnoreCase("time"))
    {
      lcd.clear();
      getTime();
    }
    else if (line.equalsIgnoreCase("light"))
    {
      lcd.clear();
      getLightIntensity();
    }
    else if (line.equalsIgnoreCase("led off"))
    {
      lcd.clear();
      allLedOff("Shut down LEDs");
    }
    else if (line.equalsIgnoreCase("led on"))
    {
      lcd.clear();
      allLedOn("Turn on LEDs");
    }
    else if (line.equalsIgnoreCase("red on"))
    {
      lcd.clear();
      redLightOn("Red LED On");
    }
    else if (line.equalsIgnoreCase("red off"))
    {
      lcd.clear();
      redLightOff("Red LED Off");
    }
    else if (line.equalsIgnoreCase("green on"))
    {
      lcd.clear();
      greenLightOn("Green LED On");
    }
    else if (line.equalsIgnoreCase("green off"))
    {
      lcd.clear();
      greenLightOff("Green LED Off");
    }
    else if (line.equalsIgnoreCase("blue on"))
    {
      lcd.clear();
      blueLightOn("Blue LED On");
    }
    else if (line.equalsIgnoreCase("blue off"))
    {
      lcd.clear();
      blueLightOff("Blue LED Off");
    }
    else if (line.equalsIgnoreCase("clear screen"))
    {
      lcd.clear();
    }
  }
  else
  {
    connect_server();
  }
  delay(250);
}