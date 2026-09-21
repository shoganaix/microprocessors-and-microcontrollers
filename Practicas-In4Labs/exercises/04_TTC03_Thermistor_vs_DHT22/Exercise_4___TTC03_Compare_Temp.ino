/*
  Exercise 4 - Thermistor TTC03 and DHT22 comparison

  This program reads temperature from TTC03 (thermistor) and DHT22 sensor
  Both values are displayed on both the LCD and SM

  -> The thermistor is an analog sensor, so its reading is converted
  to temperature using the Steinhart-Hart equation

  -> The DHT22 is a digital sensor and directly provides temperature
  in Celsius
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library
#include "DHT.h"                 // DHT sensor library
#include <math.h>                // math library used for logarithm

// thermistor config
#define THERMISTOR_PIN A2

#define R_NOMINAL 10000
#define TEMP_NOMINAL 25
#define B_COEFF 3435
#define R_SERIE 10000

// DHT22 config
#define DHT22_PIN 12
#define DHTTYPE DHT22

DHT dht(DHT22_PIN, DHTTYPE);

// LCD object: address 0x3F, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// timing config
const unsigned long READ_INTERVAL = 2000;
unsigned long previousMillis = 0;

// sensor values
float thermistorTemperature = 0;
float dhtTemperature = 0;

// last displayed values, used to avoid unnecessary LCD refreshes
float lastThermistorTemp = -1000;
float lastDhtTemp = -1000;

void setup()
{
  // init SM
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Init DHT22 sensor
  dht.begin();

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("Temp compare");
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();

  // check if defined time interval has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    // updates last exec time
    previousMillis = currentMillis;

    // check if reading went OK
    if (readSensors())
    {
      printSerial();
      updateLCDIfNeeded();
    }
    else
    {
      handleSensorError();
    }
  }
}

bool readSensors()
{
  // read thermistor temperature
  thermistorTemperature = readThermistorTemperature();

  // read DHT22 temperature in Celsius
  dhtTemperature = dht.readTemperature();

  // DHT22 returns NaN if reading fails
  // Thermistor returns -1000 if analog reading is invalid
  if (isnan(dhtTemperature) || thermistorTemperature == -1000))
  {
    return false;
  }

  return true;
}

float readThermistorTemperature()
{
  // read raw analog value from thermistor
  float signal = analogRead(THERMISTOR_PIN);

  // avoid division by zero (if analog reading = invalid)
  if (signal <= 0)
  {
    return -1000;
  }

  // convert analog signal into resistance using voltage divider formula
  float resistance = (float)(1023 - signal) * R_SERIE / signal;

  // convert resistance into temperature using Steinhart-Hart equation
  float temperature = 1.0 / (log(resistance / R_NOMINAL) / B_COEFF + 1.0 / (TEMP_NOMINAL + 273.15)) - 273.15;

  return temperature;
}

void printSerial()
{
  // print both temperatures to compare sensors
  Serial.print("Thermistor: ");
  Serial.print(thermistorTemperature);
  Serial.print(" C | DHT22: ");
  Serial.print(dhtTemperature);
  Serial.println(" C");
}

void updateLCDIfNeeded()
{
  // update LCD only if values changed
  // -> This reduces flickering and unnecessary refreshes
  if (abs(thermistorTemperature - lastThermistorTemp) >= 0.1 ||
      abs(dhtTemperature - lastDhtTemp) >= 0.1)
  {
    lcd.setCursor(0, 0);
    lcd.print("TTC:");
    lcd.print(thermistorTemperature, 1);
    lcd.print("C   ");

    lcd.setCursor(0, 1);
    lcd.print("DHT:");
    lcd.print(dhtTemperature, 1);
    lcd.print("C   ");

    lastThermistorTemp = thermistorTemperature;
    lastDhtTemp = dhtTemperature;
  }
}

void handleSensorError()
{
  // error message if DHT22 reading fails
  Serial.println("Error: DHT22 reading failed");

  lcd.setCursor(0, 0);
  lcd.print("Sensor error   ");
  lcd.setCursor(0, 1);
  lcd.print("Check DHT22    ");
}