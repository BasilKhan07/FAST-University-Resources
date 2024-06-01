#include<iostream>

using namespace std;

int Fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int fib = Fib(n-1) + Fib(n-2);
    return fib;
}

int main()
{
    cout << Fib(5);
}