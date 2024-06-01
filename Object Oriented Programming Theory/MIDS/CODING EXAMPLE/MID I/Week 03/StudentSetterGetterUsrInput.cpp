// student rollNo with getter and setter
// taking input from user on command line
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
	int aRollNo;
	cout<<"Enter roll number:";
	cin>>aRollNo;
	std1.setRollNo(aRollNo);
	cout<<std1.getRollNo();
}
