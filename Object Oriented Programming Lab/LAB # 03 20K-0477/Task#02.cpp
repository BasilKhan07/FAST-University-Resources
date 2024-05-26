#include<iostream>

using namespace std;

class Employee{
	private:
		char* fname;
		string lname;
		long salary;
	
	public:
		char* getfirstname(){
			return fname;
		}
		void setfirstname(char* first){
			fname=first;
		}
		string getlastname(){
			return lname;
		}
		void setlastname(string last){
			lname=last;
		}
		long getsalary(){
			return salary;
		}
		void setsalary(long sal){
			if(salary<0)
			{
				salary=0;
			}
			else
			{
				salary=sal;
			}
		}
};

void display(Employee E, long m, long y);

int main()
{
	Employee e[2];
	int i;
	long amount, m[2], y[2];
	for(i=0;i<2;i++)
	{
		char* Fname=new char[30];
		char* Lname=new char[30];
		cout << "Enter " << i+1 << " Employee First Name: ";
		cin >> Fname;
		e[i].setfirstname(Fname);
		cout << "Enter " << i+1 << " Employee Last Name: ";
		cin >> Lname;
		e[i].setlastname(Lname);
		cout << "Enter " << i+1 << " 1st Employee Salary: ";
		cin >> amount;
		e[i].setsalary(amount);
		m[i]=e[i].getsalary()*1.1;
		y[i]=m[i]*12;
		cout << endl << endl;
	}
	system("cls");
	for(int i=0;i<2;i++)
	{
		cout << " EMPLOYEE " << i+1 << ":" << endl << endl;
		display(e[i],m[i],y[i]);
	}
}

void display(Employee E, long m, long y)
{
	cout << "Employee First Name: " << E.getfirstname() << endl;
	cout << "Employee Last Name: " << E.getlastname() << endl;
	cout << "Employee Monthly Salary: " << m << endl;
    cout << "Employee Yearly Salary: " << y << endl;
    cout << endl << endl;	
}
