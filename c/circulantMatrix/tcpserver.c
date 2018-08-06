//Name    : Okello Job Opiyo
//Reg no.: P15/37353/2016

//Server side implementation of TCP client-server model#include<stdio.h> using C language
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<stdio.h> 

void main()
{ 
   struct sockaddr_in server, client;
   int n, sock, newsock, i, j, k, x = 0;
   int matSize;
   int myVector[1000];
   int matrix[1000][1000];
   int circulantMatrix[1000];
   int tempHolder;

  printf("***************************\nTCP server listening....\n***************************\n");

   sock = socket(AF_INET, SOCK_STREAM, 0);
   server.sin_family = AF_INET;
   server.sin_port = 2000;
   server.sin_addr.s_addr = inet_addr("127.0.0.1");
   bind(sock, (struct sockaddr*) &server, sizeof(server));

   //creates the connection between the server and the client
   listen(sock, 2);
   n = sizeof(client);
   newsock = accept(sock, (struct sockaddr*) &client, &n);

   recv(newsock, &matSize, sizeof(int), 0);

   printf("size = %d\n", matSize);

   recv(newsock, &myVector, matSize*sizeof(int), 0);

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

   send(newsock, &circulantMatrix, (matSize*matSize)*sizeof(int), 0);//sends back the reversed string to the client
}