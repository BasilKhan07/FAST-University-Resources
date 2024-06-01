#include<iostream>
using namespace std;
class A{
	public:
int a;
};
class B: virtual public A{
	public:
	int b;
};
class C: virtual public A{
public:
	int c;
};
class D: public B, public C{
	public:
	int d;
};
int main(){
	D d;
	d.a = 10;        //Statement 3
            //d.a = 100;      //Statement 4
 
            d.b = 20;
            d.c = 30;
            d.d = 40;
 
            cout<< "\n A : "<< d.a;
            cout<< "\n B : "<< d.b;
            cout<< "\n C : "<< d.c;
            cout<< "\n D : "<< d.d;
	
	
}
