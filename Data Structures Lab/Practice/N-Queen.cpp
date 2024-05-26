#include<iostream>

using namespace std;

bool IsSafe(int arr[4][4], int x, int y, int n)
{
    for(int row=0; row<x;  row++) // For checking queen is place in that row.
    {
        if(arr[row][y]==1)
        {
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0) // For checking upper left daignol if queen is place.
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = x;
    col = y;
    while(row>=0 && col<n) // For checking upper right daignol if queen is place.
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true; // if no queen is place in that row
}

bool nQueen(int arr[4][4], int x, int n)
{
    if(x>=n)
    {
        return true;
    }
    for(int col=0; col<n; col++)
    {
        if(IsSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if(nQueen(arr, x+1, n))
            {
                return true;
            }
            arr[x][col] = 0; // Backtracking
        }
    }
    return false;
}

int main()
{
    int arr[4][4]= {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    if(nQueen(arr, 0, 4))
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

}