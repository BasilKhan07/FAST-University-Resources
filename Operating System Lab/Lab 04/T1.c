#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
int i = 5;
pid_t pid;
void parent_process();
void child_process();
int main() {

pid = fork();
if(pid == 0) {
i += 10;
child_process();
}
else {
parent_process();
}
return 0;
}
void parent_process() {
printf("I am a parent process and my value of 'i' is %d  %d \n",i, (int) getpid());
}
void child_process() {
printf("I am a child process and my value of 'i' is %d  %d  %d \n",i, (int) getpid(), (int) getppid());
}
