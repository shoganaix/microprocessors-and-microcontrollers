/*
  Exercise 1 - ADXL335 Accelerometer

  This program reads the acceleration values from the X, Y and Z axes
  using the ADXL335 accelerometer. The values are displayed on the LCD
  screen and printed to the Serial Monitor every second.

  The code uses functions to keep the program organized and millis()
  instead of delay() to avoid blocking the main loop
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library
#include "ADXL335.h"             // ADXL335 accelerometer library

// accelerometer pins
#define X_AXIS_PIN A8
#define Y_AXIS_PIN A9
#define Z_AXIS_PIN A10

// hardware objects: accelerometer and lcd
ADXL335 accelerometer;
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// time interval (in milliseconds) between sensor readings
const unsigned long READ_INTERVAL = 1000;
// stores last time sensor was read
unsigned long previousMillis = 0;

// accelerometer readings
int x = 0;
int y = 0;
int z = 0;

// last displayed values, used to avoid unnecessary LCD refreshes
//		-> init to -1 so first real reading always triggers an update
int lastX = -1;
int lastY = -1;
int lastZ = -1;

void setup()
{
  // init Serial communication
  Serial.begin(9600);

  // init the LCD display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init accelerometer
  accelerometer.begin();

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("ADXL335 ready");
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();

  // check if defined time interval has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    // update last exec time
    previousMillis = currentMillis;

    // read and display acceleration values (update lcd ONLY if values have changed)
    readAccelerometer();
    printSerial();
    updateLCDIfNeeded();
  }
}

void readAccelerometer()
{
  // reads values from axes
  accelerometer.getXYZ(&x, &y, &z);
}

void printSerial()
{
  // prints readings to Serial Monitor
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" | Y: ");
  Serial.print(y);
  Serial.print(" | Z: ");
  Serial.println(z);
}

void updateLCDIfNeeded()
{
  // ONLY update the LCD if values have changed
  // 	-> this avoids flickering
  if (x != lastX || y != lastY || z != lastZ)
  {
    // clears previous values
    lcd.clear();

    // displays x (first row)
    lcd.setCursor(0, 0);
    lcd.print("X:");
    lcd.print(x);
    
    // displays y (first row, right side)
    // 		-> left side: columns 0–7
	  //	    -> right side: columns 8–15
    lcd.setCursor(8, 0);
    lcd.print("Y:");
    lcd.print(y);

    // displays z (second row)
    lcd.setCursor(0, 1);
    lcd.print("Z:");
    lcd.print(z);

    // stores current values
    lastX = x;
    lastY = y;
    lastZ = z;
  }
}