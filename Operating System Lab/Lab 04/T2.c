#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
int main() {
pid_t pid; pid = fork(); if(pid == 0) {
printf("I am child and my parent is %d and my own PID is %d\n", getppid(), getpid());
}
else if(pid > 0) {
printf("I am a Parent and my pid is %d\n", getpid());
}
return 0;}
