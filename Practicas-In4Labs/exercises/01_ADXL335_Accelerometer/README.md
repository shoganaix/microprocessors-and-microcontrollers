# 01 — ADXL335 Accelerometer

Reads the acceleration of the **X, Y and Z axes** from the ADXL335 accelerometer and
displays the values on an I²C LCD and the Serial Monitor every second.

The LCD is only refreshed when values change, avoiding flicker.

- **Sensor:** ADXL335 (analog, 3-axis)
- **Wiring:** X → A8, Y → A9, Z → A10
- **Key ideas:** analog read, `millis()` non-blocking timing, conditional LCD refresh

File: `Exercise_1___ADXL335_Accelerometer.ino`