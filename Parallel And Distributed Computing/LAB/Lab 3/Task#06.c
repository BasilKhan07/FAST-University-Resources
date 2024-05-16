#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>

int main()
{
	float t1, t2;
	t1 = omp_get_wtime();
	int A[4],AA[4],AAA[4];
	int tid;
	#pragma omp parallel for schedule(dynamic,1) num_threads(4)
	// Using Dynamic Scheduling each thread fills a single index of each array.
	for(int i=0; i<4; i++)
	{
		tid = omp_get_thread_num();
		printf("Index %d filled By Thread id : %d\n",tid,tid);
		A[tid] = rand(); 
		AA[tid] = rand();
		AAA[tid] = rand();
	}
	
	t2 = omp_get_wtime();
	printf("\nTotal time taken : %f\n\n", t2 - t1);
	
	
	printf("\nArray A : ");
	for(int i=0; i<4; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\nArray AA : ");
	for(int i=0; i<4; i++)
	{
		printf("%d ", AA[i]);
	}
	
	printf("\nArray AAA : ");
	for(int i=0; i<4; i++)
	{
		printf("%d ", AAA[i]);
	}
	printf("\n");
}
