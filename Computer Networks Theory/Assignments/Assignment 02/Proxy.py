import socket, sys, _thread, traceback, ssl, os

filterList = ['example.com', 'www.example.com']
def main():
    global clientPort, buffer
    try:
        clientPort = int(input("Enter client port: "))
    except KeyboardInterrupt:
        sys.exit(0)

    buffer = 4096
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind(("", clientPort))
        s.listen(32)

        print("\nSocket binded at port: [{}]".format(clientPort))
    except Exception as error:
        pass
        sys.exit(2)

    while True:
        try:
            c, addr = s.accept()
            rawData = c.recv(buffer)
            _thread.start_new_thread(extractUrl, (c, rawData, addr))
        except KeyboardInterrupt:
            s.close()
            print("\nConnection acceptance failed\nClosing proxy system...")
            sys.exit(1)

def extractUrl(c, rawData, addr):
    try:
        rawInput = rawData.decode('latin-1').split("\n")[0]
        url = rawInput.split(" ")[1]
        file_name = rawInput.split(" ")
        file_name = file_name[1]
        file_name = file_name.replace(".", "_").replace("http://", "_").replace("/", "")

        httpPos = url.find("://")
        if httpPos == -1:
            nonHttp = url
        else:
            nonHttp = url[(httpPos + 3):]

        portPos = nonHttp.find(":")
        siteLimit = nonHttp.find("/")
        if siteLimit == -1:
            siteLimit = len(nonHttp)
        globalHost = ""
        port = -1
        if portPos == -1 or siteLimit < portPos:
            port = 80
            globalHost = nonHttp[:siteLimit]
        else:
            port = int(nonHttp[(portPos + 1):][:siteLimit - portPos - 1])
            globalHost = nonHttp[:portPos]

        print(globalHost)
        if globalHost in filterList:
            return
        filter_list(c, addr, globalHost)
        proxyServer(globalHost, port, c, rawData, addr, file_name)
    except Exception as error:
        pass

def filter_list(c, ip, domain):
    print("globalhost = " + domain)
    with open('blacklist/ip', 'rb') as handle:
        for line in handle.readlines():
            if line.decode().strip() == domain.strip():
                print("Ip is blacklisted.")
                c.close()
                sys.exit(1)

    with open('blacklist/domain', 'rb') as handle:
        for line in handle.readlines():
            if line.decode().strip() == domain.strip():
                print("Domain is blacklisted.")
                c.close()
                sys.exit(1)

def proxyServer(globalHost, port, c, rawData, addr, file_name):
    print("{} {} {} {}".format(globalHost, port, c, addr))
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((globalHost, port))
        s.send(rawData)
        if file_name in os.listdir('cache/'):
            print("CACHE HIT.")
            file_handler = open("cache/" + file_name, "rb")
            Data = file_handler.read()
            c.send(Data)
            file_handler.close()

        else:
            print("CACHE MISS.")
            file_handler = open("cache/" + file_name, "wb")
            while 1:
                hostData = s.recv(buffer)
                if len(hostData) > 0:
                    c.sendall(hostData)
                    file_handler.write(hostData)
                    print("[*] Request sent: {} > {}".format(addr[0], globalHost))
                else:
                    break
            file_handler.close()

        s.close()
        c.close()

    except Exception as error:
        pass
        s.close()
        c.close()
        sys.exit(1)

if __name__ == "__main__":
    main()