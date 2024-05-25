#include<stdio.h>
int main () 
{
	int i,j, prime;
	int count = 0;
    for (i=2; i<1000000; i++) 
    {
        prime=1;
        
        for (j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
            {
                prime=0;
                break;    
            }
        }   
        if(prime == 1) {
		printf("%d \n",i);
		count++;	
	}
    }
    printf("\nNumber of Primes%d",count);
    return 0;
}
