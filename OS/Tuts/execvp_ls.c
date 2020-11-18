#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	int pid, status;
	int newfd;
	char *cmd[] = { "/bin/ls", "-al", "/", 0 };
	
	if ((newfd = open("test.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
		perror("test.txt"); /* open failed */
		exit(1);
	}
	printf("writing output of the command %s to \"%s\"\n", cmd[0], "text.txt");
	pid = fork();
	if(!pid)
	{
		wait();
		printf("All done\n");
	}
	else
	{
		dup2(newfd, 1);

		execvp(cmd[0], cmd);
		perror(cmd[0]); /* execvp failed */
	}
	

	exit(1);
}