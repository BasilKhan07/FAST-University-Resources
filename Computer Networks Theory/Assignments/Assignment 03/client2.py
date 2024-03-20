from socket import *
import sys,time
import colorama
from colorama import Fore
from functools import partial


def summ(f):  
    carry=0
    ss=[]
    for i in range(0,16,1):
        s=int(f[0][i])+int(f[1][i])+carry
        if s==0:
            ss.append('0')
        elif s==1:
            ss.append('1')
            if carry==1:
                carry=0
        elif s==2:
            ss.append('0')
            carry=1
        elif s==3:
            ss.append('1')
            carry=1
    while(carry!=0):
        for i in range(0,16,1):
            s=int(ss[i])+carry
            if s==int(ss[i]):
                break
            if s==1:
                ss[i]='1'
                if carry==1:
                    carry=0
            if s==2:
                ss[i]='0'
                carry=1
    return ss


def Convert_to_bits(text): 
    ascii_values = []
    flag=0
    for character in text:
        ascii_values.append(ord(character))
    for i in ascii_values:
            f=[]
            while i!=0:
                i=int(i)
                f.append(str(i%2))
                i/=2
                i=int(i)
            f.append('0')
            if flag==0:
                binary_vals=list(f)
                flag=1
            else:
                binary_vals+=f
    return binary_vals

def packet_division(data,packet_size):  
    try:
        packets=[]
        reminder=int(len(data)%packet_size)
        number_of_packets=int(len(data)/packet_size)
        for i in range(number_of_packets):
            packets.append(list(data[(i*packet_size):(packet_size+(packet_size*i))]))
        rem=list(data[(number_of_packets*packet_size):(reminder+(packet_size*number_of_packets))])
        for i in range((5-len(rem))):
            rem.append(' ')
        packets.append(rem)
        return packets
    except Exception as e:
        print("Cant create packets")
        return []


def FirstComplementary(s):  
    for i in range(len(s)):
        if s[i]=='0':
            s[i]='1'
        elif s[i]=='1':
            s[i]='0'
    return s

def calculate_checksum(f):   # Main function to find checksum of a packet
    sum=[['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0']]
    count=0
    for  i in f:
        if len(i)==2:
            sum.append(Convert_to_bits(i))
            count+=1
    if count==2:
        s=list(sum[1:3])
        s=summ(s)
        s=FirstComplementary(s)
        s=''.join(s)
        return(s)
    elif count==1:
        return(''.join(FirstComplementary(sum[1])))
    else:
        return(''.join(FirstComplementary(sum[0])))


def packets_checksum(packets):  
    try:
        s=[]
        Convert_to_bits=[]
        for i in range(len(packets)):
                f=''.join(packets[i])
                s.append(f.split())
                Convert_to_bits.append(calculate_checksum(f.split()))
        return(Convert_to_bits)
    except Exception as e:
        print('cant do it')

def create_packet(packet,Convert_to_bits,seq):
    f=''.join(packet)+'/r'+Convert_to_bits+'/r'+str(seq)
    return(f)

def rdt_send(data,serverName,serverPort,clientSocket):
    packet_size=5 #packet size
    packetss=packet_division(data,packet_size)
    print("\033[1m Number of packets made",int(len(packetss)))
    Convert_to_bits=packets_checksum(packetss)
    sequence_number=0
    for i in range(len(packetss)):
        count=1
        timeoutflag=0
        message=create_packet(packetss[i],Convert_to_bits[i],sequence_number)
        print("\033[96m Sending packet",i+1,"with checksum",str(Convert_to_bits[i]),"and sequence number",sequence_number)
        if sequence_number==1:
            sequence_number=0
        else:
            sequence_number=1
        
        start=0
        start=time.time() 
        clientSocket.sendto(message.encode(),(serverName, serverPort))
        while True:
            try:
                modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
                end=time.time()
                if end-start>0.0008: #timer
                    print("Timeout")
                    if sequence_number==0:
                        print("\033[91m Resending packet",i+1,"with checksum",str(Convert_to_bits[i]),"and sequence number 1")
                    else:
                        print("\033[91m Resending packet",i+1,"with checksum",str(Convert_to_bits[i]),"and sequence number 0")

                        
                    clientSocket.sendto(message.encode(),(serverName, serverPort))
                    start=time.time() 
                    continue

                break
            except Exception as aa:
                count+=1
                if count==1:
                    print("Timeout")
                    timeoutflag=1
                    break
        if timeoutflag==1:
            i-=1
            if sequence_number==1:
                sequence_number=0
            else:
                sequence_number=1
            continue
        modifiedMessage=modifiedMessage.decode()
        modifiedMessage= modifiedMessage.split('/r')
        s=[]
        s.append(list(str(modifiedMessage[1])))
        s.append(list('0100000101001011'))
        ff=summ(s)
        if ('0'  in ff) or (sequence_number==int(modifiedMessage[2])):
            i-=1
            if sequence_number==1:
                sequence_number=0
            else:
                sequence_number=1
        else:
            print("\033[1;32m Acknowledgement of packet with sequence number",modifiedMessage[2],"received")
    message="/r/r"
    clientSocket.sendto(message.encode(),(serverName, serverPort))
    return



serverName = "localhost"
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.setblocking(0)

        
with open ('sending.txt','r') as myfile:
    for line in myfile.readlines():
        rdt_send(line,serverName,serverPort,clientSocket)
print()
print()

clientSocket.close()