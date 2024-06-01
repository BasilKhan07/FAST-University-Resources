//Polymorphism
// Example 05
#include<iostream>
using namespace std;

class Rectangle{
	private:
		int len, wdt, oneside;
	public:
		void setDimension(int length, int width){
			len = length;
			wdt = width;
			cout<<"values of length and width are:   "<<length<<"   ,   "<<width<<endl;
		}
		void setDimension(int side){
		    oneside = side;
		    cout<<"value of one side is :   "<<oneside<<endl;
				
		}
		int getArea(){
			return len*wdt;
		}
		int getArea(){ // 	[Error] 'int Rectangle::getArea()' cannot be overloaded
			return oneside*oneside;
		}
};
int main(){
	Rectangle obj;
	obj.setDimension(5,6);
	obj.setDimension(7);
	cout<<obj.getArea()<<endl;
}
