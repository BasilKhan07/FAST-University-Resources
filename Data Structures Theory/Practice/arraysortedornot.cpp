#include<iostream>

using namespace std;

bool sort(int arr[], int size)
{
    if(size==1)
    {
        return true;
    }
    bool restarray = sort(arr+1, size-1);
    return arr[0] < arr[1] && restarray;
}

int main()
{
    int array[5] = {3, 3, 3, 3, 3};
    if(sort(array, 5))
    {
        cout << "Array is sorted." << endl;
    }
    else
    {
        cout << "Array not sorted. " << endl;
    }
}