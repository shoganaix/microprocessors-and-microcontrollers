/*
  Exercise 6 - RFID RC522 and servo

  This program moves the servo to place the RFID tag near the reader.
  Then, reads the RFID tag UID and displays it both on the LCD and Serial Monitor
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library
#include <Servo.h>               // Servo motor library
#include <SPI.h>                 // SPI communication library
#include <MFRC522.h>             // RFID RC522 library

// servo config
#define SERVO_PIN 41
// manual RFID position measured in the lab
#define RFID_POSITION 180

// RFID config
// SS_PIN 53 is used because Arduino Mega uses pin 53 as SPI SS
#define SS_PIN 53
#define RST_PIN 5

// hardware objects
Servo myservo;
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// tag variables
String tagUID = "";
bool tagRead = false;

void setup()
{
  // init Serial communication
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init servo (attached)
  myservo.attach(SERVO_PIN);

  // init RFID communication
  SPI.begin();
  rfid.PCD_Init();

  // move servo to RFID reader pos
  myservo.write(RFID_POSITION);

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("rfid ready");
  lcd.setCursor(0, 1);
  lcd.print("scan tag...");
}

void loop()
{
  // if the tag has already been read, keep the result on screen
  if (tagRead)
  {
    return;
  }

  readRFID();
}

void readRFID()
{
  // check if a new RFID card is present
  if (!rfid.PICC_IsNewCardPresent())
  {
    return;
  }

  // try to read card serial number
  if (!rfid.PICC_ReadCardSerial())
  {
    return;
  }

  tagUID = "";

  // build UID string from card bytes
  for (byte i = 0; i < rfid.uid.size; i++)
  {
    if (rfid.uid.uidByte[i] < 0x10)
    {
      tagUID += "0";
    }

    tagUID += String(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1)
    {
      tagUID += ":";
    }
  }

  // convert UID to uppercase
  tagUID.toUpperCase();

  // mark tag as read
  tagRead = true;

  printSerial();
  updateLCD();

  // stop communication with current card
  rfid.PICC_HaltA();
}

void printSerial()
{
  // print RFID tag uid to Serial Monitor
  Serial.print("rfid tag uid: ");
  Serial.println(tagUID);
}

void updateLCD()
{
  // display UID on LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("tag detected");

  lcd.setCursor(0, 1);
  lcd.print(tagUID);
}