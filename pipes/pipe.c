// C program to demonstrate use of fork() and pipe()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	// We use two pipes
	// First pipe to send input string from parent
	// Second pipe to send concatenated string from child
 	int procNUm = 10;
 	int i;
	int fd1[50][2]; // Used to store two ends of first pipe
	int fd2[50][2]; // Used to store two ends of second pipe

	char fixed_str[] = " Opiyo Okello";
	char input_str[100];
	pid_t p;


	for (i=0; i<procNUm; i++)
	{
		if (pipe(fd1[i])==-1)
		{
			fprintf(stderr, "Pipe Failed" );
			return 1;
		}
	}//creating file descriptors for first pipe

	for (i=0; i<procNUm; i++)
	{
		if (pipe(fd2[i])==-1)
		{
			fprintf(stderr, "Pipe Failed" );
			return 1;
		}
	}//creating file descriptor for second pipe


	printf("enter string to merge\n");//prompt to enter string to be concatinated
	scanf("%s", input_str);


 	for (i = 0 ; i < procNUm; i++)
 	{
 		p = fork();//creating new child processes

		// child process
		if (p == 0)
		{
			close(fd1[i][1]); // Close writing end of first pipe

			// Read a string using first pipe
			char concat_str[100];
			read(fd1[i][0], concat_str, 100);
			printf("string received by childprocessID=%d\n", getpid());//print ID for the child proces

			// Concatenate a fixed string with it
			int k = strlen(concat_str);
			int j;
			for (j=0; j<strlen(fixed_str); j++)
				concat_str[k++] = fixed_str[j];

			concat_str[k] = '\0'; // string ends with '\0'

			// Close both reading ends
			close(fd1[i][0]);
			close(fd2[i][0]);

			// Write concatenated string and close writing end
			write(fd2[i][1], concat_str, strlen(concat_str)+1);
			close(fd2[i][1]);

			exit(0);
		}

 	}

 	for(i=0; i<procNUm; i++){
 		char concat_str[100];

		close(fd1[i][0]); // Close reading end of first pipe

		// Write input string and close writing end of first
		// pipe.
		write(fd1[i][1], input_str, strlen(input_str)+1);
		close(fd1[i][1]);

		// Wait for child to send a string
		wait(NULL);

		close(fd2[i][1]); // Close writing end of second pipe

		// Read string from child, print it and close
		// reading end.
		read(fd2[i][0], concat_str, 100);
		printf("Concatenated string is  %s parent process is %d\n", concat_str, getpid());//print ID for parent process
		close(fd2[i][0]);
 	}
	

	// if (p < 0)
	// {
	// 	fprintf(stderr, "fork Failed" );
	// 	return 1;
	// }

	// // Parent process
	// else if (p > 0)
	// {
	// 	char concat_str[100];

	// 	close(fd1[0]); // Close reading end of first pipe

	// 	// Write input string and close writing end of first
	// 	// pipe.
	// 	write(fd1[1], input_str, strlen(input_str)+1);
	// 	close(fd1[1]);

	// 	// Wait for child to send a string
	// 	wait(NULL);

	// 	close(fd2[1]); // Close writing end of second pipe

	// 	// Read string from child, print it and close
	// 	// reading end.
	// 	read(fd2[0], concat_str, 100);
	// 	printf("Concatenated string is  %s parent process is %d\n", concat_str, getpid());
	// 	close(fd2[0]);
	// }

	
}
