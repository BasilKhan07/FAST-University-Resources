#include<iostream>

using namespace std;

void fun1(int n[], int i)
{	
	if(i==1)
	{
		return;
	}
	for(int j=0; j<i-1; j++)
	{
		if(n[j]>n[j+1])
		{
			int temp = n[j+1];
			n[j+1] = n[j];
			n[j] = temp; 
		}
	}
	fun1(n,i-1);
}

int fun2(int a[])
{
	fun1(a, 6);
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6,7};
	cout << "Input: " << endl;
	for(int i=0; i<6; i++)
	{
		cout << arr[i] << " ";
	}
	
	fun2(arr);
	cout << endl << "Ouput: " << endl;
	for(int i=0; i<6; i++)
	{
		cout << arr[i] << " ";
	}
}
