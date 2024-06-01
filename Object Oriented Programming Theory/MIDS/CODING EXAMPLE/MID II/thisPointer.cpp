// this pointer
// Example 01
#include<iostream>
using namespace std;
class circle{
	int r;
	public:
	circle(int r){
		this->r = r;
	}
	int getArea(){
	return 3.14*r*r;	
	}
};
int main(){
	circle c(5);
	cout<<c.getArea();
}
