#include<iostream>

using namespace std;

class Student{
	private:
		string studentName;
		int rollNumber;
		int subMarks[4];
	
	public:
		string getname(){
			return studentName;
		}
		void setname(string name){
			studentName=name;
		}
		int getrollno(){
			return rollNumber;
		}
		void setrollno(int rollno){
			rollNumber=rollno;
		}
		int getmarks(int i){
			return subMarks[i];
		}
		void setmarks(int marks, int i){
			subMarks[i]=marks;
			
		}
		float percentage(){
			int i, total=0;
			float per;
			for(i=0;i<4;i++)
			{
				total = total + subMarks[i];
			}
			per = (float (total ) /400) * 100;
			return per;
		}
		void display(float per){
			cout << "Student Name: " << studentName << endl;
			cout << "Student Roll Number: " << rollNumber << endl;
			for(int i=0;i<4;i++)
			{
				cout << "Subject " << i+1 << " Marks : " << subMarks[i] << "/100" << endl;
			}
			cout << "Percentage: " << per;
		}
};

int main()
{
	Student S;
	string name;
	int rollno, marks[4], i;
	float per;
	cout << "Enter Student Name: ";
	getline(cin,name);
	S.setname(name);
	cout << "Enter Student Roll Number: ";
	cin >> rollno;
	S.setrollno(rollno);
	for(i=0;i<4;i++)
	{
		cout << "Enter Subject "<< i+1 << " Marks: ";
		cin >> marks[i];
		S.setmarks(marks[i],i);
	}
	system("cls");
	per = S.percentage();
	S.display(per);
}
