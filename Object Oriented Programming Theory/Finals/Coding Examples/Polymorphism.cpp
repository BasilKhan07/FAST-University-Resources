// Polymorphism
// Example 01
//  
// Compile time polymorphism example  is function overloading
#include <iostream>

using namespace std;
class A
{
	public:	
	// function with 1 integer parameter
	void function(int x)
	{
		cout<<"function with 1 integer parameter: "<<endl;
		cout << "value of x is " << x << endl;
	}
	// function with same name but 1 double parameter
	void function(double x)
	{
		cout<<"function with same name but 1 double parameter: "<<endl;
		cout << "value of x is " << x << endl;
	}
	
	// function with same name and 2 integer parameters
	void function(int x, int y)
	{
		cout<<"function with same name and 2 integer parameters: "<<endl;
		cout << "value of x and y is " << x << ", " << y << endl;
	}
};

int main() {
	
	A obj;
	
	// Which function is called will depend on the parameters passed
	// The first 'func' is called
	obj.function(5);
	
	// The second 'func' is called
	obj.function(9,2);
	
	// The third 'func' is called
	obj.function(6,6);
	return 0;
}

