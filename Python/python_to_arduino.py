#!/usr/bin/env python3

import serial, time
arduino = serial.Serial('/dev/ttyACM0')  # open serial port

while True:
	print arduino.readline()
	time.sleep(1)
