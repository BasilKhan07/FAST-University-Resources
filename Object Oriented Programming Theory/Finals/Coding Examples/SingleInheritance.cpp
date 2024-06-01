// Inheritence
// example 01 , public inheritance example
/*
#include<iostream>
using namespace std;

class Person{
	public:
		int person_id;
		
	
};
// inheriting subclass from base class

class Student:public Person{
	public:
		int std_id;
};

int main(){
	Student s1;
	s1.person_id = 2;
	s1.std_id = 3;
	cout<<"person id is: "<<s1.person_id<<endl;
	cout<<"Student id is: "<<s1.std_id<<endl;
	return 0;
}
*/


/*
// Example 03
// protected can be accessed only in derived classes
#include<iostream>
using namespace std;

class Person{
	public:
		int person_id=2;
	
};

// inheriting subclass from base class

class Student:protected Person{
	public:
		int std_id;
	 Student(){
	 	cout<<"Person id is: "<<person_id<<endl;
	 }	
		
};

int main(){
	Student s1;
	s1.std_id = 3;
	cout<<"Student id is: "<<s1.std_id<<endl;
	return 0;
}*/


// Example 04
// private inheritance
#include<iostream>
using namespace std;

class Person{
	public:
		int person_id=2;
	
};

// inheriting subclass from base class

class Student:private Person{ // person_id is accessable in derived class only
	public:
		int std_id;
	 Student(){
	 	cout<<"Person id is: "<<person_id<<endl; 
	 }	
		
};

int main(){
	Student s1;
	s1.std_id = 3;
//	s1.person_id;
	cout<<"Student id is: "<<s1.std_id<<endl;
	return 0;
}


//Example 05
// Multiple inheritance

/*#include<iostream>
using namespace std;

class Teacher{
	public:
		int teacher_id;
	Teacher(){
		cout<<"Teaching oop"<<endl;
	}
	
};


/*
class Student{ 
	public:
		int std_id;
	 Student(){
	 	cout<<"Student attned the lectures"<<endl;
	 }	
};

// inheriting subclass from base class teacher and student
class PhdStudent: public Teacher, private Student{
	public:
	PhdStudent(){
		teacher_id = 3;
	    std_id = 1;
	    cout<<"student id can be accesed in class: "<<std_id<<endl;
	}
	
};
		


int main(){
	PhdStudent s1;
	cout<<"Teacher id is: "<<s1.teacher_id<<endl;
//	cout<<"Student id is: "<<s1.std_id<<endl;
	return 0;
}*/

// Base class
/*class Employee {
  protected: // Protected access specifier
    int salary;
};

// Derived class
class Programmer: public Employee {
  public:
    int bonus;
    void setSalary(int s) {
      salary = s;
    }
    int getSalary() {
      return salary;
    }
};

int main() {
  Programmer myObj;
  myObj.setSalary(50000);
  myObj.bonus = 15000;
  cout << "Salary: " << myObj.getSalary() << "\n";
  cout << "Bonus: " << myObj.bonus << "\n";
  return 0;
}*/

