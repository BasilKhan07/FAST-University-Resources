#include<iostream>
#include<cmath>
#include<iomanip>
#define PI 3.142

using namespace std;

float distance(float n1, float n2, float n3, float n4);
float radius(float n1, float n2, float n3, float n4);
float circumference(float n1);
float area(float n1);

int main()
{
	float x1, y1 , x2, y2, r, c, a;
	cout << "Enter Center Points of Circle: " << endl;
	cin >> x1 >> y1;
	cout << "Enter Point on Circle: " << endl;
	cin >> x2 >> y2;
	r = radius(x1,y1,x2,y2);
	cout << fixed;
	cout << "Radius of Circle is: " << setprecision(2) << r << endl;
	c = circumference(r);
	cout << "Circumference of Circle: " << setprecision(2) << c << endl;
	a = area(r);
	cout << "Area of Circle is: " << setprecision(2) << a << endl; 
}

float radius(float n1, float n2, float n3, float n4)
{
	float r;
	r = distance(n1,n2,n3,n4);
	return r;
}

float distance(float n1, float n2, float n3, float n4)
{
	float dis, ans;
	ans = pow((n3-n1),2) + pow((n4-n2),2);
	dis = sqrt(ans);
	return dis;
}

float circumference(float n1)
{
	float c;
	c = 2 * PI * n1;
	return c;
}

float area(float n1)
{
	float a;
	a = PI * pow(n1,2);
	return a;
}
