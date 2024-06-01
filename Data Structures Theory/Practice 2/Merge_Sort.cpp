#include<iostream>

using namespace std;

void Merge(int arr[], int lb, int mid, int ub)
{
    int brr[10];
    int i = lb;
    int j = mid+1;
    int k = lb;
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            brr[k] = arr[i];
            i++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            brr[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
              brr[k] = arr[i];
              i++;
              k++;  
        }
    }
}

void MergeSort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid+1, ub);
        Merge(arr, lb, mid, ub);
    }
}

int main()
{
    int arr[10] = {2,5,3,8,9,10,1,4,6,7};
    MergeSort(arr, 0, 9);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}
