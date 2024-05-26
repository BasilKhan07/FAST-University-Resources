#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 2000

int main(){
key_t key = ftok("shmfile", 65);
int shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666);
char *shm = shmat(shmid, (void *)0, 0);
printf("The number recived is: %s\n",shm);
int num = atoi(shm);      //// there must error atol(str)

*shm = 'r';
	while(*shm != '*')
	{
		sleep(1);
	}
printf("recived symbol %s\n", shm);
printf("Table of entered numbers:");
	for(int count = 1; count <= 10 ; count++)
	{
		printf("%d\n",count *num);
	}
shmdt(shm);
return 0;
}
