/*
  Exercise 10 - Ultrasonic Sensor HC-SR04 + servo

  This program moves the servo to 0, 90 and 180 degrees.
  At each position, reads distance using the HC-SR04 sensor
  and prints the result on both the LCD and Serial Monitor.
*/

#include <Wire.h>               // I2C communication library
#include <LiquidCrystal_I2C.h>  // LCD display library
#include <Servo.h>              // Servo motor library

// ultrasonic sensor configuration
#define TRIG_PIN 9
#define ECHO_PIN 10

// servo config
#define SERVO_PIN 41

// sound speed in cm/us
#define SOUND_SPEED_CM_US 0.0343

// max echo waiting time in microseconds
#define ECHO_TIMEOUT 30000

// LCD object: address 0x3F, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// servo object
Servo myservo;

// servo positions to test
int positions[] = {0, 90, 180};
const int N_POSITIONS = 3;
int currentIndex = 0;

// timing config
const unsigned long READ_INTERVAL = 3000;
unsigned long previousMillis = 0;

// distance value in cm
float distanceCm = 0;

void setup()
{
  // init Serial communication
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // configure ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // init servo
  myservo.attach(SERVO_PIN);

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("ultrasonic");
  lcd.setCursor(0, 1);
  lcd.print("ready");
}

void loop()
{
  // get current time since program started
  unsigned long currentMillis = millis();

  // check if defined time interval has passed
  if (currentMillis - previousMillis >= READ_INTERVAL)
  {
    // update previous execution time
    previousMillis = currentMillis;

    // move servo to current test pos
    moveServoToPosition();

    // read distance at current servo pos
    distanceCm = readDistance();

    // print result to SM & update LCD display
    printSerial();
    updateLCD();

    // move to next test pos
    currentIndex++;

    // restart sequence after last pos
    if (currentIndex >= N_POSITIONS)
    {
      currentIndex = 0;
    }
  }
}

void moveServoToPosition()
{
  // move servo to current test pos
  myservo.write(positions[currentIndex]);

  // wait until servo reaches selected pos
  delay(500);
}

float readDistance()
{
  // sends short trigger pulse to start ultrasonic measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure echo duration in microseconds
  //  -> timeout avoids blocking the program if no echo is received
  long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT);

  // if no echo is received, return 0
  if (duration == 0)
  {
    return 0;
  }

  // convert time into distance in cm
  // distance = (echo time * sound speed) / 2
  float distance = duration * SOUND_SPEED_CM_US / 2;

  return distance;
}

void printSerial()
{
  // print servo angle and measured distance
  Serial.print("servo angle: ");
  Serial.print(positions[currentIndex]);
  Serial.print(" degrees | distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
}

void updateLCD()
{
  // display angle and distance on LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("angle:");
  lcd.print(positions[currentIndex]);

  lcd.setCursor(0, 1);
  lcd.print("dist:");
  lcd.print(distanceCm, 1);
  lcd.print(" cm");
}