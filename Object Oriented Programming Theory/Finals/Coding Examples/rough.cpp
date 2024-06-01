/*
#include<iostream>
#include<conio.h>
using namespace std;
class vector{
	float a, b;
	public:
		void setData(float x, float y){
			a = x;
			b = y;
		}
		void showData(){
			cout<<"a is: "<<a<<", b is: "<<b<<endl;
		
		}
//		vector add(vector v){
//			vector temp;
//			temp.a = a + v.a;
//			temp.b = b + v.b;
//			return temp;
//		}
		vector operator +(vector v){
			vector temp;
			temp.a = a + v.a;
			temp.b = b + v.b;
			return temp;
		}
};
int main(){
	vector v1, v2, v3;
	v1.setData(5,6);
	v2.setData(4,5);
	v1.showData();
	v2.showData();
//	v3 = v1.add(v2);
    v3 = v1 + v2;
	v3.showData();
}*/
#include<iostream>
using namespace std;
class shape{
	protected:
		int length, width;
		public:
			shape(int a, int b){
				length = a;
				width = b;
			}
			virtual int area(){
				cout<<"this is parent class area: "<<endl;
			}
};
class rectangle : public shape{
	public:
	rectangle(int a, int b): shape(a, b){
	}
	int area(){
		return length*width;
		
	}
};
class triangle : public shape{
	public:
	triangle (int a, int b):shape(a, b){
	}
	int area()
	{
		return (length*width/2);
	}
};
int main(){
	shape *s;
	rectangle rec(5,6);
	s = &rec;
	cout<<s->area()<<endl;
	triangle tri(12,6);
	s = &tri;
	cout<<s->area()<<endl;
	
}
