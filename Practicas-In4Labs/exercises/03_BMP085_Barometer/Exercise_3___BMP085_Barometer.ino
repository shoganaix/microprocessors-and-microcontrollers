/*
  Exercise 3 - BMP085 Barometer

  This program reads temperature and pressure from the BMP085 barometer,
  calculates altitude from pressure, converts pressure from Pascals to atm,
  and displays the results on the LCD and Serial Monitor every 2 seconds.
*/

#include <Wire.h>               // I2C communication library
#include <LiquidCrystal_I2C.h>  // LCD display library
#include "BMP085.h"             // BMP085 barometer library

// hardware objects
LiquidCrystal_I2C lcd(0x3F, 16, 2);
BMP085 barometer;

// timing config
const unsigned long READ_INTERVAL = 2000;
unsigned long previousMillis = 0;

// sensor values
float temperature = 0;
float pressurePa = 0;
float pressureAtm = 0;
float altitude = 0;

// last displayed values, used to avoid unnecessary LCD refreshes
float lastPressureAtm = -1000;
float lastAltitude = -1000;

// conversion constant: 1 atmosphere = 101325 Pascals
const float PA_PER_ATM = 101325.0;

void setup()
{
  // init Serial Monitor
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init BMP085 sensor
  barometer.init();

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("BMP085 ready");
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();

  // check if defined time interval has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    // update last execution time
    previousMillis = currentMillis;

    readBarometer();
    printSerial();
    updateLCDIfNeeded();
  }
}

void readBarometer()
{
  // read temperature first.
  // BMP085 library requires temperature reading before calculating pressure.
  temperature = barometer.bmp085GetTemperature(barometer.bmp085ReadUT());

  // read pressure in Pascals from the BMP085 sensor
  pressurePa = barometer.bmp085GetPressure(barometer.bmp085ReadUP());

  // convert pressure from Pascals to atmospheres
  pressureAtm = pressurePa / PA_PER_ATM;

  // estimate altitude based on pressure
  altitude = barometer.calcAltitude(pressurePa);
}

void printSerial()
{
  // print values to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C | Pressure: ");
  Serial.print(pressurePa, 0);
  Serial.print(" Pa | Pressure: ");
  Serial.print(pressureAtm, 4);
  Serial.print(" atm | Altitude: ");
  Serial.print(altitude, 1);
  Serial.println(" m");
}

void updateLCDIfNeeded()
{
  // update LCD only if values have changed enough.
  // -> this reduces flickering and unnecessary refreshes.
  if (abs(pressureAtm - lastPressureAtm) >= 0.0001 ||
      abs(altitude - lastAltitude) >= 0.1)
  {
    lcd.setCursor(0, 0);
    lcd.print("P:");
    lcd.print(pressureAtm, 4);
    lcd.print(" atm  ");

    lcd.setCursor(0, 1);
    lcd.print("Alt:");
    lcd.print(altitude, 1);
    lcd.print(" m   ");

    lastPressureAtm = pressureAtm;
    lastAltitude = altitude;
  }
}