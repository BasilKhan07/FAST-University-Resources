#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

int main()
{
	int tid, sum=0, n=10;
	int array[]={2, 4, 6, 4, 3, 2, 3, 9, 10, 12};
	
	omp_set_num_threads(6);
	
	#pragma omp parallel for
		for(int i=0; i<n; i++)
		{
			sum = sum + array[i];
			printf("Partial Sum = %d By Thread:  %d\n", sum, omp_get_thread_num());
		}
	
	printf("Total Sum = %d\n",sum);
}
