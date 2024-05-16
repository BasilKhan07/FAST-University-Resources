#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

int main()
{
	int num1=8,num2=1,num3=4,num4=2,A,B,C,D,E,F;
	
	#pragma omp parallel num_threads(5)
	{
	#pragma omp single nowait
	{
		#pragma omp task depend(out:A)
		{
			A = num1+num1;
			printf("Task A executed By Thread: %d\n", omp_get_thread_num());
		}
		
		#pragma omp task depend(in:A) depend(out:B)
		{
			B = A+num2;
			printf("Task B executed By Thread: %d\n", omp_get_thread_num());
		}
		
		#pragma omp task depend(in:A) depend(out:C)
		{
			C = A+num3;
			printf("Task C executed By Thread: %d\n", omp_get_thread_num());
		}
		
		#pragma omp task depend(in:A) depend(out:D)
		{
			D = A+num4;
			printf("Task D executed By Thread: %d\n", omp_get_thread_num());
		}
		
		#pragma omp task depend(in:B,C)
		{
			E = B+C;
			printf("Task E executed By Thread: %d\n", omp_get_thread_num());
		}
		
		#pragma omp task depend(in:C,D)
		{
			F = C+D*num1;
			printf("Task F executed By Thread: %d\n", omp_get_thread_num());
		}
	
	}
	}
}
