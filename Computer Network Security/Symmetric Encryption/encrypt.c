/*
Okello Job Opiyo
P15/37353/2016
CSC 411
Symmetric encryption
*/
//C client code 
// Cient side code 
#include <netinet/in.h> 
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h> 

char buf[1024];

char *mygets(char *buf, size_t size) 
{
    if (buf != NULL && size > 0) 
    {
        if (fgets(buf, size, stdin)) 
        {
            buf[strcspn(buf, "\n")] = '\0';
            return buf;
        }
        *buf = '\0';  /* clear buffer at end of file */
    }
    return NULL;
}


// Driver code 
int main() 
{ 
	int clientSocket, portNum, nBytes; 
	char file_buffer[3000], path[1024], buffer[3000];
	char file_name[25];
	char str[1024]; 

	// This key array stores the hidden key 
	char const key[3000] = "HIDDENKEY"; 
	struct sockaddr_in serverAddr; 
	socklen_t addr_size; 
	int i; 
	clientSocket = socket(PF_INET, SOCK_DGRAM, 0); 

	serverAddr.sin_family = AF_INET; 
	serverAddr.sin_port = htons(5004); 
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

	addr_size = sizeof serverAddr; 

	while (1) 
	{ 
		printf("Enter file name for the message you wish to encrypt: \n"); 
		mygets(path, sizeof path); 

		// printf("%s\n", path); 
		FILE* fp; 
		fp = fopen(path, "r");

		if (fp) 
		{

			printf("The plain text is:  \n");
		    while (fscanf(fp, "%s", str)!=EOF)
		        printf(" %s",str);
		}

		printf("\n");

		if (fp == NULL) { 
			printf("file \n"); 
		} 

		fseek(fp, 0, SEEK_END); 
		size_t file_size = ftell(fp); 
		fseek(fp, 0, SEEK_SET); 

		if (fread(file_buffer, file_size, 1, fp) <= 0) 
		{ 
			printf("unable to copy file into buffer\n"); 
			exit(1); 
		} 

		if (sendto(clientSocket, file_buffer, 3000, 0, (struct sockaddr*)&serverAddr,addr_size) < 0) 
		{ 
			printf("error in sending the file\n"); 
			exit(1); 
		} 

		bzero(file_buffer, sizeof(file_buffer)); 

		nBytes = recvfrom(clientSocket, buffer, 1024, 0, NULL, NULL); 

		printf("\n\nMessage sent back from server: \n"); 

		// printing some of the character to have a feel of encryption 
		for (i = 0; i < 100; ++i) 
			printf("%02X ", buffer[i]); 
		printf("\n"); 

		char x[3000]; 
		for (i = 0; i < nBytes - 1; ++i) 
			x[i] = (char)(buffer[i] ^ key[i]); 

		// printing some of the character to have a feel of decryption 
		printf("Message after decryption: \n"); 
		for (i = 0; i < 100; ++i) 
			printf("%c ", x[i]); 

		printf("\n"); 
	} 

	return 0; 
} 
