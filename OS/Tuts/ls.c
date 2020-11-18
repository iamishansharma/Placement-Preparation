#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	execlp("ls","ls","-l",NULL);
	return 0;
}