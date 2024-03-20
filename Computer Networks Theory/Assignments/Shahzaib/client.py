import socket
import pickle
import random
import time

class ACK():
    def __init__(self,seqno,notcorrupt):
        self.seqno = seqno
        self.notcorrupt = notcorrupt

class packet():
    def __init__(self,seq_no,data,checksum):
        self.seq_no = seq_no
        self.data = data
        self.checksum = checksum

def addDelay():
    print("Delay Added!\n")
    time.sleep(0.5)

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

def checkChecksum(string, checksum):
    # Calculate the checksum of the string using the same function as the sender
    calculated_checksum = calcChecksum(string)
    
    # Compare the calculated checksum with the received checksum
    if calculated_checksum == checksum:
        return True
    else:
        return False


s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(('localhost',12346))  # Bind to a different port than the client
i=1
prev_packet = -1
while i!=0:
    i=random.randint(1,9)
    packet1,address = s.recvfrom(4096)
    data_variable = pickle.loads(packet1)
    var = checkChecksum(data_variable.data,data_variable.checksum)
    if var == True and prev_packet!=data_variable.seq_no:
        text_file = open('recieveddata.txt','ab')
        text_file.write(data_variable.data + b'\n')
        text_file.close()
    elif var == False:
        print('Corrupted Packet Recieved!\n')
    else:
        print('Duplicate Packet Recieved!\n')
        text_file = open('recieveddata.txt','ab')
        text_file.write(data_variable.data + b' DUPLICATE' + b'\n')
        text_file.close()
    ack = ACK(data_variable.seq_no,checkChecksum(data_variable.data,data_variable.checksum))
    response = pickle.dumps(ack)
    prev_packet = data_variable.seq_no
    if i%3==0:
        addDelay()
    s.sendto(response,address)  # Send response to the client address