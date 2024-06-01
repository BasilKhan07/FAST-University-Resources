// Static casting
#include<iostream>
using namespace std;

int main(){
	int a = 5;
	int b = 2;
	
	float c = static_cast<float>(a)/b;
	cout<<c<<endl;
}
