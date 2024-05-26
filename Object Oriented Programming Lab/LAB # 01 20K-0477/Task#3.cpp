#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct menuitemtype{
	char menuitem[8][20]={"Plain Egg", "Bacon and Egg", "Muffin", "French Toast ", "Fruit Basket", "Cereal", "Coffee", "Coffee"};
	double menuprice[8]={1.45, 2.45, 0.99, 1.99, 2.49, 0.69, 0.50, 0.75};
	};
main()
{
	menuitemtype m;
	int num,i,choice,price;
	float total=0;
	string name;
	cout << "Welcome to Johnny's Restaurant" << endl;
    for(i=0;i<8;i++)
    {
    	cout << i+1 << ". " << m.menuitem[i] << ": " <<  m.menuprice[i] << endl;
    }
	cout<<"How many items do you want:";
	cin>>num;
	
	
	for(i=0;i<num;i++)
	{
		cout<<"Enter the the choice you want: ";
		cin>>choice;
		total=total+m.menuprice[choice];
	}
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout<<"The total is: "<<total;
}
