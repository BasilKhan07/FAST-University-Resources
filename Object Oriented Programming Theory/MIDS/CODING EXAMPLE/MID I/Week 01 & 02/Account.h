#include<iostream>
using namespace std;
class Account
{
	public:
		void setName(string accountName){
			name = accountName;
		}
		string getName(){
			return name;
		}
	private:
		string name;
};
