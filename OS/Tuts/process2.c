#include <stdio.h>
#include <fcntl.h>

int main()
{
	int pid;
	printf("******Before Fork******\n");
	system("ps");
	pid = fork();
	if(pid == 0)
	{
		printf("****after fork*****\n");
		printf("child pid=%d\n",pid );
	}
	else
	{
		printf("parent pid = %d\n",pid );
		printf("Hello\n");
		system("ps");
		// wait();
	}	

	return 0;
}