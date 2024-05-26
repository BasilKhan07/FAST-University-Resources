#include<iostream>

using namespace std;

int main()
{
    int arr[10] = {2, 5, 14, 4, 8, 9, 7, 1, 0, 6};
    cout << "Selection Sort: " << endl;
    int i, j;
    for(i=0; i<10; i++)
    {
        int min = i;
        for(j=i+1; j<10; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}