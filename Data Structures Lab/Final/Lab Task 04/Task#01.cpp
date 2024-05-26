#include<iostream>

using namespace std;

void Display(int arr[], int size)
{
	for(int i=0; i<size; i++)
		{
			cout << arr[i] << " ";
		}
}

void BubbleSort(int arr[], int size)
{
	system("cls");
	cout << endl << "Bubble Sort: " << endl << endl;
	for(int i=0; i<size-1; i++)
		{
			for(int j=0; j<size; j++)
				{
					if(arr[j]>arr[j+1])
					{
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
		}
}

void InsertionSort(int arr[], int size)
{
	system("cls");
	cout << endl << "Insertion Sort: " << endl << endl;
	for(int i=1; i<size; i++)
		{
			int temp = arr[i];
			int j;
			for(j=i-1; j>=0 && arr[j]>temp; j--)
			{
				arr[j+1]= arr[j];
			}
			arr[j+1] = temp;
		}
}

void SelectionSort(int arr[], int size)
{
	system("cls");
	cout << endl << "Selection Sort: " << endl << endl;
	for(int i=0; i<size-1; i++)
	{
		int min=i;
		for(int j=i+1; j<size; j++)
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
}

void CombSort(int arr[], int size)
{
	system("cls");
	cout << endl << "Comb Sort: " << endl << endl;
	int gap = size;
	bool swapped = false;
	const float SHRINK_FACTOR = 1.3;
	while(gap > 1 || swapped == true)	
	{
		swapped = false;
		gap = int(gap / SHRINK_FACTOR);
		for(int i=0; i<(size-gap); i++)
		{
			if(arr[i]>arr[i+gap])
			{
				swap(arr[i],arr[i+gap]);
				swapped = true;
			}
		}
		
	} 
}

int main()
{
	int List[]={5, 3, 8, 1, 4, 6, 2, 7, 10, 9};
	int size, choice, temp;
	size = sizeof(List)/sizeof(int);
	cout << "***** SORTING ******" << endl << endl;
	cout << "1 -> Bubble Sort. " << endl;
	cout << "2 -> Insertion Sort. " << endl;
	cout << "3 -> Selection Sort. " << endl;
	cout << "4 -> Comb Sort. " << endl << endl;
	cout << "List: " << endl;
	Display(List, size);
	cout << endl << endl << "Which sorting to use to sort above List ?: ";	
	cin >> choice;
	switch(choice)
	{
		case 1:
			{
				BubbleSort(List, size);			
				Display(List, size);
				break;
			}
		case 2:
			{
				InsertionSort(List, size);
				Display(List, size);
				break;
			}
		case 3:
			{
				SelectionSort(List, size);
				Display(List, size);
				break;
			}
		case 4:
			{
				CombSort(List, size);
				Display(List, size);
				break;
			}
		default:
			{
				cout << endl << "Invalid Choice for sorting!!!! " << endl;
				break;
			}
	}
}
