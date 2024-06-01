import socket
import time
import sys

s = socket.socket()
print("Socket Created")
localhost = socket.gethostname()
IP = socket.gethostbyname(localhost)
s.bind((localhost, 9999))
s.listen(1)
print('Waiting for connection')
c, addr = s.accept()
print('Got connection from ', addr)
while True:
    message = input('Enter Message: ')
    if message == 'bye':
        c.send(message.encode())
        break
    c.send(message.encode())
    message = c.recv(1024)
    message = message.decode()
    print("Message Received: ", message)
s.close()