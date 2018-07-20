#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
} message;

void progFork(int progForkNum)
{
	pid_t pid;


	key_t key = ftok("mQfile", 9972);
	int msgid = msgget(key, IPC_CREAT|0666);
	char queuedMessage[2048];

	int rc;
	struct msqid_ds buf;
	int queuedMessageTotal;

	pid = fork();

	if (progForkNum > 0)
	{
		if (pid < 0)
		{
			perror("fork failed");
		}
		else if (pid == 0)
		{
			printf("Child process %d with PID: %d created Successfully!!!\n",progForkNum, getpid());

			rc = msgctl(msgid, IPC_STAT, &buf);
			queuedMessageTotal = buf.msg_qnum;

			if (queuedMessageTotal > 0)
			{
				msgrcv(msgid, &message, sizeof(message), 1, 0);
				printf("Process %d received the following message via the Queue:  %s\n",getpid(), message.mesg_text);
			}
			else
			{
				printf("The queue is empty\n");
			}

			message.mesg_type = 1;

			printf("Enter message for process %d into the Queue: ", getpid());

			fgets(queuedMessage,1024,stdin);
			if ((strlen(queuedMessage) > 0) && (queuedMessage[strlen(queuedMessage) - 1] == '\n'))
			{
				queuedMessage[strlen(queuedMessage) - 1] = '\0';
			}

			strcat(message.mesg_text, queuedMessage);

			msgsnd(msgid, &message, sizeof(message), 0);

			printf("Process %d added the following message into the queue: %s\n",getpid(), message.mesg_text);

			if (progForkNum != 1)
			{
				printf("\n");
			}

			exit(0);
		}
		else if (pid > 0)
		{
			wait(NULL);

			progFork(progForkNum - 1);
		}
	}

	msgctl(msgid, IPC_RMID,NULL);	
}

int main(int argc, char const *argv[])
{
	progFork(5);

	return 0;
}