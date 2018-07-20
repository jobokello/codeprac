/**
 * The following program has a process that spawns 10 child processes,
 * who all communicate with the parent process, and terminate successfully.
 *
 *  REG NO: P15/55175/2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/msg.h>

/* structure for message queue */
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

/* fork the parent process into 'num' child processes */
void myfork(int num) {
  pid_t pid;

  /* setup variables for IPC using message queues */
  key_t key = ftok("messagequeuefile", 65); /* generate new key */
  int msgid = msgget(key, 0666|IPC_CREAT); /* shmget returns an identifier in shmid */
  char new_msg[1000];

  /* to check if message queue is empty */
  int rc;
  struct msqid_ds buf;
  int num_messages;

  /* create child processes */
  pid = fork();
  if(num > 0) {
    if (pid < 0) {
      /* child process was not created */
      perror("fork");
    }
    else if (pid == 0) {
      /* child process */
      printf("This is child process %d, pid: %d\n", num, getpid());

      /**
       * START OF communication amongst the child processes
       */

      rc = msgctl(msgid, IPC_STAT, &buf);
      num_messages = buf.msg_qnum; /* check number of messages in queue */

      if(num_messages > 0) { /* if queue is not empty */
        msgrcv(msgid, &message, sizeof(message), 1, 0); /* msgrcv to receive message */
        printf("Message received by process %d is : %s \n", getpid(), message.mesg_text); /* display the message */
      }
      else {
        printf("This is the first read. There is no written message in message queue.\n");
      }

      message.mesg_type = 1;

      printf("Your message: "); /* ask user to input their text */

      fgets(new_msg, 256, stdin); /* read user input */
      if ((strlen(new_msg) > 0) && (new_msg[strlen (new_msg) - 1] == '\n')) /* remove trailing newline, if exists */
        new_msg[strlen (new_msg) - 1] = '\0';

      strcat(message.mesg_text, new_msg); /* concatenate the user text to the current value in queue */

      msgsnd(msgid, &message, sizeof(message), 0); /* msgsnd to send message to queue */

      printf("Message sent by process %d is : %s \n", getpid(), message.mesg_text); /* display the new message */

      if(num != 1) {
        printf("\n");
      }

      /**
       * END OF communication amongst child processes
       */

      exit(0);
    }
    else if(pid > 0) {
      /* parent process */
      wait(NULL);

      /*recursively call fork */
      myfork(num - 1);
    }
  }

  msgctl(msgid, IPC_RMID, NULL); /* to destroy the message queue */
}

int main() {
  myfork(5); /* fork 5 processes using recursion */

  return EXIT_SUCCESS;
}
