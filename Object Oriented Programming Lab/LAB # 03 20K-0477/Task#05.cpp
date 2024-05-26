#include<iostream>
#include<conio.h>

float inter = 0;
int flag=0;

using namespace std;

class BankAccount{
	private:
		long accountNumber;
		int numberOfTransaction;
		long balance;
		float interest;
		
	public:
		long getaccno(){
			return accountNumber;
		}
		void setaccno(long accno){
			accountNumber=accno;
		}
		int gettrans(){
			return numberOfTransaction;
		}
		void incrementtrans(){
			numberOfTransaction++;
		}
		long getbal(){
			return balance;
		}
		void setbal(long bal){
			balance=bal;
		}
		void deposit(int dep){
			balance += dep;
		}
		void withdraw(int with){
			if(with>balance)
			{
				cout << "Insufficient Balance!!" << endl;
				flag=1;
			}
			else
			{
				flag=0;
				balance -= with;
			}
		}
		float Interest(int time){
			inter = (balance * time) * 0.3;
			return inter;
		}
};

int main()
{
	BankAccount B;
	long bal, accno;
	cout << "Enter Account Number: ";
	cin >> accno;
	B.setaccno(accno);
	cout << "Enter Account Balance: ";
	cin >> bal; 
	B.setbal(bal);
	cout << "Press to return to menu";
	getch();
	Main:
		system("cls");
		int choice;
		cout << "     Bank Management System" << endl;
		cout << "            Menu" << endl;            
		cout << "1. Display the account balance." << endl;
		cout << "2. Display number of transaction." << endl;
		cout << "3. Display interest earned for this period." << endl;
		cout << "4. Make a deposit." << endl;
		cout << "5. Make a withdrawl." << endl;
		cout << "6. Add interest for this period." << endl;
		cout << "7. Exit." << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					system("cls");
					cout << "Account Number: " << B.getaccno() << endl;
					cout << "Account Balance: " << B.getbal() << endl; 
					cout << "Press enter to return to menu.";
					getch();
					goto Main;
					break;
				}
			case 2:
				{
					system("cls");
					cout << "Account Number: " << B.getaccno() << endl;
					cout << "Number of Transaction: " << B.gettrans() << endl;
					cout << "Press enter to return to menu.";
					getch();
					goto Main;
					break;
				}
			case 3:
				{
					system("cls");
					int period;
					cout << "Account Number: " << B.getaccno() << endl;
					cout << "Enter time period in years: ";
					cin >> period;
					cout << "Interest earned: " << B.Interest(period) << endl;
					cout << "Press enter to return to menu.";
					getch();
					goto Main;
					break;
				}
			case 4:
				{
					system("cls");
					int dep;
					cout << "Account Number: " << B.getaccno() << endl;
					cout << "Enter amount to deposit: ";
					cin >> dep;
					B.incrementtrans();
					B.deposit(dep);
					cout << "Amount deposited. " << endl;
					cout << "Press enter to return to menu.";
					getch();
					goto Main;
					break;
				}
			case 5:
				{
					system("cls");
					int with;
					cout << "Account Number: " << B.getaccno() << endl;
					cout << "Enter amount to withdraw: ";
					cin >> with;
					B.withdraw(with);
					if(flag==0)
					{
						B.incrementtrans();
						cout << "Amount withdrawed. " << endl;
					}
					cout << "Press enter to return to menu. ";
					getch();
					goto Main;
					break;
				}
			case 6:
				{
					system("cls");
					cout << "Account Number: " << B.getaccno() << endl;
					cout << "Previous Account Balance: " << B.getbal() << endl; 
					cout << "Balance after interest addition: " <<  inter + B.getbal() << endl;
					cout << "Press enter to return to menu. ";
					getch();
					goto Main;
					break;
				}
			case 7:
				{
					system("cls");
					cout << "Thanks for visiting our bank !!";
					getch();
					exit(0);
					break;
				}
		}
}

