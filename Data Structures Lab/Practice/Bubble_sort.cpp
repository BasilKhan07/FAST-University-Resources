#include<iostream>

using namespace std;

int main()
{
    int arr[10] = {2, 5, 14, 4, 8, 9, 7, 1, 0, 6};
    cout << "Bubble Sort: " << endl;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(arr[i]<arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}