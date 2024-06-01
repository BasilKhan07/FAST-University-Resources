#include<iostream>

using namespace std;

int factorial(int num)
{
    if(num==0)
    {
        return 1;
    }
    int fact = num * factorial(num-1);
    return fact;
}

int main()
{
    cout << factorial(4);
}