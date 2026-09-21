# Practicas-In4Labs — Sensor Lab Exercises

A lab kit of **11 Arduino exercises** carried out for *Microprocessors and
Microcontrollers* (UNED). They progressively cover sensor acquisition, I²C communication
and actuator control.

Every program reads a sensor/module, displays the result on a 16×2 I²C LCD and the Serial
Monitor, and uses `millis()`-based timing to avoid blocking the main loop.

## Exercises (`exercises/`)

| # | Folder | Sensor / Module | Behaviour |
|---|---|---|---|
| 01 | `01_ADXL335_Accelerometer` | ADXL335 accelerometer | Reads X, Y, Z acceleration; LCD refresh only on change |
| 02 | `02_DHT22_Temperature_Humidity` | DHT22 | Temperature and humidity every 2 s |
| 03 | `03_BMP085_Barometer` | BMP085 | Pressure, temperature, altitude (Pa → atm) |
| 04 | `04_TTC03_Thermistor_vs_DHT22` | TTC03 + DHT22 | Compares thermistor (Steinhart–Hart) vs. DHT22 |
| 05 | `05_GL5528_LightSensor_Servo` | GL5528 + servo | Servo scans for a target light value |
| 06 | `06_RFID_RC522_Servo` | RFID RC522 + servo | Positions tag, reads and shows its UID |
| 07 | `07_PIR_Servo` | PIR + servo | Continuous servo sweep, motion detection |
| 08 | `08_Sound_Sensor` | Sound sensor | Averaged readings vs. threshold |
| 09 | `09_MQ2_GasSensor_Calibration` | MQ2 | Calibration baseline from clean-air average |
| 10 | `10_HC-SR04_Ultrasonic_Distance` | HC-SR04 + servo | Distance measurement at 0°/90°/180° |
| 11 | `11_DS1307_RealTimeClock` | DS1307 RTC | Date and time via I²C |

## Hardware used

Arduino microcontroller, 16×2 I²C LCD (0x3F), sensors above, servos and basic components.

## Files

- `In4Labs_MP-MC_MariaSoriano.pdf` — full lab report
- `Practica-In4Labs.pdf` — lab statement
- `exercises/` — one `.ino` per exercise