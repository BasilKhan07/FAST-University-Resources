#include<iostream>

using namespace std;

void MinMax(int arr[], int *x, int *y)
{
	*x = arr[0];
	for(int i=0; i<5; i++)
	{
		if(*x>arr[i])
		{
			*x = arr[i];
		}
	}
	*y = arr[0];
	for(int i=0; i<5; i++)
	{
		if(*y<arr[i])
		{
			*y = arr[i];
		}
	}
}

int main()
{
	int min, max;	
	int num[5];
	cout << "Enter five numbers: ";
	for(int i=0; i<5; i++)
	{
		cin >> num[i];
	}
	MinMax(num, &min, &max);
	cout << "Maximum Number: " << max << endl;
	cout << "Minimum Number: " << min << endl;
}
