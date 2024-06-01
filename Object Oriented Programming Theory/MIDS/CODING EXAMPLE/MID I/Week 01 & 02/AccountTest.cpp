#include<iostream>
#include"Account.h"
using namespace std;
int main(){
	Account myAccount;
	cout<<"The initial account name is:\n defualt \n"<< myAccount.getName();
	
	cout<<"Enter the account name:\n";
	string theName;
	getline(cin,theName);
	myAccount.setName(theName);
	cout<<"the name in object myAccount is:\n"<< myAccount.getName()<<endl; 
	
}
