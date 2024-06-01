// Student
# include<iostream>
using namespace std;

class Student{
	string name;
	string studentId;
	public: 
	void reading(){
		cout<<"Reading:\n";
	}
	void playing(){
		cout<<"playing:\n";
	}
};
int main(){
	Student theStudent;
	theStudent.reading();
	theStudent.playing();
}
