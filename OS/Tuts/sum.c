#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
	int sum = 0;
	if(argc != 4)
	{
		printf("Invalid Argument\n");
		exit(0);
	}
	int i;
	for(i = 1; i < argc; i++)
	{
		printf("%s\n", argv[i]);
		sum += atoi(argv[i]);
	}
	printf("%d\n",sum);

	return 0;
}