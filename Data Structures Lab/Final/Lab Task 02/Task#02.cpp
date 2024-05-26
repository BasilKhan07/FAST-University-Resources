#include<iostream>

using namespace std;

int main()
{
	int *arr;
	arr = new int[10];
	cout << "Enter 10 integers: " << endl;
	for(int i=0; i<10; i++)
	{
		cin >> arr[i];
	}
	system("cls");
	cout << "Integers in ascending order: " << endl;
	for(int i=0; i<10; i++)
	{
		for(int j= i+1; j<10; j++)
		{
			if(arr[i]>arr[j])
			{
				int temp = 0;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i=0; i<10; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl << "Integers in descending order: " << endl;
	for(int i=0; i<10; i++)
	{
		for(int j= i+1; j<10; j++)
		{
			if(arr[i]<arr[j])
			{
				int temp = 0;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i=0; i<10; i++)
	{
		cout << arr[i] << endl;
	}
	delete[]arr;
}
