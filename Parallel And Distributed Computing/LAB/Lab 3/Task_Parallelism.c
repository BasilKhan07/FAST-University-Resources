#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int tid,ans;
    int num1= 5,num2=5;
    
    omp_set_num_threads(3);
    #pragma omp parallel private(tid) 
    {   
        #pragma omp single 
        {
            tid = omp_get_thread_num();
            ans = num1*num2;
            printf("Multiplication = %d by Thread: %d \n",ans, tid);
        }
        
        #pragma omp single 
        {
            tid = omp_get_thread_num();
            ans = num1+num2;
            printf("Summation = %d by Thread: %d\n",ans, tid);
        }
        
        #pragma omp single 
        {
            tid = omp_get_thread_num();
            ans = num1/num2;
            printf("Division = %d by Thread: %d \n",ans, tid);
        }    
    }
    return 0;
}
