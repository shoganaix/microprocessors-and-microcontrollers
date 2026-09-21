import RPi.GPIO as GPIO  # Import library to control Raspberry Pi GPIO pins
import time              # Import time library to handle delays

led_pins = [17, 27, 22, 23, 24]  # List of GPIO pins where LEDs will be connected
button_pin = 5                   # GPIO pin where push button will be connected
press_count = 0                  # Counter to store number of button presses
previous_state = 0               # Variable to store previous button state for edge detection
                                        # edge detection is used to detect changes in a signal

GPIO.setmode(GPIO.BCM)   # Uses BCM numbering (GPIO numbers instead of physical pin numbers)
GPIO.setwarnings(False)  # Disables GPIO warnings !

for led in led_pins:                  # LOOP through all LED pins
    GPIO.setup(led, GPIO.OUT)                # Configures each LED pin as output
    GPIO.output(led, GPIO.LOW)               # Ensures all LEDs start turned OFF

# Configures button as input with pull-down resistor
GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)  

def turn_off_all():                    # FUNCTION to TURN OFF all LEDs
    for led in led_pins:                     # Loops through all LED pins
        GPIO.output(led, GPIO.LOW)           # Sets each LED to LOW (OFF)

def turn_on_one(index):                # FUNCTION to TURN ON LED by index
    turn_off_all()                           # Turns OFF all LEDs
    GPIO.output(led_pins[index], GPIO.HIGH)  # Sets selected by index LED to HIGH (ON)

try:
    while true:                        # INFINITE LOOP      
        current_state = GPIO.input(button_pin)      # Reads current state of button

        if current_state == 1 and previous_state == 0:  # Detects rising edge (LOW (0) → HIGH (1))
            press_count += 1                              # If so, increases press counter
            if press_count == 1:                        # If press counter equals 1 (one pulsation)
                turn_on_one(0)                            # Turns ON LED at GPIO17
            elif press_count == 2:                      # If press counter equals 2 (two pulsations)
                turn_on_one(1)                            # Turns ON LED at GPIO27
            elif press_count == 3:                      # If press counter equals 3 (three pulsations)
                turn_on_one(2)                            # Turns ON LED at GPIO22
            elif press_count == 4:                      # If press counter equals 4 (four pulsations)
                turn_on_one(3)                            # Turns ON LED at GPIO23
            elif press_count == 5:                      # If press counter equals 5 (five pulsations)
                turn_on_one(4)                            # Turns ON LED at GPIO24
            elif press_count == 6:                      # If press counter equals 6 (six pulsations)
                for led in led_pins:                      # Turns ON all LEDs
                    GPIO.output(led, GPIO.HIGH)
                time.sleep(1)                           # Keeps all LEDs ON for 1 second
                turn_off_all()                          # Turns OFF all LEDs
                press_count = 0                         # Resets counter
        previous_state = current_state                  # Updates previous state to current
        time.sleep(0.2)                                 # Waits 200 ms

except KeyboardInterrupt:                           # IMPORTANT! This handles manual interruption (Ctrl+C)
    turn_off_all()                                      # Turns OFF all LEDs before exiting
    GPIO.cleanup()                                      # Resets GPIO configuration to a safe state