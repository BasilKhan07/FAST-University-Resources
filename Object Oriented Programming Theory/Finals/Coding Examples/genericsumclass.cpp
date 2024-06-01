// generic class
#include<iostream>
using namespace std;
template <class T>class addition
{
	public:
		T a, b;
    void ask(){
       cout<<"Enter first number: ";
       cin>>a;
       cout<<"Enter second number: ";
       cin>>b;
    }
	int add(T a, T b){
		return a+b;
	}
	 void show(){
       cout<<add(a, b);
    }
};
int main(){
	addition <float>obj;
	obj.ask();
	obj.show();
}
