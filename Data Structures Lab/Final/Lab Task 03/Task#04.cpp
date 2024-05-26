#include<iostream>

using namespace std;

int fun(int n)
{
	// 1 - 95 > 100 = FALSE 
	// 3 - 106 > 100 = TRUE
	// 6 - 96 > 100 = FALSE
	// 8 - 107 > 100 = TRUE
	// 11 - 97 > 100 = FALSE
	// 13 - 108 > 100 = TRUE
	// 16 - 98 > 100 = FALSE
	// 18 - 109 > 100 = TRUE 
	// 21 - 99 > 100 = FALSE
	// 23 - 110 > 100 = TRUE
	// 26 - 111 > 100 = TRUE
	if(n>100)
	{
		// 4 - 106 - 10 = 96
		// 9 - 107 - 10 = 97
		// 14 - 108 - 10 = 98
		// 19 - 109 - 10 = 99
		// 24 - 110 - 10 = 100
		// 27 - 111 - 10 = 91
		return n-10;
	}
	// 2 - fun(fun(95+11=106))
	// 5 - fun(96)
	// 7 - fun(fun(96+11=107)
	// 10 - fun(97)
	// 12 - fun(fun(97+11=108))
	// 15 - fun(98)
	// 17 - fun(fun(98+11=109))
	// 20 - fun(99)
	// 22 - fun(fun(99+11=110))
	// 25 - fun(100+11=111)
	// 27 - return 91
	return fun(fun(n+11));
}
int main()
{
	int r;
	r = fun(95);
	cout << " " << r;
	return 0;
}
