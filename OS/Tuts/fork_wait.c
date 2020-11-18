#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int status;
	printf("Hello World\n");
	pid = fork();
	if(pid == 0)
	{
		printf("I am the child process %d\n",getpid());
		printf("I am the child process %d\n",getpid());
		printf("I am the child process %d\n",getpid());
	}
	else
	{
		printf("Kya Hua\n");
		printf("Here\n");
		wait(&status);
		printf("child process %d terminates\n", pid);
		printf("Bye\n");
	}
}