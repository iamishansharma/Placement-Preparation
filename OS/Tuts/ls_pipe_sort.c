#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd[2],newfd;
	pipe(fd);
	printf("Hello\n");
	// if ((newfd = open("test.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
	// 	perror("test.txt"); /* open failed */
	// 	exit(1);
	// }
	if(!fork())
	{
		dup2(fd[1],1);
		close(fd[0]);
		execlp("ls","ls","-l",NULL);
	}
	else
	{
		dup2(fd[0],0);
		close(fd[1]);
		execlp("sort","sort",NULL);
	}
	return 0;
}