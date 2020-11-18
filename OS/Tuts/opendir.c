#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
	struct dirent *dir;
	DIR *dr;
	dr = opendir(".");
	if(dr == NULL)
		printf("Could not open current directory\n");

	// while((dir = readdir(dr)) != NULL)
	// {
	// 	printf("%s\n",dir->d_name);
	// }
	dir = readdir(dr);
	while(dir != NULL)
	{
		printf("%s\n", dir->d_name);
		dir = readdir(dr);
	}
	closedir(dr);

	return 0;
}