#include<iostream>

using namespace std;

bool RatMaze(int arr1[4][4], int x, int y, int size, int arr2[4][4])
{
	if( (x==size-1) && (y==size-1) )
	{
		arr2[x][y] = 1;
		return true;
	}
	
	bool checkarray;
	if(x<size && y<size && arr1[x][y]==1)
	{
		checkarray = true;
	}
	else
	{
		checkarray = false;
	}
	
	if(checkarray)
	{
		arr2[x][y]=1;
		if(RatMaze(arr1,x+1,y,size,arr2))
		{
			return true;
		}
		if(RatMaze(arr1,x,y+1,size,arr2))
		{
			return true;
		}
		arr2[x][y]=0;
		return false;	
	}
	return false;
}

int main()
{
	int GivenMaze[4][4] = {{1,1,0,1},
	                       {0,1,1,1},
					       {0,1,1,1}};
					 
	int SolutionMaze[4][4];
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			SolutionMaze[i][j]=0;
		}
		cout << endl;
	}
	
	RatMaze(GivenMaze,0,0,4,SolutionMaze);
	
	cout << "Given Maze: " << endl;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout << GivenMaze[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "Solution Maze: " << endl;
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout << SolutionMaze[i][j] << " ";
		}
		cout << endl;
	}
}
