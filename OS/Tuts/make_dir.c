#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
	mkdir("test",0777);
	int fd[2];
	creat("test/demo1.txt",0777);
	creat("test/demo2.txt",0777);
	struct dirent *de;
	DIR * dr = opendir("test");
	int i = 0;
	while((de = readdir(dr)) != NULL)
	{
		fd[i] = open(de -> d_name,O_RDWR);
		printf("%d\n", fd[i]);
		i++;
	}
	char buf[256];
	write(fd[0],"Tomorrow we have OS tutorial Test",sizeof("Tomorrow we have OS tutorial Test"));
	int nbread;
	while((nbread = read(fd[0],buf,sizeof(buf))) > 0)
		write(fd[1],buf,sizeof(buf));

	close(fd[0]);
	close(fd[1]);

	closedir(dr);
}