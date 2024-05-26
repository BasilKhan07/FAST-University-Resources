#include<iostream>

using namespace std;

int main()
{
	int *arr1{new int[6]{2,3,5,1,6,7}};
	int *arr2;
	arr2 = new int[6];
	int *arr3;
	arr3 = new int[6];
	int *arr4;
	arr4 = new int[6];
	cout << "Input array: ";
	for(int i=0; i<6; i++)
	{
		cout << arr1[i] << " ";
	}
	for(int i=0; i<6; i++)
	{
		for(int j= i+1; j<6; j++)
		{
			if(arr1[i]>arr1[j])
			{
				int temp = 0;
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
		}
	}
	cout << endl;
	for(int i=0; i<6; i++)
	{
		arr2[i] = arr1[i];
	}
	for(int i=0; i<6; i++)
	{
		for(int j= i+1; j<6; j++)
		{
			if(arr1[i]<arr1[j])
			{
				int temp = 0;
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
		}
	}
	for(int i=0; i<6; i++)
	{
		arr3[i] = arr1[i];
	}
	int j = 0;
	for(int i=0; i<6; i=i+2)
	{
		arr4[i] = arr3[j];
		j++;
	}
	int k = 0;
	for(int i=1; i<6; i=i+2)
	{
		arr4[i] = arr2[k];
		k++;
	}
	cout << endl << "Desired array: ";
	for(int i=0; i<6; i++)
	{
		cout << arr4[i] << " ";
	}
}
