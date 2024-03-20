from socket import *
from tkinter import *
import _thread as mythread
def disconnect():
    server.close()
    type.config(state=DISABLED)
    button2.config(state=DISABLED)
    
def receivemsg():
    while 1:
        try:
            msg = server.recv(2048).decode()
            chat.config(state=NORMAL)
            chat.insert(END, 'Client: ' + msg)
            chat.config(state=DISABLED)
        except:
            pass
def send():
    message = type.get("0.0",END)
    chat.config(state=NORMAL)
    chat.insert(END, 'Client: ' + message)
    chat.config(state=DISABLED)
    server.send(message.encode())
    type.delete("0.0", END)

def connection():
    global server
    port_num=ip.get("0.0",END)
    port=int(port_num)
    s = socket(AF_INET, SOCK_STREAM)
    s.bind(('localhost',port))
    s.listen()
    server, addr = s.accept()
    button2.config(state=NORMAL)
    button3.config(state=NORMAL)
    type.config(state=NORMAL)
def GUI():
    global type
    global chat
    global ip
    global button1
    global button2
    global button3
    root = Tk()
    mythread.start_new_thread(receivemsg, ())
    label1=Label(root,text="Enter Port",bg="light blue")
    label1.grid(column=0 ,row=1)
    chat=Text(root,bg='light grey',fg='black')
    chat.config(state=DISABLED)
    root.config(bg="light yellow")
    root.title("Client")
    root.geometry("500x500")
    button1 = Button(root,bg="light yellow", text="Connect", command=connection)
    button2 = Button(root,bg="light yellow", text="Send", command=send)
    button2.config(state=DISABLED)
    button3 = Button(root, bg="light yellow", text="Disconnect",command=disconnect)
    button3.config(state=DISABLED)
    type=Text(root,bg='light grey',fg='black')
    type.config(state=DISABLED)
    ip = Text(root, bg='light grey')
    ip.place(x=70, y=6, height=30, width=150)
    button1.place(x=250, y=6, height=30, width=80)
    chat.place(x=4, y=60, height=300, width=440)
    type.place(x=6, y=370, height=100, width=320)
    button2.place(x=350, y=400, height=20, width=80)
    button3.place(x=350, y=430, height=20, width=80)
    root.mainloop()
GUI()
