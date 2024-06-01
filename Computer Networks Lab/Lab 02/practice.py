import socket

hostname = socket.gethostname()
print(hostname)
IP_Address = socket.gethostbyname(hostname)
print(IP_Address)

x = socket.gethostbyaddr('172.217.18.142')
print(x)