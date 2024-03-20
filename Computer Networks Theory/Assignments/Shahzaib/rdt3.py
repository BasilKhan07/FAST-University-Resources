import socket
import time
import pickle
from functools import partial
import random

address = ('localhost',12345)
max_size = 24
time_limit = 0.3

class ACK():
    def __init__(self,seqno,notcorrupt):
        self.seqno = seqno
        self.notcorrupt = notcorrupt



class packet():
    def __init__(self,seq_no,data,checksum):
        self.seq_no = seq_no
        self.data = data
        self.checksum = checksum

def corruptData(data):
    return data + b'abc'

def calcChecksum(string):
    # Convert the string to bytes
    if isinstance(string, str):
        string = string.encode()
    
    # If the length of the string is odd, add a null byte to the end
    if len(string) % 2 == 1:
        string += b'\x00'
    
    # Initialize the checksum to 0
    checksum = 0
    
    # Iterate over the string two bytes at a time
    for i in range(0, len(string), 2):
        # Get the two bytes
        a = string[i]
        b = string[i+1]
        
        # Combine them into a 16-bit integer
        value = (a << 8) + b
        
        # Add the value to the checksum
        checksum += value
        
        # If the checksum overflows, wrap around and add the carry bit
        if checksum > 0xFFFF:
            checksum = (checksum & 0xFFFF) + 1
    
    # Take the one's complement of the checksum and return it
    return ~checksum & 0xFFFF

 

def rdt_send(data,seqno):
    checksum = calcChecksum(data)
    i = random.randint(0,9)
    P = packet(seqno,data,checksum) #Create Packet
    data_string = pickle.dumps(P)
    sender_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    sender_socket.bind(address)
    sender_socket.sendto(data_string,('localhost',12346))  #request sent         
    start_time = time.time() #start timer
    response , server_address = sender_socket.recvfrom(4096)
    data_variable = pickle.loads(response)
    while True:
        if time.time() - start_time >= time_limit:
            print("Request timed out....\nResending Packet.....\n")
            sender_socket.sendto(data_string,('localhost',12346))   
            start_time = time.time() #restart timer
            response , server_address = sender_socket.recvfrom(4096)
            data_variable = pickle.loads(response) 
        elif data_variable.seqno == seqno and data_variable.notcorrupt == True: #check if ack for correct sequence number is recieved
            print('Packet ',seqno,' sent succesfully!\n')
            break

    sender_socket.close()

i=0    
with open('sendingdata.txt', 'rb') as openfileobject:
    for chunk in iter(partial(openfileobject.read, max_size), b''):
        rdt_send(chunk,i)
        i+=1