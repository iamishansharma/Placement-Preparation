#include <stdio.h>

int main()
{
	// execl("sum","sum1","10","20","30",(char *)NULL);
	// printf("execl call unsuccessful\n");

	printf("Hello World\n");
	execl("/bin/echo","echo","Print","from","execl",(char *)NULL);
}