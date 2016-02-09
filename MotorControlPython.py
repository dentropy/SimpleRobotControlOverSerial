import serial
port = raw_input("Enter Port Name:")
ser = serial.Serial(port)
while True:
    user_input = raw_input("Enter A Command: ")
    ser.write(user_input)
    if user_input == "quit":
        break
