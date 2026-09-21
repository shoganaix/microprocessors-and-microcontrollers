#include <Arduino.h>  // Includes basic Arduino functions and defs

const int LED_PIN = 2;  // Constant storing pin number where LED will be connected

// The setup() function runs once when the board starts
void setup()
{
    pinMode(LED_PIN, OUTPUT);  // Configures LED pin as a digital output
    randomSeed(analogRead(A0));  // Initializes random seed using noise from an unconnected analog pin
}

// The loop() function runs repeatedly in an infinite loop
void loop()
{
    long time_on = random(200, 10001);  // Generates random time between 200 - 10000 ms
    digitalWrite(LED_PIN, HIGH);  // Turns LED ON by setting the pin to HIGH
    delay(time_on);  // Keeps LED ON for time_on ms
    digitalWrite(LED_PIN, LOW);  // Turns LED OFF by setting the pin to LOW
    delay(200);  // Waits 200 ms before next iteration
}

