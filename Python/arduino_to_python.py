#!/usr/bin/env python3

import serial, time
arduino = serial.Serial('/dev/ttyACM0')  # open serial port

while True:
	b = arduino.read() # read a byte
	i = int.from_bytes( b, 'big') # convert it to int
	print( i ) # print to console
	time.sleep(0.1)
