#define N 4
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stddef.h>
#include "mpi.h"

void print_results(int ans[N]);

int main(int argc, char *argv[])
{
    int rank, size;
    int arr[N]= {1,2,3,4};
    int buff;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 4)
    {
    	printf("Meant to be run with 4 processes.\n");
    	MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   
    MPI_Scatter(&arr, 1, MPI_INT, &buff, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    printf("Rank %d have : %d.\n", rank, buff);
    buff = buff + (rand() % 1000);
    MPI_Gather(&buff, 1, MPI_INT, &arr, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);  
    MPI_Finalize();
    if (rank == 0)
    {                   
            printf ("\nPrinting Result After adding random number: \n");
    		for (int i = 0; i < N; i++) 
    		{
    			printf("%d ", arr[i]);
    		}
    		printf("\n");
	}
}
