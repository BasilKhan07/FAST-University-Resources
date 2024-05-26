#include<iostream>

using namespace std;

class BankAccount{
	private:
		string nameOfdepositor;
		long accountNumber;
		long balance;
	
	public:
		string getname(){
			return nameOfdepositor;
		}
		void setname(string name){
			nameOfdepositor=name;
		}
		long getaccno(){
			return accountNumber;
		}
		void setaccno(long accno){
			accountNumber=accno;
		}
		long getbalance(){
			return balance;
		}
		void setbalance(long bal){
			balance = bal;
		}
		void setdeposit(long dep){
			balance = balance+dep;
		}
};

int main()
{
	BankAccount B;
	string name;
	long amount, accno, bal=0, dep=0, with=0, rem=0;
	cout << "Enter Name: ";
	getline(cin,name);
	B.setname(name);
	cout << "Enter Account Number: ";
	cin >> accno;
	B.setaccno(accno);
	cout << "Enter Balance: ";
	cin >> bal;
	B.setbalance(bal);
	amount = B.getbalance();
	cout << "Enter Deposit Amount: ";
	cin >> dep;
	B.setdeposit(dep);
	cout << "Enter Withdrawal Amount: ";
	cin >> with;
	if(with > B.getbalance())
	{
		cout << "Insufficient Balance!!" << endl;
	}
	else
	{
		rem = B.getbalance()-with;
	}
	
	system("cls");
	cout << "Name Of Depositor: " << B.getname() << endl;
	cout << "Account Number: " << B.getaccno() << endl;
	cout << "Balance Ammount: " << amount << endl;
	cout << "Deposit Amount: " << dep << endl;
	cout << "New Balance after deposit: " << B.getbalance() << endl;
	cout << "Withdrawl Amount: " << with << endl;
	cout << "Remaing Balance: " << rem << endl;
}
