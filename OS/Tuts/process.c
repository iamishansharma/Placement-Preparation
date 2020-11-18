#include <stdio.h>
#include <fcntl.h>

int main() 
{ 
	int pid; 
	pid = fork(); 
	if (pid < 0) 
	{ 
		// error occurred 
		fprintf(stderr, "Fork failed!\n"); 
		exit(-1); 
	} 
	else if (pid == 0) 
	{ 
		// child process 
		printf("I am the child, return from fork=%d\n", pid); 
		execlp("/bin/ps", "ps", NULL); 
	} 
	else 
	{ 
		// parent process 
		printf("%d\n",pid );
		printf("I’m the parent, return from fork, child pid=%d\n", pid);
		printf("%d\n",pid ); 
		printf("Parent exiting!\n"); exit(0); 
	} 
}