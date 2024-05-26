#include<iostream>

using namespace std;

int main()
{
	float **courses = new float*[5];
	courses[0] = new float[5]{3.66, 3.33, 4.0, 3.0, 2.66};
	courses[1] = new float[4]{3.33, 3.0, 3.66, 3.0};
	courses[2] = new float[3]{4.0, 3.66, 2.66};
	courses[3] = new float[3]{2.66, 2.33, 4.0};
	courses[4] = new float[5]{3.33, 3.66, 4.0, 3.0, 3.33};
	int NOC;
	for(int i=0; i<5; i++)
	{
		
		float totalpoints = 0, totalgradepoints = 0;
		int credithours = 1;
		float GPA;
		string name;
		cout << "Enter name of Student: ";
		cin >> name;
		cout << "Enter Number of courses enroll: ";
		cin >> NOC;
		for(int j=0; j<NOC; j++)
		{
			totalpoints += courses[i][j];
			totalgradepoints = totalpoints * 3;
			credithours = NOC * 3;
			GPA = totalgradepoints/credithours;
		}
		cout << "Total points: " << totalgradepoints << endl;
		cout << "Total credit hours: " << credithours << endl;
		cout << "GPA: " << GPA << endl;
		cout << endl;
	}
}
