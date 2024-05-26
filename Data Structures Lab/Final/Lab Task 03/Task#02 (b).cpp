#include<iostream>

using namespace std;

void Func1(int n, int i)
{
	static int j=0;
	if(n==0)
	{
		return ;
	}
	cout << i << " ";
	i = i+j;
	j++;
	return Func1(n-1,i);
}

void Func2(int n)
{
	return Func1(n, 1);
}

int main()
{
	Func2(8);
}
