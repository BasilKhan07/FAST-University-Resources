#include<iostream>

using namespace std;

int main()
{
	bool arr[5][5]={{false,true,false,true,true},
	{true,false,true,false,true}, 
	{false,true,false,false,false},
	{true,false,false,false,true},
	{true,true,false,true,false}
	};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(arr[i][j])
			{
				cout<<" * ";
			}
			else
			{
				cout<<"   ";
			}
		}
		cout<<endl;
	}
	int num1, num2;
	cout << endl << "Enter two numbers: " << endl;
	cin >> num1 >> num2;
	int j = 0;
	for(int i=0; i<5; i++)
	{
		if(arr[num1][i]==true && arr[i][num2]==true)
		{
			j++;
			cout << i << " is a common friend of " << num1 << " and " << num2 << endl;
		}
	}
	if(j==0)
	{
		cout << "No one is a common friend of " << num1 << " and " << num2 << endl;
	}
}
