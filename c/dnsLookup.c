#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	int sockfd;
	struct addrinfo hints, *results, *p;
	struct sockaddr_in *ip_access;
	int rv;
	char hostname[200];
	char ip[256];
	char inputVal[256];

	printf("Enter the domain name: ");
	scanf("%s",inputVal);
	strcpy(hostname,inputVal);

	memset(&hints,0,sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if((rv = getaddrinfo(hostname, "domain", &hints, &results)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n",gai_strerror(rv));
		return 1;
	}

	for(p = results; p != NULL; p = p->ai_next)
	{
		ip_access = (struct sockaddr_in *) p->ai_addr;

		printf("The IP adress is: %s \n",inet_ntoa(ip_access->sin_addr));
	} 

	freeaddrinfo(results);

	printf("\n");

	return 0;
}