/*
  Exercise 5 - GL5528 Light sensor and Servo

  This program rotates a servo while reading the light sensor
  If sensor value matches target value-> servo finds light -> servo stops moving

  Current light value is displayed on both the LCD and Serial Monitor
*/

#include <Wire.h>               // I2C communication library
#include <LiquidCrystal_I2C.h>  // LCD display library
#include <Servo.h>              // Servo library

// light sensor config
#define LIGHT_SENSOR_PIN A15

// servo config
#define SERVO_PIN 41

// target value (this must be measured manually before running automatic search)
#define TARGET_LIGHT_VALUE 435
// error range (allowed)
#define TOLERANCE 10      

// LCD object: address 0x3F, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// servo obj
Servo myservo;

// timing config
const unsigned long READ_INTERVAL = 500;
unsigned long previousMillis = 0;

// light variables
int lightValue = 0;
int lastLightValue = -1;

// servo variables
int servoPos = 0;
bool targetReached = false;

void setup()
{
  // init Serial Monitor
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init light
  pinMode(LIGHT_SENSOR_PIN, INPUT);

  // init servo (attached)
  myservo.attach(SERVO_PIN);

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("light search");
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

    // read current light sensor value
    readLight();

    // move servo ONLY while target has not been reached
    if (!targetReached)
    {
      moveServo();
    }

    printSerial();
    updateLCDIfNeeded();
  }
}

// read current light value
void readLight()
{
  lightValue = analogRead(LIGHT_SENSOR_PIN);
}

void moveServo()
{
  // check if current value is close to target
  if (abs(lightValue - TARGET_LIGHT_VALUE) <= TOLERANCE)
  {
    targetReached = true;
    Serial.println("target reached");
    return;
  }

  // move servo step by step
  servoPos++;

  if (servoPos > 180)
  {
    servoPos = 0;
  }

  // send new position to servo
  myservo.write(servoPos);
}

// print on Serial Monitor
void printSerial()
{
  if (targetReached)
  {
    Serial.print("target reached | light: ");
    Serial.print(lightValue);
    Serial.print(" | servo stopped at: ");
    Serial.println(servoPos);
  }
  else
  {
    Serial.print("light value: ");
    Serial.print(lightValue);
    Serial.print(" | servo position: ");
    Serial.println(servoPos);
  }
}

void updateLCDIfNeeded()
{
  // print only if target reached
  if (targetReached)
  {
    lcd.setCursor(0, 0);
    lcd.print("target found    ");
    lcd.setCursor(0, 1);
    lcd.print("servo stopped   ");
    return;
  }

  // update lcd only if light value changes
  if (lightValue != lastLightValue)
  {
    lcd.setCursor(0, 0);
    lcd.print("light:");
    lcd.print(lightValue);
    lcd.print("   ");

    lcd.setCursor(0, 1);
    lcd.print("searching...   ");

    lastLightValue = lightValue;
  }
}