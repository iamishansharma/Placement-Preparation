#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1,fd2;
	fd1 = open("demo1.txt",O_RDONLY);
	fd2 = open("demo2.txt",O_WRONLY);

	int pos = lseek(fd1,0,SEEK_END);
	printf("%d\n", pos);
	char c;
	while(pos > 0)
	{
		lseek(fd1,--pos,SEEK_SET);
		read(fd1,&c,1);
		//printf("%c\n", c);
		write(fd2,&c,1);
		// lseek(fd1,--pos,SEEK_SET);
	}
	close(fd1);
	close(fd2);

	return 0;
}