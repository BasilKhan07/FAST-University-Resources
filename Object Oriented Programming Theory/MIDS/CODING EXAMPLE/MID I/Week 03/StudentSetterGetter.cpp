// student rollNo with getter and setter
#include<iostream>

using namespace std;

class Student{
	int rollNo;
	public:
		int setRollNo(int aRollNo){
			rollNo = aRollNo;
		}
		int getRollNo(){
			return rollNo;
		}
};

int main(){
	Student std1;
	std1.setRollNo(16305);
	cout<<std1.getRollNo();
}
