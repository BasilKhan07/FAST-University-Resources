// Operator Overlaoding
#include <iostream>
#include<conio.h>

using namespace std;

class Vector{
	int a, b;
	public:
		void setData(int x, int y){
			a = x;
			b = y;
		}
		void print(){
			cout<<"Value of a is: "<<a<<"   ,  "<<b<<endl;
		}
		Vector operator +( Vector  obj){
			Vector temp;
			temp.a = a + obj.a;
			temp.b = b + obj.b;
			return (temp);
		}
		
};
int main(){
	Vector v1, v2, v3;
	v1.setData(5,6);
	v2.setData(7,3);
	v3 = v1 + v2;
	v3.print();

//	cout<<v1.print()<<endl;
//	cout<<v2.print()<<endl;
	
}
