#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd1,fd2;
	fd1 = open("demo.txt",O_RDONLY);
	printf("%d\n",fd1);
	close(fd1);
	fd2 = open("xyz.txt",O_RDONLY|O_CREAT);
	printf("%d\n",fd2);
	fd1 = write(1,"Hello World\n",strlen("Hello World\n"));
	printf("%d\n",getpid());
	printf("%d\n",getppid());
	return 0;
}