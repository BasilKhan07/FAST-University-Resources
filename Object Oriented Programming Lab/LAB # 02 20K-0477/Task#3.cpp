#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int account_no, rmu, pdm, pnm;
    float totalBill = 0;
    char choice;
    float regular_acc_fee = 10.00, regular_rate = 0.20, premium_acc_fee = 25.00, premium_day_rate = 0.10, premium_night_rate = 0.05;
    cout << "Please Enter an Account Number" << endl;
    cin >> account_no;
    cout << "P or p - Premium Service" << endl;
    cout << "R or r - Regular Service" << endl;
    cin >> choice;
    if(choice == 'P' || choice == 'p')
    {
    	    cout << "Please enter the number of day minutes used: ";
            cin >> pdm;
            cout << "Please enter the number of night minutes used: ";
            cin >> pnm;
            if (pdm > 75) 
			{
                totalBill = (pdm - 75) * premium_day_rate;
            }
            if (pnm > 100) 
			{
                totalBill = (pnm - 100) * premium_night_rate;
            }
            totalBill += premium_acc_fee;
	}
	else if(choice == 'R' || choice == 'r')
	{
		    cout << "Please enter the number of minutes used: ";
            cin >> rmu;
            if (rmu > 50) 
			{
				totalBill = ((rmu - 50) * regular_rate) + regular_acc_fee;
            } 
			else 
			{
                totalBill = regular_acc_fee;
            }
	}
	else
	{
		cout << "Invalid Service Code!!" << endl;
	}
	cout << "Total Bill: $ " << totalBill << endl;

}


