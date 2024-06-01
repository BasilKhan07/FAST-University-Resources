#include<iostream>

using namespace std;

// O(n^2)
int main()
{
    int arr[10] = {2,5,3,8,9,10,1,4,6,7};
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}