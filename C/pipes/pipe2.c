#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
	pid_t childPIDorZero = fork();

	if (childPIDorZero < 0)
	{
		perror("fork() error");
		exit(-1);
	}

	if (childPIDorZero != 0)
	{
		printf("im the parent %d, my child is %d\n", childPIDorZero, getpid());
	}
	else
	{
		printf("im the child %d, my parent is %d\n",getpid(), getpid());
		execl("/bin/echo", "echo", "hello world", NULL);
	}
}