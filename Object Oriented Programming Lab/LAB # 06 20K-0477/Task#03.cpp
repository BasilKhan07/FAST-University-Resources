#include<iostream>

using namespace std;

class ADD{
	public:
		static int a;
		static int b;
		
		static int sum(){
			return a+b;
		}
};

int ADD::a=0;
int ADD::b=0;

int main()
{
	int num1, num2;
	cout << "Enter First Number: ";
	cin >> num1;
	cout << "Enter Second Number: ";
	cin >> num2;
	ADD::a=num1;
	ADD::b=num2;
	cout << "The Sum of Two Number is: " << ADD::sum();
}
