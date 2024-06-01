#include<iostream>
using namespace std;

class CompareInline {
	
	inline int max(int x, int y){
		((x>y)?x:y);
	}
};

int main(){
	CompareInline  cmprInline;
	int a, b;
	cout<<"Enter values for a and b:";
	cin>>a>>b;
	cout<<"The greater value is:"<<max(a,b);
	return 0;
}
