#include<iostream>

using namespace std;
// Time complexity = O(Log n)
int Binarysearch(int arr[], int left, int right, int val)
{
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid] == val)
        {
            return mid;
        }
        else if(arr[mid] < val)
        {   
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{   
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << Binarysearch(arr, 0, 9, 11);
}