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

/* fork the parent process into 'num' child processes */
void myfork(int num) {
  pid_t pid;

  /* setup variables for IPC using shared memory */
  key_t key = ftok("sharedmemoryfile", 65); /* generate new key */
  int shmid = shmget(key, 1024, 0666|IPC_CREAT); /* shmget returns an identifier in shmid */
  char *msg = (char*) shmat(shmid, (void*)0, 0); /* shmat to attach to shared memory */
  char new_msg[1000]; /* write string variables */

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

      if(msg[0] != '\0') { /* if msg is not empty */
        printf("Data read by process %d: %s\n", getpid(), msg); /* print the current value of msg */
      }
      else {
        printf("This is the first read. There is no written message in shared memory.\n");
      }

      printf("Your message: "); /* ask user to input their text */

      fgets(new_msg, 256, stdin); /* read user input */
      if ((strlen(new_msg) > 0) && (new_msg[strlen (new_msg) - 1] == '\n')) /* remove trailing newline, if exists */
        new_msg[strlen (new_msg) - 1] = '\0';

      strcat(msg, new_msg); /* concatenate the user text to the current value in msg */

      printf("Data written by process %d: %s\n", getpid(), msg); /* print the new appended msg */

      if(num != 1) {
        printf("\n");
      }

      shmdt(msg); /* detach from shared memory */

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

  shmctl(shmid, IPC_RMID , 0); /* clear data in shared memory */
}

int main() {
  myfork(5); /* fork 5 processes using recursion */

  return EXIT_SUCCESS;
}
