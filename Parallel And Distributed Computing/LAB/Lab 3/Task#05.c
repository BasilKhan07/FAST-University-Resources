#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

void A(int array[], int size)
{
	#pragma omp parallel for shared(array)
	for(int s=0; s<(size-1); s++)
	{
		int z=0;
		for(int i=0; i<size-(s-1); i++)
		{
			if(array[i] > array[i+1])
			{	
				#pragma omp critical // so only one thread can enter in this section and to the swapping. 
				{
					int temp = array[i];
					array[i] = array[i+1];
					array[i+1] = temp;
					z=1;
				}
			}
		}
		if(z==0)
		break;
	}

}

int main()
{
	int arr[] = {10, 39, 56, 9, 7, 30};
	A(arr, 6);
	printf("Sorted Array:\n"):
	for(int i=0; i<6; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");	
}
