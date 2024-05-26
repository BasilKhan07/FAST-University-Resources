#include<iostream>

using namespace std;

void Func(int n, int i)
{
	static int j=2;
	if(n==0)
	{
		return ;
	}
	cout << i << " ";
	i = i+j;
	j++;
	return Func(n-1,i);
}

int main()
{
	Func(7,1);
}
