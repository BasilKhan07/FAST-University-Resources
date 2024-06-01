#include<iostream>

using namespace std;

int power(int num, int p)
{
    if(p==0)
    {
        return 1;
    }
    int product = num * power(num, p-1);
    return product;
}

int main()
{
    cout << power(4, 3);
}