#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHMSIZE 2048

void progFork(int childProcNum)
{
	pid_t pid;//process ID

	key_t key = ftok("shmFile", 9876);//generate unique key for shared memory

	int shmid = shmget(key, SHMSIZE, IPC_CREAT|0666);//get identifier for the shared memory segment(memory ID)

	char *msg = (char*) shmat(shmid, (void*)0, 0);

	char sharedMessage[2048];//message

	pid = fork();//create child process

	if (childProcNum > 0)
	{
		if(pid < 0)
		{
			perror("fork error!!!");
		}
		else if (pid == 0)
		{
			printf("child process %d with PID: %d has been created successfully\n",childProcNum,getpid());

			if(msg[0] != '\0')
			{
				printf("Process %d found the following message in memory: %s\n",getpid(),msg );
			}
			else
			{
				printf("Process %d will be the first to write into the shared memory\n",getpid());
			}

			//add new content into the memory
			printf("Enter new message into the memory: ");

			fgets(sharedMessage,256,stdin);

			//append new string to the existent string shared memory content
			if ((strlen(sharedMessage) > 0) && (sharedMessage[strlen(sharedMessage) - 1] == '\n'))
			{
				sharedMessage[strlen(sharedMessage) - 1] = '\0';
			}

			strcat(msg, sharedMessage);

			printf("Process %d wrote the following message into memory: %s\n",getpid(), msg);

			if(childProcNum != 1)
			{
				printf("\n");
			}

			shmdt(msg);//detach from the shared memory after wrting into it 

			exit(0);

		}
		else if(pid > 0)
		{
			wait(NULL);

			progFork(childProcNum -1);
		}
	}

	shmctl(shmid,IPC_RMID, 0);//destroy the shared memory after all processes have communicated
}

int main(int argc, char const *argv[])
{
	progFork(5);
	return 0;
}