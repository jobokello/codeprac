//Name   : Okello Job Opiyo
//Reg no.: P15/37353/2016

//Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
#define PORT     8080
 
// Driver code
int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    int i, j, k, x=0;
    int matSize;
    int myVector[1000];
    int matrix[1000][1000];
    int circulantMatrix[1000];
    int tempHolder;
    

    printf("***************************\nUDP server listening....\n***************************\n");
     
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
     
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
     
    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
     
    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
            sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    int len, n;

    //while(1)
    //{
        n = recvfrom(sockfd, &matSize, sizeof(int),MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);

        printf("size is: %d\n", matSize);

        n = recvfrom(sockfd, &myVector, matSize*sizeof(int),MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);

        printf("the received vector is: [");

        for(i=0; i<matSize; i++)
        {
          printf("%d  ", myVector[i]);
        }

        printf("]\n");

        printf("size = %d\nThe generated matrix is:\n", matSize);

        for(i=0; i<matSize; i++)
        {
            for(j=0; j<matSize; j++)
            {
                matrix[i][j] = myVector[j];
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }

        printf("\n\n");

        for(i=matSize-1; i>-1; i--)
        {
            for(k=i; k>0; k--)
            {
                tempHolder = matrix[i][matSize-1];

                for(j=matSize-1; j>0; j--)
                {
                    matrix[i][j] = matrix[i][j-1];
                    printf("[%d][%d]=[%d][%d]\t", i,j,i,j-1);
                }

                matrix[i][0] = tempHolder;
                printf("\n");
            }
          printf("\n\n");
        }

        printf("\nthe new matrix is:\n\n\n");

        for(i=0; i<matSize; i++)
        {
            for(j=0; j<matSize; j++)
            {
                printf("%d\t",matrix[i][j]);
                circulantMatrix[x] = matrix[i][j];
                x++;
            }

                printf("\n");
        }

        
        sendto(sockfd, &circulantMatrix, (matSize*matSize)*sizeof(int),MSG_CONFIRM, (const struct sockaddr *) &cliaddr,len);
        printf("\n\nCirculant matrix sent back to client!!!\n"); 
    //}   
     
    return 0;
}