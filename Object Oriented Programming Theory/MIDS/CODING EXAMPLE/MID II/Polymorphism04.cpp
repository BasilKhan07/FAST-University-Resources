// Example 04
// Polymorphism
// Operator overloading

#include<iostream>
using namespace std;
class Complex{
	int a , b;
	public:
		void setData(int num1, int num2){
			a = num1;
			b = num2;
		}
		void showData(){
			cout<<"Value of a is:   "<<a<<endl;
			cout<<"Value of b is:   "<<b<<endl;
		}
};
int main(){
	Complex c1, c2, c3;
	c1.setData(4,5);
	c2.setData(6,7);
	c3 = c1 + c2;
}
