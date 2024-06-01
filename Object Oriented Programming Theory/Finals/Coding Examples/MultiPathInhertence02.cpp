// C++ program demonstrating ambiguity in Multipath
// Inheritance


#include <iostream>
using namespace std;
class A {
public:
	int a;
};

class B : public A {
public:
	int b;
};
class C : public A {
public:
	int c;
};

class D : public B, public C {
public:
	int d;
};

int main()
{

	D obj;

	 //obj.a = 10;				 //Statement 1, Error
	// obj.a = 100;				 //Statement 2, Error

	obj.B::a = 5; // Statement 3
	obj.C::a = 6; // Statement 4

	obj.b = 7;
	obj.c = 8;
	obj.d = 9;

	cout << "\n A from B : " << obj.B::a;
	cout << "\n A from C : " << obj.C::a;

	cout << "\n B : " << obj.b;
	cout << "\n C : " << obj.c;
	cout << "\n D : " << obj.d;
}

