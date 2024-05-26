#include<iostream>
#include<iomanip>

using namespace std; 

double billCalculation(int n1, int n2, double n3);

int main()
{
	int income, consultinGMinutes;
	double hourlYRate, bill;
	cout << "Enter Income: " << endl;
	cin >> income;
	cout << "Enter Consulting Time in Mintes: " << endl;
	cin >> consultinGMinutes;
	cout << "Enter Hourly Rate: " << endl;
	cin >> hourlYRate;
	bill = billCalculation(income,consultinGMinutes,hourlYRate);
	cout << "Total Bill: $ " << fixed << setprecision(2) << bill << endl; 
}

double billCalculation(int n1, int n2, double n3)
{
	double bill;
	if(n1<25000)
	{
		if(n2<=30)
		{
			return 0;
		}
		else
		{
			bill = n3 * 0.40 * ((double)(n2-30)/60);
			return bill;
		}
	}
	else
	{
		if(n2<=20)
		{
			return 0;
		}
		else
		{
			bill = n3 * 0.70 * ((double)(n2 - 20)/60);
			return bill;
		}
	}
}
