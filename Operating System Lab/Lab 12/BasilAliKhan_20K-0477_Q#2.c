#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int signum)
{
	if (signum == SIGTERM)
	{
		printf("Ignoring SIGTERM\n");
	}
	else if (signum == SIGTSTP)	
	{
		printf("Ignoring SIGTSTP\n");
	}
}

int main(void)
{
	printf("Process ID:%d \n",getpid());
	signal(SIGTERM, handler);	
	signal(SIGTSTP, handler);
	while(1)
	{	
		sleep(1);
	}
	return 0;
}
