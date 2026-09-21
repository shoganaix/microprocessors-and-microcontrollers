# 03 — BMP085 Barometer

Reads **temperature and pressure** from the BMP085, converts pressure from Pascals to
atmospheres, computes **altitude** from pressure, and displays everything every 2 s.

- **Sensor:** BMP085 (I²C)
- **Key ideas:** I²C communication, unit conversion (Pa → atm), altitude estimation,
  LCD + Serial output

File: `Exercise_3___BMP085_Barometer.ino`