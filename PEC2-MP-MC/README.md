# PEC2 — MP/MC Final Assignment

Final required assignment for *Microprocessors and Microcontrollers* (UNED) covering both
platforms used in the course.

## `cpp-arduino/`

Random blink program for an Arduino board.

- `C-Arduino_Program.ino` — blinks an LED with a random ON time between 200–10 000 ms;
  the random seed is taken from noise on an unconnected analog pin.
- `C++Arduino_Diagram.png` — wiring / flow diagram.

## `python-raspberry/`

Push-button LED counter for the Raspberry Pi.

- `Python-Raspberry_Program.ino` — a button press counter that lights one of 5 LEDs per
  press (rising-edge detection with `GPIO.PUD_DOWN`); after the 6th press all LEDs flash
  and the counter resets.
  > This file contains **Python** code and keeps the `.ino` extension as it was submitted
  > for the course.
- `Python-Raspberry_Diagram.png` — wiring / flow diagram.

## Files

- `PEC_I_MP-MC_MariaSoriano.pdf` — full report
- `Enunciado_PEC_MP-MC.pdf` — course statement