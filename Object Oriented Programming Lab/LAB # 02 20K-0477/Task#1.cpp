#include<iostream>
#include<cmath>
#include<cctype>

using namespace std;

float residential_bill(int n1);
float buisness_bill(int n1, int n2);

int main()
{
	long int account_no=0;
	char customer_code;
	int premium_no=0, connection_no=0;
	float total_bill=0;
	cout << "Account Number: " << endl;
	cin >> account_no;
	cout << "Enter Customer Code: " << endl;
	cin >>  customer_code;
	if(customer_code == 'r' || customer_code == 'R')
	{
		cout << "Enter Number Of Premium Channels: " << endl;
		cin >> premium_no;
		total_bill = residential_bill(premium_no);
	}
	else if(customer_code == 'b' || customer_code == 'B')
	{
		cout << "Enter Number Of Basic Service Connection: " << endl;
		cin >> premium_no;
		cout << "Enter Number Of Connections: " << endl;
		cin >> connection_no;
		total_bill = buisness_bill(premium_no,connection_no);
	}
	else
	{
		cout << "Enter Valid Customer Code!!" << endl;
	}
	cout << "Account Number: " << account_no << endl;
	cout << "Total Bill: " << total_bill << endl;
}

float residential_bill(int n1)
{
	float bill_fee = 4.50;
	float basic_fee = 20.50;
	float channel;
	float total;
	channel = n1 * 7.50;
	total = bill_fee + basic_fee + channel;
	return total;
}

float buisness_bill(int n1, int n2)
{
	float total;
	int extra;
	float bill_fee = 15;
	float basic_fee = 75;
	float channel;
	channel = n1 * 50;
	total = channel + basic_fee + bill_fee;
	if(n2<=10)
	{
		total += 75;
	}
	else
	{
		total += 75;
		extra = n1-10;
		extra = extra * 5;
		total += extra;
	}
	return total;
}
