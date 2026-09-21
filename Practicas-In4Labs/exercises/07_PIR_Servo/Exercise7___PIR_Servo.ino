/*
  Exercise 7 - PIR motion sensor + servo

  This program moves a servo continuously near the PIR sensor.
  The PIR sensor detects motion and displays the result both on the LCD and SM
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library
#include <Servo.h>               // servo motor library

// pir sensor config
#define PIR_PIN 7

// servo config
#define SERVO_PIN 41

// lcd
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// servo object
Servo myservo;

// timing config
const unsigned long READ_INTERVAL = 300;
unsigned long previousMillis = 0;

// PIR + Servo variables
int pirState = LOW;
int lastPirState = -1;
int servoPos = 0;
int servoDirection = 1;

void setup()
{
  // init Serial communication
  Serial.begin(9600);
  // startup message
  Serial.println("PIR system ready");

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init PIR
  pinMode(PIR_PIN, INPUT);

  // init servo
  myservo.attach(SERVO_PIN);
  myservo.write(servoPos);

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("pir ready");
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

    // read PIR sensor state
    readPIR();
    //move servo continuosuly
    moveServo();
    printSerial();
    updateLCDIfNeeded();
  }
}

void readPIR()
{
  // read PIR digital output
  // -> high means motion detected, low means no motion
  pirState = digitalRead(PIR_PIN);
}

void moveServo()
{
  // move servo back and forth between 0 and 180 degrees
  servoPos += servoDirection;

  // change direction when reaching maximum angle
  if (servoPos >= 180)
  {
    servoPos = 180;
    servoDirection = -1;
  }
  // change direction when reaching min angle
  else if (servoPos <= 0)
  {
    servoPos = 0;
    servoDirection = 1;
  }

  // send new position to servo
  myservo.write(servoPos);
}

void printSerial()
{
  // print motion status and servo position
  Serial.print("pir: ");

  if (pirState == HIGH)
  {
    Serial.print("motion detected");
  }
  else
  {
    Serial.print("no motion");
  }

  Serial.print(" | servo: ");
  Serial.println(servoPos);
}

void updateLCDIfNeeded()
{
  // display PIR status on first LCD row
  lcd.setCursor(0, 0);

  if (pirState == HIGH)
  {
    lcd.print("motion detected ");
  }
  else
  {
    lcd.print("no motion       ");
  }

  // display current servo position on second row
  lcd.setCursor(0, 1);
  lcd.print("servo:");
  lcd.print(servoPos);
  lcd.print("   ");

  lastPirState = pirState;
}