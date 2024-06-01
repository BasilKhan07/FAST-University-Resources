#include<iostream>

using namespace std;

int add(int num)
{
    if(num==0)
    {
        return 0;
    }
    int sum = num + add(num-1);
    return sum;
}

int main()
{
    int n = 6;
    cout << add(n);
}