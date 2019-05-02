/*
Okello Job Opiyo
P15/37353/2016
CSC 411
Symmetric encryption
*/
//C server code 
#include <memory.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h> 


// Driver code 
int main() 
{ 
	int udpSocket, nBytes; 
	char buffer[3000], xor[3000]; 
	char const key[1024] = "HIDDENKEY"; 
	struct sockaddr_in serverAddr, clientAddr; 
	struct sockaddr_storage serverStorage; 
	socklen_t addr_size, client_addr_size; 
	int i; 

	udpSocket = socket(PF_INET, SOCK_DGRAM, 0); 

	serverAddr.sin_family = AF_INET; 
	serverAddr.sin_port = htons(5004); 
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

	bind(udpSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); 

	addr_size = sizeof serverStorage; 
	puts("Receiving message for decryption... :"); 
	int count = 0; 

	while (1) 
	{ 
		nBytes = recvfrom(udpSocket, buffer, 3000, 0, (struct sockaddr*)&serverStorage, 
																			&addr_size);  

		for (i = 0; i < nBytes - 1; i++) 
		{ 
			if (buffer[i] != '\n') 
				xor[i] = (char)(buffer[i] ^ key[i]); 
			else
				xor[i] = buffer[i]; 
		} 

		printf("Encrypted message received:\n"); 

		// printing some of the character to have a feel of encryption 
		for (i = 0; i < 100; ++i) 
			printf("%02X ", xor[i]); 
		printf("\n"); 

		FILE* fp; 
		fp = fopen("temp.txt", "w+"); 

		for (i = 0; i < nBytes - 1; i++) 
		{ 
			if (xor[i] != '\n') 
				fprintf(fp, "%X", xor[i]); 
			else
				fprintf(fp, "%c", xor[i]); 
		}

		printf("\n\n\n");

		char decrypted[3000]; 
		for (i = 0; i < nBytes - 1; ++i) 
			decrypted[i] = (char)(buffer[i] ^ key[i]); 

		// printing some of the character to have a feel of decryption 
		printf("Decrypted message to be sent back:\n"); 
		for (i = 0; i < 100; ++i) 
			printf("%c ", decrypted[i]); 

		printf("\n");  

		fclose(fp); 
		sendto(udpSocket, xor, nBytes, 0, (struct sockaddr*)&serverStorage, 
																addr_size); 
	} 

	return 0; 
} 
