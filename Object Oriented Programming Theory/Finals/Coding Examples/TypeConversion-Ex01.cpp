//implicit conversion
// Type conversion
// From int to double
#include<iostream>
using namespace std;
int main(){
	int a = 5; //assigning int value to a
	double b; //decalaring double variable
	
	int c = 6;
	double f = 3.5;
	// implicit conversion
	
	b = a; // assigning value of a to b
	
	//implicit conversion
	c = f; // assigning value of f to c
	
	// print the values of variable a and varibale b
	cout<<"Value of a is: "<<a<<endl;
	cout<<"Value of b is: "<<b<<endl;
	cout<<"Value of c is: "<<c<<endl;
	
}
