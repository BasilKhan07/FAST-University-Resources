#include<iostream>
#include<string>
using namespace std;

class Book{
	public:
	void setName(string x ){
		name = x;
		
		
	}
	void setRollNo(int aRollNo){
		rollNo = aRollNo;
	}
	string getName(){
		return name;
		
    }
    int getRollNo(){
    return rollNo;	
	}

	
	private:
	string name, lastName;
	int rollNo;
};

int main(){
Book book1;
book1.setName("OOP" );
book1.setRollNo(123);
cout<<"Here is the student name: \n"<<book1.getName();
cout<<"\n Here is the student roll number:\n"<<book1.getRollNo();
return 0;
}
