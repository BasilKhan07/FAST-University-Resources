#include<iostream>
#include<cmath>
#include<cctype>

using namespace std;

void showChoices();
void metersAndCentTofeetAndInches(double meters, double cents, double &feet, double &inches);
void feetAndInchesToMetersAndCent(double feet, double inches, double &meters, double &cent);

int main()
{
	int choice;
	double n1, n2, n3, n4;
	showChoices();
	cin >> choice;
	if (choice == -1)
	{
		exit(0);
	} 
	else if (choice == 1) 
	{
		cout << "Meters and centimeters to feet and inches" << endl;
		cout << "Enter Meter value: " << endl;
		cin >> n1;
		cout << "Enter Feet value: " << endl;
		cin >> n2;
		metersAndCentTofeetAndInches(n1,n2,n3,n4);
		cout << " Meters = " << n1 << " Centimeters = " << n2 << " Feet = " << n3 << " Inches = " << n4 << endl;
	}
	else if (choice == 2) 
	{
		cout << "Feet and inches to meters and centimeters" << endl;
		cout << "Enter Feet value: ";
		cin >> n1;
		cout << "Enter Inches value: ";
		cin >> n2;
		feetAndInchesToMetersAndCent(n1,n2,n3,n4); 
		cout << " Feet = " << n1 << " Inches = " << n2 << " Meters = " << n3 << " Cents = " << n4 << endl;
	}
	else 
	{
		cout << "Enter Valid choice!!" << endl;
	}
}

void showChoices()
{
	cout << "1 - Meters and Centimeters to Feet and Inches" << endl;
	cout << "2 - Feet and Inches to Meters and Centimeters" << endl;
	cout << "0 - Exit" << endl;
}

void metersAndCentTofeetAndInches(double meters, double cents, double &feet, double &inches) 
{
	feet = meters * 3.28084;
	inches = cents * 0.393701;
}

void feetAndInchesToMetersAndCent(double feet, double inches, double &meters, double &cent) 
{
	meters = feet * 0.3048;
	cent = inches * 2.54;
}


