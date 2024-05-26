#include<iostream>

using namespace std;

class CONST{
	private:
		const int balance1;
		int balance2;
		int withdraw;
		int deposit;
		
	public:
		CONST():balance1(20000)
		{
			cout << "Balance: " << balance1;
		}
		void Balance(int a)
		{
			balance2 = a;
		}
		void with(int wit) 
		{
			// balance1 = balance1 - wit; Error 
			balance2 -= wit;
		}
		void dep(int dep) const
		{
			// balance1 = 30000;  Error
			// balance1 += dep;   Error
			// balance2 += dep;  Error
		}
};

int main()
{
	CONST c;
	int wit, dep;
	cout<< "Enter Withdrawl amount: ";
	cin >> wit;
	c.with(wit);
	cout<< "Enter Deposit amount: ";
	cin >> dep;
	c.dep(dep);
}
