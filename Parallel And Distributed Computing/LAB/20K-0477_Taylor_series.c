#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    float num, base, denominator[10], numerator[10], sum;
    int i, n, j, t;
    printf("Enter value for exp function: ");
    scanf("%f", &num);
    #pragma omp parallel num_threads(4) 
    {
    	#pragma omp for
    	for (i=0; i<10; i++) 
    	{
        	for (int k=0; k<=i; k++) // For calculating power value..
        	{
        	    if (k==0)
        	    {
                	num=1;
                }
            	else
            	{
                	numerator[i] = pow(num, i);
                }
        	}
        }
    	#pragma omp for
        for (n=1; n<10; n++)  // For calculating factorial..
        {
            base = 1;
            for (t=n; t>0; t--)
            {
                base = base * t;
            }
            denominator[n] = base;
        }
    	#pragma omp for 
        for (j=0; j<10; j++)  // Summing above 2 results..
        {
            sum = sum + (numerator[j] / denominator[j]);
		}
	}
    printf("\nValue of exp(%.2f) is : %f", num, sum);
}
