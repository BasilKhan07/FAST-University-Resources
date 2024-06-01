int main(){
	int n;
	cin>>n;
	int** arr=new int*[n];
	for(int i=0; i<n;i++){
		
		arr[i]=new int[n];
		
	}
		for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
		
		cin>>arr[i][j];
		
	}
}
	int** SolArr=new int*[n];
	for(int i=0; i<n;i++){
		SolArr[i]=new int[n];
		for(int j=0; j<n;j++){
		SolArr[i][j]=0;
		
		
	}
}
	if(ratinMaze,0,0,n,SolArr){
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				cout<<SolArr[i][j]<<" ";
			}cout<<endl;
			
		}
		
		
		
	}
	
	return 0;
	
}