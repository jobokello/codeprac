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
   char buffer[60];//holds the string to be reversed
   int matrixSize;
   char newMatrix[matrixSize][matrixSize];

   /*printf("Please enter a string you wish to have reversed\n=> :");//prompts entry of string to be reversed
   scanf("%s",buffer);*/

   printf("enter matrix size\n");
   scanf("%d", &matrixSize);

   server.sin_family = AF_INET;
   server.sin_port = 2000;
   server.sin_addr.s_addr = inet_addr("127.0.0.1");// server ip address
   sock = socket(AF_INET,SOCK_STREAM, 0);

   connect(sock, (struct sockaddr*) &server, sizeof(server));
   //send(sock, buffer, sizeof(buffer), 0);//sends string to the server
   send(sock, &matrixSize, 1, 0);//sends string to the server
   recv(sock, *newMatrix, sizeof(*newMatrix), 0);// receives reversed string from the server

   printf("%d\n", strlen(newMatrix));

   printf("Your string was reverse as follows\n=>: %s",buffer); //prints out the reversed string from the server
   printf("\n");
}
