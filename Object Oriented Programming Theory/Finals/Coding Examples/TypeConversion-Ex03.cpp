// Slide example
#include<iostream>
using namespace std;
int main() 
{ 
	int a = 10;
	float f = 4.0;
	float c;

	c = a / f;			// a is promoted to float
	cout << "10 / 4 = " << c;	//prints 2.5 as result
} 

