#include<stdio.h>
#include<signal.h>
#include<wait.h>
#include<unistd.h>

void handler(int signo)
{
	if(signo == SIGUSR1)
	{
		printf("RECEIVED SIGUSR1\n");
	}
	else if(signo == SIGKILL)
	{
		printf("RECEIVED SIGKILL\n");
	}
	else if(signo == SIGSTOP)
	{
		printf("RECEIVED SIGSTOP\n");
	}	
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	if(sigaction(SIGINT, &sa, NULL) == SIG_ERR)
	{
		printf("\nCant catch SIGUSR1\n");
	}
	if(sigaction(SIGKILL, &sa, NULL) == SIG_ERR)
	{
		printf("\nCant catch SIGKILL\n");
	}
	if(sigaction(SIGSTOP, &sa, NULL) == SIG_ERR)
	{
		printf("\nCant catch SIGSTOP\n");
	}
	while(1)
	{
		sleep(1);
	}
	return 0;
}
