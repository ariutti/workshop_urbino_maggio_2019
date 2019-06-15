#!/usr/bin/env python3

import serial, time
arduino = serial.Serial('/dev/ttyACM0')  # open serial port

while True:
	arduino.write(b'P')
	time.sleep(1)
	arduino.write(b'R')
	time.sleep(1)
