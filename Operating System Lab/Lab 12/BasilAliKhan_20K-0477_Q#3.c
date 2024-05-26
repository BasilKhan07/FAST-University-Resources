#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include<unistd.h>

#define NUM_OF_THREADS 5

int arr[10]={4,5,6,7,8,9,10,11,12,1};
int sum=0;

void *Thread(void *id)
{
	alarm(5);
	int n = 10 / NUM_OF_THREADS;
	long tid = (long)id;
	int partial_sum=0;
	printf("Thread %ld working...\n",tid); 
	tid*=n;
	for(long i=tid;i<tid+n;i++)
	{
		partial_sum = partial_sum + arr[i];
	    	sum = sum + arr[i];
	}	
	printf("Thread %ld partial sum: %d\n", tid/n, partial_sum);
	pause();
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid[NUM_OF_THREADS];
	long i; 
	for(i=0; i < NUM_OF_THREADS; i++)
 	{
    		pthread_create(&tid[i], NULL, Thread, (void*)i);
   	}
   	for(i=0; i < NUM_OF_THREADS; i++)
   	{
   		pthread_join(tid[i], NULL);
   	}
	printf("\nSum of array: %d\n", sum);
   	pthread_exit(NULL);
}
