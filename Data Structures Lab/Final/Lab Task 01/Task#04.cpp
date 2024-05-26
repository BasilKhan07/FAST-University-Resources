#include<iostream>

using namespace std;

int Calculation(int n)
{
	int s=0;
	if(n==-1)
	{
		exit(0);
	}
	else
	{
		cout << "Factors of " << n << " : " << endl;
		for(int i=2; i<=(n/2); i++)
		{
			if(n%i==0)
			{
				cout << i << endl;
				s = s + i;
			}
			else
			{
				continue;
			}
		}
	}
	return s;
}

int main()
{
	int num, sum;
	cout << "Enter Number: ";
	cin >> num;
	sum = Calculation(num);
	cout << "Sum of all factors of " << num << " : " << sum << endl;
}
