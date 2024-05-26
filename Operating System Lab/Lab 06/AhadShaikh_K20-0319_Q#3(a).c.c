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
printf("Enter the number > ");
fgets(shm, MAXSIZE, stdin);
	while(*shm != 'r')
	{
		sleep(1);
	}
printf("recived ready signal.....\n");
shm = "*";
shmdt(shm);
return 0;
}
