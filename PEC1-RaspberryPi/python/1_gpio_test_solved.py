
'''
---------------------------------------------------------------------------------
This script configures GPIO pins and continuously checks if any pins / buttons
have been pressed
- OUTPUT pins can be turned on or off
- INPUT pins read wether there is a signal or not

So:

· Pressing GPIO23 → turns on GPIO4 and GPIO17

· Pressing GPIO15 → turns on GPIO18 and GPIO21

· Pressing GPIO24 → turns off GPIO18 and GPIO21

· Pressing GPIO26 → turns off GPIO4 and GPIO17
---------------------------------------------------------------------------------
'''

# imports GPIO module from Emulator Script
from EmulatorGUI import GPIO

# real Raspberry Pi GPIO library (commented out)
#import RPi.GPIO as GPIO

# delays like time.sleep()
import time
# prints detailed error information
import traceback
# used to make HTTP requests (GET POST DELETE...)
import requests

# defines main
def Main():
    try:
        # sets GPIO numbering mode to BCM
        #       meaning pins are referenced by their Broadcom GPIO numbers
        GPIO.setmode(GPIO.BCM)
        # disables GPIO warning messages.
        GPIO.setwarnings(False)
 
        # sets GPIO4 as output pin
        GPIO.setup(4, GPIO.OUT)
        # sets GPIO17,18,2 as output and its initial value to LOW (0) - GND
        GPIO.setup(17, GPIO.OUT, initial = GPIO.LOW)
        GPIO.setup(18, GPIO.OUT, initial = GPIO.LOW)
        #GPIO.setup(21, GPIO.OUT, initial = GPIO.LOW)
        GPIO.setup(2, GPIO.OUT, initial=GPIO.LOW)

        # sets GPIO23, GPIO27 as input with an internal pull-up resistor
            # meaning HIGH by default, LOW when activated
        GPIO.setup(23, GPIO.IN, pull_up_down = GPIO.PUD_UP)
        GPIO.setup(27, GPIO.IN, pull_up_down = GPIO.PUD_UP)

        # sets GPIO15, GPIO24 as input with an internal pull-down resistor
            # meaning LOW by default, HIGH when activated
        GPIO.setup(15, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)
        GPIO.setup(24, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)
        # sets GPI26 as input pin
        GPIO.setup(26, GPIO.IN)
 
        while(True):

            # checks if GPIO23 is LOW 
                # 23 uses pull-up, low means input has been activated
            if (GPIO.input(23) == False):
                # Debug print
                print("GPIO23 activated → Turning ON GPIO4 and GPIO17")
                # Sets 4 and 17 to HIGH (turn on)
                GPIO.output(4,GPIO.HIGH)
                GPIO.output(17,GPIO.HIGH)
                # 10 sec delay
                time.sleep(10)
 
            # checks if GPIO15 is HIGH
                # 15 uses pull-down, high means input has been activated
            if (GPIO.input(15) == True):
                # Debug print
                print("GPIO15 activated → Turning ON GPIO18 and GPIO2")
                # Sets 18 and 2 to HIGH (turn on)
                GPIO.output(18,GPIO.HIGH)
                GPIO.output(2,GPIO.HIGH)
                time.sleep(1)
 
            # checks if GPIO24 is HIGH
                # 24 uses pull-down, high means input has been activated           
            if (GPIO.input(24) == True):
                # Debug print
                print("GPIO24 activated → Turning OFF GPIO18 and GPIO2")
                # Sets 18 and 2 to LOW (turn off)
                GPIO.output(18,GPIO.LOW)
                GPIO.output(2,GPIO.LOW)
                time.sleep(1)
 
            # checks if GPIO26 is HIGH
                # 26 is configured as input (no pull-up-down), high means input has been activated
            if (GPIO.input(26) == True):
                # Debug print
                print("GPIO26 activated → Turning OFF GPIO4 and GPIO17")
                # Sets 4 and 17 to LOW (turn off)
                GPIO.output(4,GPIO.LOW)
                GPIO.output(17,GPIO.LOW)
                time.sleep(1)

            # checks if GPIO27 is LOW
                # 27 uses pull-up, low means input has been activated        
            if GPIO.input(27) == False:
                # Debug print
                print("GPIO está bajo")
                # Sets 2 to HIGH (turn on)
                GPIO.output(2, GPIO.HIGH)
                time.sleep(2)
                # Sets 2 to LOW (turn off)
                GPIO.output(2, GPIO.LOW)
 
    except Exception as ex:
        # prints error traceback when exception
        traceback.print_exc()
        
    # IMPORTANT! This block always runs, whether error or not
    finally:
        # ensures clean exit (cleans up GPIO conf)
        GPIO.cleanup() 

# Calls main
Main()


''' 
---------------------------------------------------------------------------------
                                NOTES
---------------------------------------------------------------------------------
              ◉ What's GPIO? (General Purpose Input / Output)
PINS that serve as input (button, sensor...) and/or output (led, motor...)          
                        
                        ◉ How to use request:

import requests

response = requests.get("https://api.github.com")

print(response.status_code)     # 200
print(response.text)            # page content


                     ◉ What is a pull_up_down resistor:
Pull-up and pull-down resistors ensure Raspberry Pi GPIO pins read a 
stable high (1) or low (0) state, preventing "floating" (unpredictable) inputs
when a button or sensor is open. 

A pull-up connects the pin to 3V (default HIGH), while a pull-down connects it to
Ground (default LOW)
'''