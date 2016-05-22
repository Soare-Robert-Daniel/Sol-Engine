import socket               # Import socket module
import time
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # Create a socket object
host = socket.gethostname()  # Get local machine name
port = 52000               # Reserve a port for your service.
name = str(raw_input())
date = ""
s.connect((host, port))  # Connect to server
if name is not "ok":
    date = name
try:
    while True:
        if date:
            s.send(date)
        date = s.recv(1024)
        if date:
            print date
        time.sleep(1)            # Delay
except Exception as e:
    print(e)
s.close  # Close the socket when done

