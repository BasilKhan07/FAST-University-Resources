// Friend Fucntion
/*

#include<iostream>
using namespace std;
class Addition{
	int a , b;
	public:
		void setData(int x, int y){
			a = x;
			b = y;
		}
		friend void getSum(Addition);
};
void getSum(Addition p){
	cout<<"The sum is: "<< p.a + p.b;
}
int main(){
	Addition obj1, obj2, obj3;
	obj1.setData(5,6);
	getSum(obj1);
}*/
#include<iostream>
using namespace std;
class Addition{
	int a, b;
	friend void getSum(Addition);
	public:
		void setData(int x, int y){
			a = x;
			b = y;
			
		}		
};
void getSum(Addition p){
	cout<<"The sum is: "<<p.a+p.b<<endl;
}
int main(){
	Addition obj1, obj2, obj3;
	obj1.setData(5,6);
	getSum(obj1);
	obj2.setData(7,8);
	getSum(obj2);
	obj3.setData(10,15);
	getSum(obj3);
}
