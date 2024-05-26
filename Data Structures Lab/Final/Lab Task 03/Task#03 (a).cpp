#include<iostream>

using namespace std;

void fun(int n[], int i)
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
	fun(n,i-1);
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6,7};
	cout << "Input: " << endl;
	for(int i=0; i<6; i++)
	{
		cout << arr[i] << " ";
	}
	fun(arr,6);
	cout << endl << "Ouput: " << endl;
	for(int i=0; i<6; i++)
	{
		cout << arr[i] << " ";
	}
}
