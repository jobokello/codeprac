//Name	 : Okello Job Opiyo
//Reg no.: P15/37353/2016

//server code
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>

char circleMartrix(int resMatrixSize)
{
   int n = resMatrixSize;
   int i;
   int j;
   int k;
   int l;
   int m;
   int tempHolder;
   int populate = 0;
   printf("this is matrixSize: %d\n", n );
   char circleMartrix[n][n];
   char newMatrix[n][n];

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         circleMartrix[i][j] = populate++;
      }
   }

   printf("the original matrix is:\n");

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         printf("%d  ", circleMartrix[i][j] );
      }

      printf("\n");
   }

   

   tempHolder = circleMartrix[n-1][n-1];
   printf("%d\n", tempHolder );

   for (k = n-1; k > -1; k--)
   {

      printf("%d\n", k);
      for(k = n-1; k > -1; k--)
      {
         for(l = n-1; l > 0; l--)
         {
            newMatrix[k][l] = circleMartrix[k][l-1];
         }
   
         //l--;
         printf("[%d][%d] == [%d][%d]\n", k,l,k-1,n-1);

         newMatrix[k][l] = circleMartrix[k-1][n-1];


        /* for (m = 0; m < n; m++)
         {
            printf("%d  ", newMatrix[k][m] );
         }
         printf("\n");*/
      }
   }

   newMatrix[0][0] = tempHolder;

   printf("after cicling the new matrix is\n");

   for (k = 0; k < n; k++)
   {
      for (l = 0; l < n; l++)
      {
         printf("%d\t", newMatrix[k][l] );
      }

      printf("\n");
   }



}

void main()
{ 
   struct sockaddr_in server, client;
   char newMatrix[1000][1000], temp; //holds the string
   int matrixSize;
   int n, sock, newsock, i, j;

   sock = socket(AF_INET, SOCK_STREAM, 0);
   server.sin_family = AF_INET;
   server.sin_port = 2000;
   server.sin_addr.s_addr = inet_addr("127.0.0.1");
   bind(sock, (struct sockaddr*) &server, sizeof(server));

   //creates the connection between the server and the client
   listen(sock, 2);
   n = sizeof(client);
   newsock = accept(sock, (struct sockaddr*) &client, &n);

   //reverses the received string
  /* for(;;)
   {
      recv(newsock, buffer, sizeof(buffer), 0);
      /recv(newsock, buffer, sizeof(buffer), 0);
      i = 0; 
      j = strlen(buffer) - 1;
      while(i<j)
      { 
         temp = buffer[i]; 
         buffer[i] = buffer[j]; 
         buffer[j] = temp; 
         i++; 
         j--;
       }
   send(newsock, buffer, sizeof(buffer), 0);//sends back the reversed string to the client
   }*/

   recv(newsock, &matrixSize, 1, 0);

   printf("matrix sizeis %d\n", matrixSize);
   circleMartrix(matrixSize);

   send(newsock, *newMatrix, sizeof(*newMatrix), 0);//sends back the reversed string to the client



}
