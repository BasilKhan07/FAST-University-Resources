#include<iostream>
#include<string>
using namespace std;

class Book{
	
	public:
	void setName(string x){
		name = x;
	}
	string getName(){
		return name;
	}
	private:
	string name;
};

int main(){
Book book1;
book1.setName("OOP");
cout<<book1.getName();
return 0;
}
