#include<iostream>

using namespace std;

int main()
{
	int num, sum=0;
	cout << "Enter Number: ";
	cin >> num;
	if(num==-1)
	{
		exit(0);
	}
	else
	{
		cout << "Factors of " << num << " : " << endl;
		for(int i=2; i<=(num/2); i++)
		{
			if(num%i==0)
			{
				cout << i << endl;
				sum = sum + i;
			}
			else
			{
				continue;
			}
		}
		cout << "Sum of all factors of " << num << " : " << sum << endl;
	}
}
