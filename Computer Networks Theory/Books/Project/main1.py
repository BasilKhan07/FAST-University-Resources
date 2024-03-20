from PyQt5.QtWidgets import *
from PyQt5 import uic
import imaplib
import email
import ssl
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
class MyGUI(QMainWindow):
    def __init__(self):
        super(MyGUI, self).__init__()
        uic.loadUi("graphicalinterface1.ui", self)
        self.show()
        self.LOGINBUTTON.clicked.connect(self.login)
        self.REFRESHBUTTON.clicked.connect(self.refresh)
        self.LOGOUTBUTTON.clicked.connect(self.logout)
    def login(self):
        try:

            imapaddr = self.IMAPBOX.text()
            self.imap = imaplib.IMAP4_SSL(imapaddr)

            emailaddr = self.EMAILBOX.text()
            password = self.PASSWORDBOX.text()
            self.imap.login(emailaddr, password)
            self.TEXTBOX.setEnabled(True)
            self.LOGOUTBUTTON.setEnabled(True)
            self.REFRESHBUTTON.setEnabled(True)

            self.LOGINBUTTON.setText("Logged In")
            self.LOGINBUTTON.setEnabled(False)

            self.refresh()
        except Exception as e:
            print(e)
    def refresh(self):


            res,messages=self.imap.select("Inbox")
            messages = int(messages[0])
            n = 7
            Total = ""
            for i in range(messages, messages-n, -1):
                res, msg = self.imap.fetch(str(i), "(RFC822)")
                for response in msg:

                    if isinstance(response, tuple):
                        msg = email.message_from_bytes(response[1])
                        form=msg["From"]
                        subject = msg["Subject"]
                        body = msg["TEXT"]

                        print(subject)
                        print(body)
                        Total=(Total)+("From: ")+(form)+("\n\nSubject: ")+(subject)+"\n-----------------------------------------------------------------------------------------------------------------\n"



            self.TEXTBOX.setText(Total)

    def logout(self):
        self.imap.close()

        self.TEXTBOX.clear()
        self.LOGINBUTTON.setEnabled(True)
        self.LOGOUTBUTTON.setEnabled(False)
        self.REFRESHBUTTON.setEnabled(False)
        self.LOGINBUTTON.setText("Login")


app= QApplication([])
window = MyGUI()
app.exec_()
