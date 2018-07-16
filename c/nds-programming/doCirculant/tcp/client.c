/* doCircularnt - client */
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sock;
  struct sockaddr_in server;
  int msg[4];
  int rsp[4][4];

  printf("Enter 4 integers: ");
  scanf("%d%d%d%d", &msg[0], &msg[1], &msg[2], &msg[3]);
  printf("\n");

  /* create socket */
  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Could not create socket. Error");
  }

  /* prepare the sockaddr_in structure */
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(8880);

  /* connect to remote server */
  if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
    perror("Connect failed. Error");
    return 1;
  }

  /* send data to server */
  if (send(sock, &msg, sizeof(msg), 0) < 0) {
    puts("Send failed. Error");
    return 1;
  }

  /* receive a reply from the server */
  if (recv(sock, &rsp, sizeof(rsp), 0) < 0) {
    puts("Receive failed. Error");
    return 0;
  }

  puts("Server reply :\n");
  
  /* print circulant matrix received */
  for( int m = 0; m < 4; m++ ) {
    for( int n = 0; n < 4; n++ ) {
      printf( "%d ", rsp[m][n] );
    }
    printf( "\n" );
  }

  /* close the socket */
  close(sock);

  return 0;
}