# Voltage Measurement using INA226 and ESP32

## This project demonstrates how to measure voltage using an INA226 current/voltage sensor and an ESP32 microcontroller. The measured voltage is then displayed on an I2C LCD display.

## Hardware
- INA226 current/voltage sensor
- ESP32 microcontroller
- I2C LCD display

## Software
- Arduino IDE (or other ESP32 development environment)
- INA226 library for Arduino.

## Setup

### Connect the INA226 sensor to the ESP32 according to the wiring diagram below.
- SDA -> ESP32 SDA
- SCL -> ESP32 SCL
- VCC -> 3.3V
- GND -> GND

### INA226 Internal Connections
- VBUS -> IN+
- GND ->  IN-

### Connect the I2C LCD display to the ESP32 according to the wiring diagram below.
- SDA -> ESP32 SDA
- SCL -> ESP32 SCL
- VCC -> 3.3V
- GND -> GND

### Install the INA226 library for Arduino by going to Sketch > Include Library > Manage Libraries in the Arduino IDE.

Open the Arduino IDE and create a new sketch.

Copy and paste the [code](Voltage.ino) into the sketch, and upload it to the ESP32.

## Usage
Once the code is uploaded to the ESP32, the measured voltage should be displayed on the LCD display. The voltage will be updated every loop iteration.
