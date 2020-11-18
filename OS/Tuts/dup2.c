#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("demo.txt",O_WRONLY);

	dup2(fd,1);
	gets("Hello");
	printf("What's up\n");

	return 0;
}