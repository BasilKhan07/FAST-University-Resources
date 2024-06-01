// Polymorphism 
// Example 10


#include<iostream>
using namespace std;

class Vector
{
	int x,y;
	public:
	Vector( int x = 0, int y = 0)
	{	this->x = x; this->y = y;}
	void printXY( )
	{	cout << "x: " << x << endl;
		cout << "y: " << y << endl;}
// unary operator

Vector operator ++ ( ) // for object v1, prefix 
{	
		++x;
		++y;
}



};

int main(){
	Vector v1(5,6);
	Vector v2(7,8);
    ++v1;
    v1.printXY();
    ++v2;
    v2.printXY();


	
	
}
