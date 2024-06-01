#include<iostream>

using namespace std;

int Partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}

void QuickSort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int key = Partition(arr, lb, ub);
        QuickSort(arr, lb, key-1);
        QuickSort(arr, key+1, ub);
    }
}

int main()
{
    int arr[10] = {2,5,3,8,9,10,1,4,6,7};
    QuickSort(arr, 0, 9);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}