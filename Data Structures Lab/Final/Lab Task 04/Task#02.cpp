#include<iostream>

using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int main()
{
	int List[]={5, 3, 8, 1, 4, 6, 2, 7, 10, 9};
	int size = sizeof(List)/sizeof(int);
    QuickSort(List, 0, size-1);
    cout << "Sorted Array Using Quick Sort: " << endl << endl;
    for (int i=0; i < size; i++)
    {
    	cout << List[i] << " ";
	}
}
