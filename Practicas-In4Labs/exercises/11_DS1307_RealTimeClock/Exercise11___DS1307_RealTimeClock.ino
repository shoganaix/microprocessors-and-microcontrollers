/*
  Exercise 11 - RTC DS1307

  This program reads date and time from DS1307 Real Time Clock (RTC)
  Date and time are displayed on both the LCD and Serial Monitor
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library
#include <I2C_RTC.h>             // RTC library

// LCD object: address 0x3F, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// RTC object
DS1307 rtc;

// timing config
const unsigned long READ_INTERVAL = 1000;
unsigned long previousMillis = 0;

// date and time variables
int dayValue = 0;
int monthValue = 0;
int yearValue = 0;
int hourValue = 0;
int minuteValue = 0;
int secondValue = 0;

void setup()
{
  // init Serial communication
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init RTC
  rtc.begin();

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("RTC DS1307 ready");
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();

  // check if defined time interval has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    //update previous time variable
    previousMillis = currentMillis;

    // read current date and time
    readRTC();

    // print values to Serial Monitor and LCD
    printSerial();
    updateLCD();
  }
}

void readRTC()
{
  // read current date and time from RTC
  dayValue = rtc.getDay();
  monthValue = rtc.getMonth();
  yearValue = rtc.getYear();

  hourValue = rtc.getHours();
  minuteValue = rtc.getMinutes();
  secondValue = rtc.getSeconds();
}

void print2Digits(Print &output, int value)
{
  // print a leading zero if value has only one digit
  if (value < 10)
  {
    output.print("0");
  }

  output.print(value);
}

void printSerial()
{
  // print date to Serial Monitor
  Serial.print("date: ");
  print2Digits(Serial, dayValue);
  Serial.print("/");
  print2Digits(Serial, monthValue);
  Serial.print("/");
  Serial.print(yearValue);

  // print time to Serial Monitor
  Serial.print(" | time: ");
  print2Digits(Serial, hourValue);
  Serial.print(":");
  print2Digits(Serial, minuteValue);
  Serial.print(":");
  print2Digits(Serial, secondValue);
  Serial.println();
}

void updateLCD()
{
  // display date on first row
  lcd.setCursor(0, 0);
  lcd.print("date:");
  print2Digits(lcd, dayValue);
  lcd.print("/");
  print2Digits(lcd, monthValue);
  lcd.print("/");
  lcd.print(yearValue);
  lcd.print(" ");

  // display time on second row
  lcd.setCursor(0, 1);
  lcd.print("time:");
  print2Digits(lcd, hourValue);
  lcd.print(":");
  print2Digits(lcd, minuteValue);
  lcd.print(":");
  print2Digits(lcd, secondValue);
  lcd.print("   ");
}