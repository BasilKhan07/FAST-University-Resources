// rough
#include<iostream>
using namespace std;
template <class T>class addition {
	public:
	T a, b;
	void userInput(){
		cout<<"Enter value for a: ";
		cin>>a;
		cout<<"Enter value for b: ";
		cin>>b;
	}
	T add(T a, T b){
		return a+b;
	}
	void display(){
		cout<<"Your result is: "<<add(a,b);
	}
	
};
int main(){
	addition <string>obj;
	obj.userInput();
	obj.display();
}
