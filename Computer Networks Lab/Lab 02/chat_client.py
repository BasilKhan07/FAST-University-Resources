import socket

s = socket.socket()
localhost = socket.gethostname()
IP = socket.gethostbyname(localhost)
s.connect((IP, 9999))
print("Connected..\n")
while True:
    message = s.recv(1024)
    message = message.decode()
    print("Recieved message: ", message)
    message = input("Enter Message: ")
    s.send(message.encode())
s.close()