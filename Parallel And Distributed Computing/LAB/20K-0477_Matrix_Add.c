#include<stdio.h>
#include<omp.h>

int main()
{	
	int tid, row1, row2, col1, col2, num_of_threads;
	printf("Enter Rows And Column of Matrix A: ");
	scanf("%d%d", &row1, &col1);
	printf("Enter Rows And Column of Matrix B: ");
	scanf("%d%d", &row2, &col2);
	int i, j, k, a[row1][col1], b[row2][col2], c[row1][col1];
	if((row1 != row2) || (col1 != col2))
	{
		printf("Addition doesnt exist.\n");
		return 0;
	} 
	printf("Enter Matrix A: \n");
	for(int x=0; x<row1; x++)
	{
		for(int y=0; y<col1; y++)
		{
			scanf("%d", &a[x][y]);
		}
	}
	printf("Enter Matrix B: \n");
	for(int x=0; x<row2; x++)
	{
		for(int y=0; y<col2; y++)
		{
			scanf("%d", &b[x][y]);
		}
	}
	printf("\nMatrix A: \n");
	for(int x=0; x<row1; x++)
	{
		for(int y=0; y<col1; y++)
		{
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}
	printf("\nMatrix B: \n");
	for(int x=0; x<row2; x++)
	{
		for(int y=0; y<col2; y++)
		{
			printf("%d ", b[x][y]);
		}
		printf("\n");
	}
	#pragma omp parallel private(tid, i, j, k)
	{
		tid = omp_get_thread_num();
		printf("Thread %d Adding.\n", tid);
		#pragma omp for
		for(i=0; i<row1; i++)
		{
			for(j=0; j<col1; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
			}
		}
	}
	printf("\nResultant Matrix C: \n");
	for(int x=0; x<row1; x++)
	{
		for(int y=0; y<col1; y++)
		{
			printf("%d ", c[x][y]);
		}
		printf("\n");
	}	
}
