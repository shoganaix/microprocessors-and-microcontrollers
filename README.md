# Microprocessors and Microcontrollers — UNED

Hands-on work for the **Microprocessors and Microcontrollers** course, part of the
**Industrial Electronics and Automation Engineering** degree at
[UNED](https://www.uned.es) (Universidad Nacional de Educación a Distancia).

This repository collects the practical assignments and laboratory work from the course:
embedded C++ for Arduino, physical computing with Raspberry Pi and Python, and a series
of sensor-and-actuator labs. The focus is low-level hardware interaction, register-level /
GPIO programming and real-time control logic.

| | |
|---|---|
| **Platforms** | Arduino (ATmega), Raspberry Pi |
| **Languages** | C++ (Arduino), Python |
| **Topics** | GPIO, interrupts, PWM, sensors, actuators, serial & I²C, Tinkercad circuit design |

---

## Repository structure

```
.
├── Apuntes/                        # Course study notes (theory + exercises, PDF)
├── PEC1-Arduino/                   # Required assignment: Tinkercad circuits & report
├── PEC1-RaspberryPi/               # Required assignment: Python + GPIO programming
├── PEC2-MP-MC/                     # Final assignment: C++/Arduino + Python/Raspberry Pi
└── Practicas-In4Labs/              # 11 lab exercises (Arduino + sensors) and report
```

---

## PEC1 — Arduino (C++)

Required assignment built as **Tinkercad** circuits. Each project is a self-contained
schematic (`.brd`) with its own report in the assignment PDF.

| Project | What it does |
|---|---|
| `Keypad4x4_Tinker.brd` | 4×4 keypad access control system |
| `LED-RGB_Tinker.brd` | RGB LED control |
| `TrafficLights_Tinker.brd` | LED traffic light system |
| `Alarm_Tinker.brd` | PIR motion detection alarm with keypad disarming |
| `Gas_Tinker.brd` | Gas detection system with multi-level alarm |

**Concepts:** digital I/O, keypad scanning, interrupt-based safety logic, multi-level
alarming, debouncing, circuit design in Tinkercad.

> 📄 `Practica-II-Arduino_MariaSoriano.pdf` — full report.

## PEC1 — Raspberry Pi (Python)

Introduction to Python and GPIO programming with the Raspberry Pi. Code targets the
course emulator (`EmulatorGUI`) and is drop-in compatible with `RPi.GPIO`.

| File | What it does |
|---|---|
| `0_intro_python_solved.py` | Python language fundamentals: types, collections, control flow |
| `1_gpio_test_solved.py` | GPIO setup, pull-up/pull-down inputs, button-driven LED control |

**Concepts:** `GPIO.BCM` numbering, `pinMode` config, pull-up/pull-down resistors,
debounce & edge handling, event-driven logic, `GPIO.cleanup()`.

> 📄 `Practica-I-Raspberry_MariaSoriano.pdf` — full report.

## PEC2 — MP/MC final assignment

Two programs plus a formal report covering both platforms.

| Directory | Program | Behaviour |
|---|---|---|
| `cpp-arduino/` | `C-Arduino_Program.ino` | Blinks an LED for random ON times (200–10 000 ms) seeded from an unconnected analog pin |
| `python-raspberry/` | `Python-Raspberry_Program.ino` | Button press counter driving 5 LEDs; sequential lighting, rising-edge detection, reset after 6 presses |

Each folder includes a wiring/flow diagram (`*_Diagram.png`).

> ⚠️ The `Python-Raspberry_Program.ino` file contains **Python** code — it keeps the
> `.ino` extension as it was submitted for the course.
>
> 📄 `PEC_I_MP-MC_MariaSoriano.pdf` — full report.

---

## Practicas-In4Labs — 11 sensor labs

A practical lab kit of 11 Arduino exercises that progressively cover sensor acquisition,
I²C communication and actuator control. All programs display results on a 16×2 I²C LCD
and the Serial Monitor, and use `millis()`-based timing to keep the loop non-blocking.

| # | Exercise | Sensor / Module |
|---|---|---|
| 01 | `01_ADXL335_Accelerometer` | ADXL335 accelerometer (X, Y, Z) |
| 02 | `02_DHT22_Temperature_Humidity` | DHT22 temperature & humidity |
| 03 | `03_BMP085_Barometer` | BMP085 pressure, temperature & altitude |
| 04 | `04_TTC03_Thermistor_vs_DHT22` | TTC03 thermistor vs. DHT22 (Steinhart–Hart) |
| 05 | `05_GL5528_LightSensor_Servo` | GL5528 light sensor + servo |
| 06 | `06_RFID_RC522_Servo` | RFID RC522 tag reader + servo |
| 07 | `07_PIR_Servo` | PIR motion sensor + servo |
| 08 | `08_Sound_Sensor` | Sound sensor with averaging & threshold |
| 09 | `09_MQ2_GasSensor_Calibration` | MQ2 gas sensor calibration baseline |
| 10 | `10_HC-SR04_Ultrasonic_Distance` | HC-SR04 ultrasonic + servo + LCD |
| 11 | `11_DS1307_RealTimeClock` | DS1307 real-time clock |

> 📄 `In4Labs_MP-MC_MariaSoriano.pdf` — full lab report.
> 📄 `Practica-In4Labs.pdf` — lab statement.

---

## Apuntes (study notes)

Summaries produced during the course:

- `Apuntes MPMC. TeoriaYCodigos.pdf` — theory and code snippets.
- `Apuntes MPMC. Ejercicios.pdf` — worked exercises.

---

## Skills developed

- Embedded systems programming (Arduino C++, Raspberry Pi Python)
- Digital and analog I/O, PWM and signal generation
- Interrupt handling and edge detection
- Serial (UART) and I²C communication
- Sensor integration and conditioning (temperature, pressure, motion, gas, RFID, ultrasonic)
- Actuator control (servo, LED, LCD)
- Circuit design with Tinkercad
- Non-blocking timing with `millis()` / state machines

---

## Author

**María Soriano** — Industrial Electronics and Automation Engineering (UNED).

Repository: [github.com/shoganaix/microprocessors-and-microcontrollers](https://github.com/shoganaix/microprocessors-and-microcontrollers)