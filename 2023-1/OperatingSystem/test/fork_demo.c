#include <stdio.h>

#include <unistd.h>
#include <wait.h>

int main()
{
	int parent = getpid();
	printf("parent = %d\n", parent);


	int child = fork();
	if(child > 0){
		printf("This is the parent, pid = %d\n", getpid());
		wait(NULL);
	} else if(child == 0) {
		printf("This is the child, pid = %d\n", getpid());
		execlp("/usr/bin/ls", "ls", "-al", NULL);
	} else {
		printf("Error! Failed to create a child process, line = %d\n", __LINE__);
	}
//	printf("Hello, World\n");

	return 0;
}
