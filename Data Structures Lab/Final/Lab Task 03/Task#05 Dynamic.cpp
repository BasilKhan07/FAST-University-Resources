#include<iostream>

using namespace std;

bool isSafe(int arr[4][4],int x,int y,int n){
	if(x<n && y<n && arr[x][y] == 1 ){
		return true;
	}
	else{
		return false;
	}
}
bool mazeRoute(int arr[4][4],int x,int y,int n,int solArr[4][4]){
	if(x==(n-1) && y==(n-1)){
		solArr[x][y] = 1;
		return true;
	}
	if(isSafe(arr,x,y,n)){
		solArr[x][y] = 1;
		if(mazeRoute(arr,x+1,y,n,solArr)){
			return true;
		}
		if(mazeRoute(arr,x,y+1,n,solArr)){
			return true;
		}
		solArr[x][y] = 0;
		return false;
	}
		return false;
}
int main(){
	int i,j;
	int n=4;
	int arr[4][4]={{1,0,0,0},
	                     {1,1,0,1},
						 {0,1,0,0},
						 {1,1,1,1}
						};
	int solArr[4][4];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			solArr[i][j] = 0;
		}
	}
	mazeRoute(arr,0,0,n,solArr);
	cout<<"Maze : "<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl<<"Solution : "<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<solArr[i][j]<<"  ";
		}
		cout<<endl;
	}		
}
