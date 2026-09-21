# 10 — HC-SR04 Ultrasonic + Servo

Moves the servo to **0°, 90° and 180°**, measuring distance with the **HC-SR04
ultrasonic sensor** at each position. Results are shown on the I²C LCD and Serial Monitor.

- **Sensor:** HC-SR04 ultrasonic + servo
- **Key ideas:** `pulseIn()` echo timing, distance = time × sound speed / 2, echo timeout,
  servo positioning

File: `Exercise10___HCSR04_Distance.ino`