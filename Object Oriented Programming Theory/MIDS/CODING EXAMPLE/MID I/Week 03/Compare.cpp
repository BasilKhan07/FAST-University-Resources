// importing libraries 

#include<iostream>
using namespace std;

class Compare{
	public:
	int max(int x, int y){
//		conditional operators
//       > greater than symbol, ? if true then print x , : otherwise y
	return((x>y)?x:y); 
}
};

int main () {
	Compare cmpr;
	cout<<"The greater value is:\n"<<cmpr.max(9,8);
}

