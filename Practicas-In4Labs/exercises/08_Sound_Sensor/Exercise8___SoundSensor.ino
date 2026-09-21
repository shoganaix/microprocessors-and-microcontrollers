/*
  Exercise 8 - Sound sensor

  This program reads the sound sensor several times, calculates
  the average value, and compares it with a defined threshold.

  -> The average sound value and sound status are displayed on
  the LCD and Serial Monitor.
*/

#include <Wire.h>                // I2C communication library
#include <LiquidCrystal_I2C.h>   // LCD display library

// analog input pin used to read the sound sensor signal
#define SOUND_SENSOR_PIN A0
// sound threshold used to classify sound level
#define SOUND_THRESHOLD 500
// number of samples used to calculate the average value
#define N_SAMPLES 10

// LCD object: address 0x3F, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// timing config
const unsigned long READ_INTERVAL = 1000;
unsigned long previousMillis = 0;

// sound variables
int soundAverage = 0;
int lastSoundAverage = -1;
bool soundDetected = false;

void setup()
{
  // init Serial communication
  Serial.begin(9600);

  // init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // init sound sensor
  pinMode(SOUND_SENSOR_PIN, INPUT);

  // startup message
  lcd.setCursor(0, 0);
  lcd.print("sound ready");
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

    // read average sound value
    readSoundAverage();
    // compare average value with threshold
    compareWithThreshold();
    printSerial();
    updateLCDIfNeeded();
  }
}

// read the sound sensor N_SAMPLES times and calculate the average value
void readSoundAverage()
{
  
  long sum = 0;

  for (int i = 0; i < N_SAMPLES; i++)
  {
    sum += analogRead(SOUND_SENSOR_PIN);
  }

  // calculate average value
  soundAverage = sum / N_SAMPLES;
}

void compareWithThreshold()
{
  // compare average value with threshold
  // >= threshold -> high sound detected
  if (soundAverage >= SOUND_THRESHOLD)
  {
    soundDetected = true;
  }
  else
  {
    soundDetected = false;
  }
}

void printSerial()
{
  // print average value and sound status to SM
  Serial.print("sound average: ");
  Serial.print(soundAverage);
  Serial.print(" | status: ");

  if (soundDetected)
  {
    Serial.println("high sound");
  }
  else
  {
    Serial.println("low sound");
  }
}

void updateLCDIfNeeded()
{
  // update LCD only if sound average changes
  if (soundAverage != lastSoundAverage)
  {
    lcd.setCursor(0, 0);
    lcd.print("avg:");
    lcd.print(soundAverage);
    lcd.print("   ");

    // display sound status
    lcd.setCursor(0, 1);

    if (soundDetected)
    {
      lcd.print("high sound      ");
    }
    else
    {
      lcd.print("low sound       ");
    }

    // store last displayed value
    lastSoundAverage = soundAverage;
  }
}
