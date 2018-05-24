//Name   : Okello Job Opiyo
//Reg no.: P15/37353/2016

// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
#define PORT     8080
#define MAXLINE 1024
 
// Driver code
int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in servaddr;
    int matSize;
    int myVector[1000];
    int circulantMatrix[1000];
    int i, k=1, l=1;
    int retMatSize;

    printf("***************************\nUDP Client Started....\n***************************\n");
 
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    memset(&servaddr, 0, sizeof(servaddr));
     
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
     
    int n, len;

    printf("enter the size of the vector: ");
    scanf("%d",&matSize);
    sendto(sockfd, &matSize, sizeof(int),MSG_CONFIRM,(const struct sockaddr *) &servaddr, sizeof(servaddr));

    printf("vector from clients is: [");

    for(i=0; i<matSize; i++)
    {

      myVector[i] = k;
      printf("%d ", myVector[i]);
      k++;
    }

    printf("]\n\n\n");

    sendto(sockfd, &myVector, matSize*sizeof(int),MSG_CONFIRM,(const struct sockaddr *) &servaddr, sizeof(servaddr));

    printf("Vector sent to server...\n\n\n");

    n = recvfrom(sockfd, &circulantMatrix, (matSize*matSize)*sizeof(int),MSG_WAITALL, (struct sockaddr *) &servaddr,&len);

    retMatSize = matSize*matSize;

    printf("the circulantMatrix is:\n\n");

    for(i=0; i<retMatSize; i++)
    {
        printf("%d\t", circulantMatrix[i]);
        if((l%matSize)==0)
        {
         printf("\n");
        }
        l++;
    }
 
    close(sockfd);
    return 0;
}