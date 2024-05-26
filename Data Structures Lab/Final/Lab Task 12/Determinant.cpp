#include<iostream>

using namespace std;

int Determinant(int **arr1, int N)
{
    int result = 0;
    if(N == 1)
    {
        return arr1[0][0];
    }
    int **arr2 = new int*[N];
    for(int i=0; i<N; i++)
    {
        arr2[i] = new int[N];
    }
    int s = 1;
    for(int i=0; i<N; i++)
    {
        int j = 0, k = 0;
        for(int r = 0; r<N; r++)
        {
            for(int c=0; c<N; c++)
            {
                if(r != 0 && c != i)
                {
                    arr2[j][k++] = arr1[r][c];
                    if(k == N-1)
                    {
                        k = 0;
                        j++;
                    } 
                }
            }
        }
        result = result + s * arr1[0][i] * Determinant(arr2, N-1);
        s = -s;
    }
    return result;
}

void Display(int **arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int NoOfRowsAndColumn;
    cin >> NoOfRowsAndColumn;
    int **arr = new int*[NoOfRowsAndColumn];
    for(int i=0; i<NoOfRowsAndColumn; i++)
    {
        arr[i] = new int[NoOfRowsAndColumn];
    }
    for(int i=0; i<NoOfRowsAndColumn; i++)
    {
        cout << "Enter Row " << i+1  << " Elements: " << endl;
        for(int j=0; j<NoOfRowsAndColumn; j++)
        {
            cout << "Column " << j+1 << ": ";
            cin >> arr[i][j];
        }
        cout << endl;
    }
    cout << "Matrix: " << endl;
    Display(&*arr, NoOfRowsAndColumn);
    cout << endl << "Determinant Of Matrix: " << Determinant(&*arr, NoOfRowsAndColumn);
}