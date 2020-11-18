#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;

	if(fork() == 0)
	{
		if(fork() == 0)
		{
			printf("P");
		}
		else
		{
			pid = wait(&status);
			printf("H");
		}
	}
	else
	{
		if(fork() == 0)
		{
			printf("G");
			exit(0);
		}
		printf("D");
	}
	printf("B");
	return 0;
}