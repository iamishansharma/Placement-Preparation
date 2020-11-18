#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	long max;
	char * buf;
	max = pathconf("/",_PC_PATH_MAX);
	buf = (char *)malloc(max);
	printf("%ld\n", max);
	if(getcwd(buf,max) == NULL)
		printf("Error:\n");
	else
		printf("Path: %s\n", buf);

	return 0;
}