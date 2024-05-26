#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>


int main (){

printf("i am %d \n",(int) getpid());
pid_t pid=fork();
printf("fork returned %d \n",(int) getpid());
printf("i am %d \n",(int) getpid());



return 0;
}
