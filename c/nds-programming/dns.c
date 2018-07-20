#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  struct addrinfo *res;
  char *hostname;
  char *hostaddr;
  struct sockaddr_in *saddr;

  if (argc != 2) {
    perror("Please insert hostname as argument\n");
    exit(1);
  }

  hostname = argv[1];

  if (0 != getaddrinfo(hostname, NULL, NULL, &res)) { /* get address info */
    fprintf(stderr, "Error in resolving hostname %s\n", hostname);
    exit(1);
  }

  saddr = (struct sockaddr_in*)res->ai_addr;
  hostaddr = inet_ntoa(saddr->sin_addr); /* change to address */

  printf("The IP address for %s is %s\n", hostname, hostaddr);
  exit(0);
}
