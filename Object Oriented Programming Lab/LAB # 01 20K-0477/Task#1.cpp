#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int weight_in_kg;
	float weight_in_pound;
	cout << "Enter Weight in Kilogram : ";
	cin >> weight_in_kg;
	weight_in_pound = weight_in_kg * 2.2;
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Weight in Pound : " << weight_in_pound << endl;
	return 0;
}