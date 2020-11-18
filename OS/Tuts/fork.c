#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Hello\n");

	int id = fork();
	if(id == 0)
		fork();
	printf("Bye\n");
}