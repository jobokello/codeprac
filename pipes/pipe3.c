#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	int ProcNum = 10; // number of processes
	int i; //process counter
	int fd1[50][2]; //first pipe from parent to  child process
	int fd2[50][2]; //second pipe from child ro parent process

	char parentMessage[] = " hello from parent. ";
	char childMessage[] = " hello from child. = ";

	pid_t pid;

	for (i=0; i<ProcNum; i++)
	{
		if (pipe(fd1[i])==-1)
		{
			perror("pipe creation failed");
		}
	}

	for (i=0; i<ProcNum; i++)
	{
		if (pipe(fd2[i])==-1)
		{
			perror("pipe creation failed");
		}
	}

	//child process
	for (i=0; i<ProcNum; i++)
	{
		pid = fork(); //create new child process

		if (pid == 0)
		{
			close(fd1[i][1]);

			char receivedMessage[100];
			read(fd1[i][0], receivedMessage, strlen(parentMessage)+1);
			printf("%s child process ID is : %d\n",receivedMessage, getpid());

			close(fd1[i][0]);
			close(fd2[i][0]);

			write(fd2[i][1], childMessage, strlen(childMessage)+1);
			close(fd2[i][1]);

			exit(0);
		}

	}

	//parent process
	for (i=0; i<ProcNum; i++)
	{
		if (pid > 0)
		{
			char childReply[100];

			close(fd1[i][0]);

			write(fd1[i][1], parentMessage, strlen(parentMessage)+1);
			close(fd1[i][1]);

			wait(NULL);

			close(fd2[i][1]);

			read(fd2[i][0], childReply, strlen(childMessage)+1);
			printf("%s parent process ID is : %d\n", childReply, getpid());
			close(fd2[i][0]);
		}
	}  

	return 0;
}
