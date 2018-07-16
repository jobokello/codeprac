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
#include <signal.h>

/* signal handler */
void child_finish_handler(int signum) {
  //exit(0); /* exit */
}

/* read characters from the pipe and echo them to stdout */
void read_from_pipe(int file) {
  FILE *stream;
  int c;
  stream = fdopen(file, "r");
  while ((c = fgetc(stream)) != EOF)
    putchar(c);
  fclose(stream);
}

/* write some random text to the pipe */
void write_to_pipe (int file, int sendid) {
  FILE *stream;
  stream = fdopen(file, "w");
  fprintf(stream, "Hello from pid: %d\n", sendid);
  fclose(stream);
}

/* fork the parent process into 'num' child processes */
void myfork(int num) {
  pid_t pid;
  int myfirstpipe[2];
  int mysecondpipe[2];

  /* create the first pipe */
  if (pipe(myfirstpipe)) {
    fprintf(stderr, "Pipe failed.\n");
    exit(EXIT_FAILURE);
  }

  /* create the first pipe */
  if (pipe(mysecondpipe)) {
    fprintf(stderr, "Pipe failed.\n");
    exit(EXIT_FAILURE);
  }

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

      /* read from first pipe - parent to child */
      close(myfirstpipe[1]);
      read_from_pipe(myfirstpipe[0]);
      close(myfirstpipe[0]);

      /* write to second pipe - child to parent */
      close(mysecondpipe[0]);
      write_to_pipe(mysecondpipe[1], getpid());
      close(mysecondpipe[1]);

      kill(getppid(), SIGUSR1); /* send signal to parent process on writing */

      exit(0);
    }
    else if(pid > 0) {
      /* parent process */

      /* write to first pipe - parent to child */
      close(myfirstpipe[0]);
      write_to_pipe(myfirstpipe[1], getpid());
      close(myfirstpipe[1]);

      signal(SIGUSR1, child_finish_handler); /* listen for signal from child process */
      sleep(2); /* if no signal, sleep for 2 seconds then continue */

      /* read from second pipe - child to parent */
      close(mysecondpipe[1]);
      read_from_pipe(mysecondpipe[0]);
      close(mysecondpipe[0]);

      /*recursively call fork */
      myfork(num - 1);
    }
  }
}

int main() {
  printf("This is the parent process, pid: %d\n\n", getpid());

  myfork(10); /* fork 10 processes using recursion */

  return EXIT_SUCCESS;
}
