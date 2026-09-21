# PEC1 — Raspberry Pi (Python)

Required assignment for *Microprocessors and Microcontrollers* (UNED): introduction to
Python and GPIO programming on the Raspberry Pi.

## Python scripts (`python/`)

| File | What it does |
|---|---|
| `0_intro_python_solved.py` | Python language fundamentals: variables, types, collections, loops, conditionals, dictionaries |
| `1_gpio_test_solved.py` | GPIO configuration and button-driven LED control (pull-up / pull-down inputs) |

The scripts use the course emulator (`EmulatorGUI`, in `python/rpi/`) and are compatible
with the real `RPi.GPIO` library.

## Concepts covered

- `GPIO.BCM` pin numbering
- Input/output setup (`GPIO.setup`)
- Internal pull-up / pull-down resistors
- Rising-edge / state detection
- Event-driven control logic
- Clean shutdown with `GPIO.cleanup()`

## Files

- `Practica-I-Raspberry_MariaSoriano.pdf` — full report
- `Enunciado_Practica-I-Raspberry_MariaSoriano.pdf` — course statement
- `python/rpi/` — emulator used during development