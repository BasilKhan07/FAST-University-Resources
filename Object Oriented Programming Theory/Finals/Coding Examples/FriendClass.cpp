// Friend class
#include<iostream>
using namespace std;
class A{
	int a;
	public:
		A(){
			a=10;
		}
		friend class B;
};
class B{
	int b;
	public:
		B(){}
			void show(A &c){
			cout<<c.a<<endl;}
		
};
int main(){
	A a;
	B b;
	b.show(a);
}
