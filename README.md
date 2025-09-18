# I2C Communication System

## Overview
This project implements an I2C bus communication system using the TM4C123 LaunchPad microcontroller to interface with several external I2C components: a TCS34725 RGB Color Sensor, MPU6050 gyroscope, a servo motor, and a 16x2 LCD display. The system demonstrates real-time sensor data acquisition, servo control, and live feedback display using I2C communication.

## Features
- LED color cycling through 8 colors (Red, Green, Blue, Yellow, Cyan, Purple, White, Dark) controlled by a switch.
- UART communication at 57600 baud for system status and debugging.
- I2C master-slave communication with:
  - TCS34725 RGB Color Sensor for color detection and classification.
  - MPU6050 gyroscope/accelerometer for motion sensing and orientation data.
  - Servo motor controlled via PWM for precise angular positioning.
  - 16x2 LCD display for real-time data visualization including sensor readings and system status.
- Calibration and filtering algorithms for accurate sensor data processing.
- Real-time dynamic updates on the LCD display.

## Hardware Components
- TM4C123 LaunchPad microcontroller
- TCS34725 RGB Color Sensor
- MPU6050 Gyroscope and Accelerometer
- Micro Servo Motor
- 16x2 LCD Display module
- Breadboard and two 4.7k Ohm resistors for I2C pull-ups

## Software Implementation
- I2C master role implemented on TM4C123 with proper initialization, data transmission, and reception.
- Error checking and timing management for reliable I2C communication.
- Sensor calibration routine for the RGB sensor.
- MPU6050 data filtering to compute meaningful orientation and acceleration.
- PWM signal generation for smooth servo motor control.
- LCD driver for text formatting, custom characters, and live data updates.
- UART interface for debugging.

## Usage Instructions
1. Power and connect the TM4C123 LaunchPad to the sensor modules, servo motor, and LCD using the breadboard.
2. Use the onboard switches to cycle LED colors and control modes.
3. Observe sensor data displayed on the LCD in real-time.
4. The servo motor position adjusts programmatically based on sensor inputs or commands.
5. Debug output available via UART over serial terminal.

## Challenges and Lessons Learned
- Integrating multiple I2C devices with distinct protocols and timing requirements.
- Achieving accurate color detection with the TCS34725 sensor despite environmental factors.
- Handling data filtering and conversion for MPU6050 gyroscope measurements, overcoming issues with persistent errors in Z-axis calculations.
- Implementing reliable PWM control for smooth servo movement.
- Coordinating real-time sensor input processing with live LCD display updates and UART communication.

## Contributors
- Jonathan Cerniaz
- Joseph Guzman
- Afzal Hakim
- Robby Rimal

