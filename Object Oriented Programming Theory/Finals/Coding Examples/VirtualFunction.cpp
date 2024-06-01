// virtual function
#include<iostream>
using namespace std;
class A{
	int a;
	public:
		A(){
			a = 10;
		}
		virtual void show(){
			cout<<"This is parent class: "<<endl;
		}
};
class B: public A{
	int b;
	public:
		B(){
			b = 20;
		}
		void show(){
			cout<<"This is derived class: "<<endl;
		}
};
int main(){
	A *pointer; // base class pointer
	B b;
	pointer = &b;
	pointer ->show();
	
}
