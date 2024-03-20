import os,sys,socket,time
import _thread as thread

     
MAX = 999999999 
DEBUG = True    
#BLOCKED = [b'www.neverssl.com',b'neverssl.com']   
BLOCKED = []      

def main():

    if (len(sys.argv)<2):
        print ("No port given")
        port = 12345
    else:
        port = int(sys.argv[1]) 


    host = ''               
    
    print ("Proxy Server Running on ",host,":",port)

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        s.bind((host, port))
        s.listen(150)
    
    except socket.error as e:
        if s:
            s.close()
        print ("Could not open socket:", e.errno)
        sys.exit(1)

    while 1:
        conn, client_addr = s.accept()

        thread.start_new_thread(proxy, (conn, client_addr))
        
    s.close()

def writetofile(type,request,address):
    cache={}
    a=address[0]
    if str(request) not in cache.keys():
        cache[str(request)]=1
        file2 = open("cachemiss.txt", "a") 
        file2.write(' cache miss '+ str(request)+ "\n")
        file2.close()
    file1 = open("myfile.txt", "a")  # append mode
    file1.write(type+" ")     
    file1.write(str(request)+ str(address[0]))
    file1.write("\n")
    file1.close()

def proxy(conn, client_addr):

    request = conn.recv(MAX)
    first_line = request.split(b'\n')[0]

    url = first_line.split(b' ')[1]
    for i in range(0,len(BLOCKED)):
        if BLOCKED[i] in url:
            writetofile("Blacklisted",first_line,client_addr)
            conn.close()
            sys.exit(1)

    writetofile("Request",first_line,client_addr)
    
    http_pos = url.find(b'://')        
    if (http_pos==-1):
        temp = url
    else:
        temp = url[(http_pos+3):]  
    
    port_pos = temp.find(b':')     

    webserver_pos = temp.find(b'/')
    if webserver_pos == -1:
        webserver_pos = len(temp)

    
    port = -1
    if (port_pos==-1 or webserver_pos < port_pos):    
        port = 80
        webserver = temp[:webserver_pos]
    else:    
        port = int((temp[(port_pos+1):])[:webserver_pos-port_pos-1])
        webserver = temp[:port_pos]

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
        s.connect((webserver, port))
        s.send(request)       
        
        while 1:
            data=b''
            data = s.recv(MAX)
            if (len(data) > 0):
                conn.send(data)
            else:
                break
        s.close()
        conn.close()
    except (socket.error):
        if s:
            s.close()
        if conn:
            conn.close()
        sys.exit(1)

main()

