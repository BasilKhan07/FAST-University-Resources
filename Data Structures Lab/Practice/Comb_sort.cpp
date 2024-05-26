#include<iostream>

using namespace std;

int main()
{
    int arr[10] = {2, 5, 14, 4, 8, 9, 7, 1, 0, 6};
    cout << "Comb Sort: " << endl;
    int gap = 10;
    bool swapped = false;
    const float shrink_factor = 1.3;
    while(gap>1 || swapped == true)
    {
        swapped = false;
        gap = int(gap/shrink_factor);
        for(int i=0; i<(10-gap); i++)
        {
            if(arr[i]>arr[i+gap])
            {
                swap(arr[i], arr[i+gap]);
                swapped = true;            }
        }
    }

    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
}