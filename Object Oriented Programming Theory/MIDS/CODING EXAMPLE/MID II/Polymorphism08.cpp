// oeprator overloading 

// Operator Overlaoding

/*
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
	Vector add(Vector v){
		Vector temp;
		temp.a = a + v.a;
		temp.b = b + v.b;
		return temp;
	}
		
};
int main(){
	Vector v1, v2, v3;
	v1.setData(5,6);
	v2.setData(7,3);
	v3 = v1.add(v2);
	v3.print();

//	cout<<v1.print()<<endl;
//	cout<<v2.print()<<endl;
	
}*/


#include<iostream>
#include<conio.h>
using namespace std;
class sumObject{
	int a, b;
	public:
		void setData(int x, int y){
			a = x;
			b = y;
		}
		void showData(){
			cout<<"value of a is: "<<a<<endl<<"value of b is: "<<b<<endl;
		}
		sumObject add(sumObject obj){
			sumObject temp;
			temp.a = a + obj.a;
			temp.b = b + obj.b;
			return temp;
			
		}
	
};
int main(){
	sumObject obj1, obj2, obj3;
	obj1.setData(2,3);
	obj2.setData(4,5);
	obj1.showData();
	obj2.showData();
	//obj3 = obj1.add(obj2);
	obj3 = obj1 + obj2;
	obj3.showData();
	
	
}

/*#include<iostream>
#include<conio.h>
using namespace std;
class sumObject{
	int a, b;
	public:
		void setData(int x, int y){
			a = x;
			b = y;
		}
		void showData(){
			cout<<"value of a is: "<<a<<endl<<"value of b is: "<<b<<endl;
		}
		sumObject operator +(sumObject obj){
			sumObject temp;
			temp.a = a + obj.a;
			temp.b = b + obj.b;
			return temp;
			
		}
	
};
int main(){
	sumObject obj1, obj2, obj3;
	obj1.setData(2,3);
	obj2.setData(4,5);
	obj1.showData();
	obj2.showData();
	obj3 = obj1.operator +(obj2);
	obj3 = obj1 + obj2;
	obj3.showData();
	
	
}*/
