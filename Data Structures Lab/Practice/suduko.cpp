#include<iostream>

using namespace std;

void display(int box[9][9])
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)   
		{
			cout << box[i][j] << " ";
		}
		cout << endl;
	}
}

bool CheckBox(int box[9][9], int row, int col, int val)
{
    for(int i=0; i<9; i++)
    {
        if(box[row][i] == val)
        {
            return false;
        }
    }
    for(int i=0; i<9; i++)
    {
        if(box[i][col] == val)
        {
            return false;
        }
    }
    int subrow = (row/3)*3;
    int subcol = (col/3)*3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(box[subrow+i][subcol+j]==val)
            {
                return false;
            }
        }
    }
    return true; 
}

void SolveSuduko(int box[9][9], int row, int col)
{
    if(row==9)
    {
        display(box);
        return;
    }
    int nrow = 0;
    int ncol = 0;
    if(col == 8) // If at extreme column then new row and column will be zero.
    {
        nrow = row+1;
        ncol = 0;
    }
    else
    {
        nrow = row; // else same row and next column
        ncol = col+1;
    }
    if(box[row][col]!=0) // If non zero number then new recursice call for row and column.
    {
        SolveSuduko(box, nrow, ncol); 
    }
    else
    {
        for(int p_option=1; p_option<=9; p_option++)
        {
            if(CheckBox(box, row, col, p_option) == true)
            {
                box[row][col] = p_option;
                SolveSuduko(box, nrow, ncol);
                box[row][col] = 0; // Backtracking
            }
        }
    }
}

int main()
{
    int arr[9][9] = {{3,0,6,5,0,8,4,0,0},
	                {5,2,0,0,0,0,0,0,0},
					{0,8,7,0,0,0,0,3,1},
					{0,0,3,0,1,0,0,8,0},
					{9,0,0,8,6,3,0,0,5},
					{0,5,0,0,9,0,6,0,0},
					{1,3,0,0,0,0,2,5,0},
					{0,0,0,0,0,0,0,7,4},
					{0,0,5,2,0,6,3,0,0}};
    SolveSuduko(arr, 0, 0);
}