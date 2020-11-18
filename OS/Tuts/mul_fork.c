#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int i= 0;
	int pid;
	// for(i = 0; i < 3; i++)
	// {
	// 	pid = fork();
	// 	if(pid == 0)
	// 		continue;
	// 	else
	// 		break;
	// }
	//printf("Process: %d\n", getpid());

	// if(fork() && (!fork()))
	// {
	// 	if(fork() || fork())
	// 		fork();
	// }
	// printf("2\n");

	if(fork())
	{
		if(!fork())
		{
			fork();
			printf("1");
		}
		else
			printf("2");
	}
	else
	{
		printf("3");
	}
	printf("4");
	return 0;
}