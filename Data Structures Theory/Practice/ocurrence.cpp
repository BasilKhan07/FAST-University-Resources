#include<iostream>

using namespace std;

int firstoccur(int arr[], int size, int i, int val)
{
    if(i==size)
    {
        return -1;
    }
    if(arr[i] == val)
    {
        return i;
    }
    return firstoccur(arr, size, i+1, val);
}

int main()
{
    int arr[7] = {4, 2, 1, 2, 5, 2, 7};
    cout << firstoccur(arr, 7, 0, 7);
}