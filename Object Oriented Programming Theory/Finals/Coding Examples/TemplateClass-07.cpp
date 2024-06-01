// Array in Class
#include<iostream>
using namespace std;
const int size = 5;
template<class T>class StudentMarks{
	T std_roll_no;
	T std_marks[size];
	public:
		T getMarks_rollNo(){
	cout<<"Enter your roll No: ";
	cin>>std_roll_no;
	for(int i=0; i<size; i++){
		cout<<"Enter marks in sbject:"<<(i+1)<<" : ";
		cin>>std_marks[i];
	}

}
T tot_marks(){
	T totalMarks = 0;
	for(int i=0; i<size; i++){
		totalMarks += std_marks[i];
		//cout<<"\nYour total marks are:\n"<<totalMarks;
	}
	cout<<"\nYour total marks are:\n"<<totalMarks;
}
	 
};

int main(){
	StudentMarks <float>std_object;
	std_object.getMarks_rollNo();
	std_object.tot_marks();
	
}
