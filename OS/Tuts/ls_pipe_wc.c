#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd[2],pid;
	pipe(fd);

	if(!fork())
	{
		dup2(fd[1],1);
		close(fd[0]);
		execlp("ls","ls",NULL);
	}
	else
	{
		dup2(fd[0],0);
		close(fd[1]);
		execlp("wc","wc","-l",NULL);
	}
	return 0;
}