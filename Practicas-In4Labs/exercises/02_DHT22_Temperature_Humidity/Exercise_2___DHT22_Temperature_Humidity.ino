/*
  Exercise 2 - Temperature & Humidity (DHT22)

  This program reads temperature and humidity values from the DHT22 sensor
  and displays them on the LCD and Serial Monitor every 2 seconds.
*/

#include <Wire.h>               // I2C communication library
#include <LiquidCrystal_I2C.h>  // LCD display library
#include "DHT.h"                // DHT sensor library

// DHT configuration
#define DHT22_PIN 12
#define DHTTYPE DHT22

DHT dht(DHT22_PIN, DHTTYPE);

// LCD (address 0x3F, column 16, row 2)
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// timing (DHT22 NEEDS ~2 seconds between readings) !
const unsigned long READ_INTERVAL = 2000;
// stores last time sensor was read
unsigned long previousMillis = 0;

// dht values
float temperature = 0;
float humidity = 0;

// last values, used to avoid unnecessary LCD refreshes and flickering
//		-> init to -1000 so first reading always triggers an update
float lastTemp = -1000;
float lastHum = -1000;

void setup()
{
  // init Serial communication
  Serial.begin(9600);

  // init the LCD display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init dht
  dht.begin();

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("DHT22 ready");
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();

  // check if defined time interval (2s) has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    // updates last exec time
    previousMillis = currentMillis;

    // if TRUE -> read and display values (update lcd ONLY if values have changed)
    if (readDHT())
    {
      printSerial();
      updateLCDIfNeeded();
    }
    // else -> show error message
    else
    {
      handleSensorError();
    }
  }
}

//returns TRUE (OK) / FALSE (NaN)
bool readDHT()
{
  // reads temperature and humidity
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // validates readings (dht returns NaN if error)
  if (isnan(temperature) || isnan(humidity))
  {
    return false;
  }

  return true;
}

void printSerial()
{
  // print reading to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

void updateLCDIfNeeded()
{
  // ONLY update LCD if values have changed
  // 	-> this avoids flickering
  if (temperature != lastTemp || humidity != lastHum)
  // floats can vary slightly so we can use some margin for better comparison
  // if (abs(temperature - lastTemp) >= 0.1 || abs(humidity - lastHum) >= 0.1)
  {
    // clears previous values
    lcd.clear();

    // displays temperature (first row)
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(temperature);
    lcd.print("C");

    // displays humidity (second row)
    lcd.setCursor(0, 1);
    lcd.print("Hum:");
    lcd.print(humidity);
    lcd.print("%");

    // stores current values
    lastTemp = temperature;
    lastHum = humidity;
  }
}

// Handle sensor error
void handleSensorError()
{
  // debug message: dht reading error
  Serial.println("Error: DHT22 reading failed");

  // clears previous values
  lcd.clear();
  // displays msg "Sensor error" (first row)
  lcd.setCursor(0, 0);
  lcd.print("Sensor error");
  // displays msg "Check DHT22" (second row)
  lcd.setCursor(0, 1);
  lcd.print("Check DHT22");
}