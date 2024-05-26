#include <iostream>
#include<string.h>
using namespace std;

class Student{
	public:
		char Name[30];
		string Rollnumber;
		int Age;
		void showdata(int i)
		{
			cout << "Name of " << i+1 << " Student: " << Name << endl;
			cout << "Roll Number: " << Rollnumber << endl;
			cout << "Age: " << Age << endl;
		}
		
};
int main() 
{
	Student *stud= new Student[5];
	for(int i=0; i<5; i++)
	{
		fflush(stdin);
		cout <<"Enter Name of "<< i+1 << " Student: ";
		cin.get(stud[i].Name, 30);
		fflush(stdin);
		cout << "Enter Roll number: ";
		getline(cin,stud[i].Rollnumber);
		cout << "Enter Age: ";
		cin >> stud[i].Age;
	}
	Student temp;
	for(int i=0; i<5; i++)
	{
		for(int j=i+1; j<5; j++)
		{
			if(strcmp(stud[i].Name,stud[j].Name) > 0)
			{
				temp = stud[i];
				stud[i] = stud[j];
				stud[j] = temp;
			}
		}
	}
	system("cls");
	for(int i=0; i<5; i++)
	{
		stud[i].showdata(i);
	}
	delete[] stud;
}
