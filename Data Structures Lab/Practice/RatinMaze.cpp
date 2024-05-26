#include<iostream>

using namespace std;

bool IsSafe(int arr[5][5], int x, int y, int n)
{
    if(x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
    return false;
}

bool RatInMaze(int arr[5][5], int x, int y, int n, int solarr[5][5])
{
    if(x==n-1 && y==n-1)
    {
        solarr[x][y] = 1;
        return true;
    }
    if(IsSafe(arr, x, y, n))
    {
        solarr[x][y] = 1; 
        if(RatInMaze(arr, x+1, y, n, solarr))
        {
            return true;
        }
        if(RatInMaze(arr, x, y+1, n, solarr))
        {
            return true;
        }
        solarr[x][y]=0;
        return false;
    }
    return false;
}

int main()
{
    int arr[5][5] = {{1, 0, 1, 0, 1}, 
                     {1, 1, 1, 1, 1},
                     {0, 1, 0, 1, 0},
                     {1, 0, 0, 1, 1},
                     {1, 1, 1, 0, 1}};
    int solarr[5][5] = {0};
    if(RatInMaze(arr, 0, 0, 5, solarr))
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                cout << solarr[i][j] << " ";
            }
            cout << endl;
        }
    }
}