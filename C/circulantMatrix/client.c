//Name	 : Okello Job Opiyo
//Reg no.: P15/37353/2016

//client code
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

void main()
{ 
   struct sockaddr_in server;
   int sock;
   int matSize;
   int myVector[1000];
   int circulantMatrix[1000];
   int i,j,k=1,l=1;
   int retMatSize;
   

   /*printf("Please enter a string you wish to have reversed\n=> :");//prompts entry of string to be reversed
   scanf("%s",buffer);*/

  

   server.sin_family = AF_INET;
   server.sin_port = 2000;
   server.sin_addr.s_addr = inet_addr("127.0.0.1");// server ip address
   sock = socket(AF_INET,SOCK_STREAM, 0);

   connect(sock, (struct sockaddr*) &server, sizeof(server));
   //send(sock, buffer, sizeof(buffer), 0);//sends string to the server

   printf("enter matrix size\n");
   scanf("%d", &matSize);
   printf("vector from clients is: [");

   for(i=0; i<matSize; i++)
   {

      myVector[i] = k;
      printf("%d ", myVector[i]);
      k++;
   }
   printf("]\n");
   send(sock, &matSize, sizeof(int) , 0);
   send(sock, &myVector, matSize*sizeof(int) , 0);//sends string to the server
   recv(sock, circulantMatrix, (matSize*matSize)*sizeof(int), 0);// receives reversed string from the server

   retMatSize = matSize*matSize;

   printf("the circulantMatrix is:\n");

   for(i=0; i<retMatSize; i++)
   {
      printf("%d\t", circulantMatrix[i]);
      if((l%matSize)==0)
      {
         printf("\n");
      }
      l++;
   }


   //printf("Your string was reverse as follows\n=>: %d",circulantMatrix[0]); //prints out the reversed string from the server
   //printf("\n");
}
