// Polymorphism
// Example 09

/*
#include<iostream>
using namespace std;

class Vector
{
	int x, y;
	public:
	Vector( int x = 0, int y = 0)
	{	this->x = x; this->y = y;}
	void printXY( )
	{	cout << "x: " << x << endl;
		cout << "y: " << y << endl;}
	Vector operator+(const Vector &ob)
	{	Vector temp;
		temp.x = x + ob.x;
		temp.y = y + ob.y;
		return temp;}
};

int main(){
	Vector v1(5,6);
	Vector v2(7,8);
//	v1.printXY();
	Vector v3 = v1 + v2;
	v3.printXY();
	
	
}*/


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

Vector operator ++ ( ) // for object v1
{	//Vector temp;
		++x;
		++y;
}
/*Vector operator ++ ( int) // for object v1
{	Vector temp;
		temp.x=++x;
		temp.y=++y;
		return temp;
}*/


};

int main(){
	Vector v1(5,6);
	Vector v2(7,8);
    ++v1;
    v1.printXY();
    ++v2;
    v2.printXY();


	
	
}
