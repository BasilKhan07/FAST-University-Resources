#include<iostream>

using namespace std;

// In insertion sort array would be divided into two subarray one sorte and unsorted.
// 1. We will take one variable from unsorted sublist and we will inset that value in sorted sublist 
// at appropriate position.
// 

int main()
{
    int arr[10] = {2, 5, 14, 4, 8, 9, 7, 1, 0, 6};
    cout << "Insertion Sort: " << endl;
    for(int i=0; i<10; i++)
    {
        int temp = arr[i];
        int j;
        for(j=i-1; j>=0 && arr[j]>temp; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}