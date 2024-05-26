#include<iostream>

using namespace std;

int func(int a, int b)
{
    return a * b;
}

int func(int a, int b, int c)
{
    return a * b * c;
}

float func(float a, float b)
{
    return a * b;
}

float func(float a, float b, float c)
{
    return a * b * c;
}

int main()
{
    cout << "Result of function taking two integer input: " << func(3, 4) << endl;
    cout << "Result of function taking three integer input: " << func(2, 3, 4) << endl;
    cout << "Result of function taking two decimal input: " << func(2.3f, 5.4f) << endl;
    cout << "Result of function taking three decimal input: " << func(3.1f, 2.3f, 4.3f) << endl;
}