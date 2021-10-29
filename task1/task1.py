import serial

ser = serial.Serial('COM4', baudrate = 9600)

while 1:
    ser.write(b'f')
