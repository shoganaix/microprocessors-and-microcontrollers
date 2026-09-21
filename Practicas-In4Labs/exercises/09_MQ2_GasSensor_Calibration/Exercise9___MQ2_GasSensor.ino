/*
  Exercise 9 - MQ2 Gas sensor calibration

  This program simulates the calibration process of the MQ2 gas sensor
  
  It reads several analog values in clean air, calculates the average,
  and uses that value as a reference baseline.

  This baseline can later be used to define a detection threshold.
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library

// MQ2 sensor config
#define MQ2_PIN A1
#define N_SAMPLES 20
#define THRESHOLD_OFFSET 100

// LCD object: address 0x3F, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// timing configuration
const unsigned long READ_INTERVAL = 1000;
unsigned long previousMillis = 0;

// gas variables
int baseline = 0;
int threshold = 0;
int gasValue = 0;
int lastGasValue = -1;

void setup()
{
  // init Serial communication
  Serial.begin(9600);
  Serial.println("MQ2 calibration started");

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init MQ2
  pinMode(MQ2_PIN, INPUT);
  lcd.setCursor(0, 0);
  // debug
  lcd.print("mq2 calibrating");
  
  // calibrate MQ2 sensor in clean air
  calibrateMQ2();

  // show calibration result on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("baseline:");
  lcd.print(baseline);

  lcd.setCursor(0, 1);
  lcd.print("th:");
  lcd.print(threshold);
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();
  // check if defined time interval has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    // Update previous execution time
    previousMillis = currentMillis;

    // Read current gas sensor value
    readGas();

    // Print values to Serial Monitor
    printSerial();

    // Update LCD display
    updateLCDIfNeeded();
  }
}

void calibrateMQ2()
{
  long sum = 0;

  // take several readings in clean air
  for (int i = 0; i < N_SAMPLES; i++)
  {
    int value = analogRead(MQ2_PIN);
    sum += value;

    Serial.print("calibration sample ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(value);

    delay(200);
  }

  // calculate clean air baseline
  baseline = sum / N_SAMPLES;

  // define a threshold above the baseline
  threshold = baseline + THRESHOLD_OFFSET;

  Serial.print("baseline: ");
  Serial.println(baseline);

  Serial.print("threshold: ");
  Serial.println(threshold);
}
void readGas()
{
  // read current MQ2 analog value
  gasValue = analogRead(MQ2_PIN);
}

void printSerial()
{
  // print gas value and threshold to Serial Monitor
  Serial.print("gas value: ");
  Serial.print(gasValue);
  Serial.print(" | threshold: ");
  Serial.print(threshold);
  Serial.print(" | status: ");

  if (gasValue > threshold)
  {
    Serial.println("gas detected");
  }
  else
  {
    Serial.println("normal air");
  }
}

void updateLCDIfNeeded()
{
  // update LCD only if gas value changes
  if (gasValue != lastGasValue)
  {
    lcd.setCursor(0, 0);
    lcd.print("gas:");
    lcd.print(gasValue);
    lcd.print("   ");

    lcd.setCursor(0, 1);

    if (gasValue > threshold)
    {
      lcd.print("gas detected   ");
    }
    else
    {
      lcd.print("normal air     ");
    }

    lastGasValue = gasValue;
  }
}
