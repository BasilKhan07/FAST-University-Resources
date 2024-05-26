#include<iostream>

using namespace std;

int main()
{
	int flag = 0;
	int arr[3][3]={{1,2,0},{0,1,0},{0,0,1}};
		for(int i=0; i<3; i++)
	{
		for(int j=0;j<3; j++)
		{	
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
    }
	for(int i=0; i<3; i++)
	{
		for(int j=0;j<3; j++)
		{
			if(i==j && arr[i][j]!=1)
			{
				flag = 1;
				break;
			}
			if(i!=j && arr[i][j]!=0)
			{
				flag = 1;
				break;
			}
			
		}
	}
	cout << endl;
	if(flag==1)
	{
		cout << "It is not an identity matrix." << endl;
	}
	else
	{
		cout << "It is an identity matrix." << endl;
	}
}
