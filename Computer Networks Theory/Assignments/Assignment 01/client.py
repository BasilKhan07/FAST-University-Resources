import _thread
from socket import *
from tkinter import *
def disconnect():
    client.close()
    type.config(state=DISABLED)
    button2.config(state=DISABLED)
    button3.config(text="Not connected",bg="red")
def send():
    message = type.get("0.0",END)
    chat.config(state=NORMAL)
    chat.insert(END, 'Client: ' + message)
    chat.config(state=DISABLED)
    client.send(message.encode())
    type.delete("0.0", END)
def receivemsg():
     while 1:
        try:
            msg = client.recv(2048).decode()
            chat.config(state=NORMAL)
            chat.insert(END, 'Server: ' + msg)
            chat.config(state=DISABLED)

        except:
            pass

def connection():
        global client
        port_num=ip.get("0.0",END)
        port=int(port_num)
        client= socket(AF_INET, SOCK_STREAM)
        ipaddress ='localhost'
        client.connect((ipaddress,port))
        button3.config(text="Connected",bg="light yellow")
        button2.config(state=NORMAL)
        button4.config(state=NORMAL)
        type.config(state=NORMAL)


def GUI():
        global root
        global type
        global chat
        global ip
        global button2
        global button3
        global button4
        root = Tk()
        root.config(bg="light blue")
        root.title("Client")
        _thread.start_new_thread(receivemsg, ())

        label1 = Label(root, text="Enter Port")
        label1.grid(row=4,column=1)
        chat = Text(root, bg='light grey',fg='black')
        chat.config(state=DISABLED)
        root.geometry("500x500")
        button1 = Button(root,bg='light yellow', text="Connect", command=connection)
        button2 = Button(root,bg='light yellow', text="Send",command=send)
        button2.config(state=DISABLED)
        button3 = Button(root, bg='red', text="Not Connected")
        button4 = Button(root, bg="light yellow", text="Disconnect", command=disconnect)
        button4.config(state=DISABLED)
        ip = Text(root, bg='light grey')
        type = Text(root, bg='light grey', fg='black')
        type.config(state=DISABLED)
        ip.place(x=80, y=6, height=30, width=150)
        button1.place(x=250, y=6, height=30, width=80)
        button3.place(x=10, y=45, height=20, width=90)
        chat.place(x=4, y=70, height=300, width=440)
        type.place(x=6, y=380, height=100, width=320)
        button2.place(x=350, y=400, height=20, width=80)
        button4.place(x=350, y=430, height=20, width=80)
        root.mainloop()
GUI()

