#include <stdio.h>
#include <unistd.h>

int main()
{
	int dir;
	dir = mkdir("mydir",0777);
	dir = rmdir("mydir");
	return 0;
}