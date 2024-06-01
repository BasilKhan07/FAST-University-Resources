#include<iostream>

using namespace std;



int main()
{
    int **arr = new int*[3];
    int size[3];
    for(int i=0; i<3; i++)
    {
        cout << "Row " << i+1 << " size: ";
        cin >> size[i];
        arr[i] = new int[size[i]];
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<size[i]; j++)
        {
            cout << "Enter row " << i+1 << " element: ";
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<3; i++)
    {
        cout << "Row " << i+1 << " element: ";
        for(int j=0; j<size[i]; j++)
        {
            cout << arr[i][j] << " ";
        } 
        cout << endl;
    }

}