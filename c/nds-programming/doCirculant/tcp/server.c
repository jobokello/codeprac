/* doCircularnt - server */
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
  int server_sock, client_sock, c, read_size;
  struct sockaddr_in server, client;
  int msg[4];
  int rsp[4][4];
  
  /* create socket */
  server_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (server_sock == -1) {
    printf("Could not create socket. Error");
  }

  /* prepare the sockaddr_in structure */
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8880);

  /* bind the socket */
  if (bind(server_sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
    perror("Bind failed. Error");
    return 1;
  }

  /* Listen for connection */
  listen(server_sock, 3);

  c = sizeof(struct sockaddr_in);

  /* accept connection from an incoming client */
  client_sock = accept(server_sock, (struct sockaddr*)&client, (socklen_t*)&c);
  if (client_sock < 0) {
    perror("Accept failed. Error");
    return 1;
  }

  /* receive a message from client */
  while ((read_size = recv(client_sock, &msg, sizeof(msg), 0)) > 0) {
    puts("Circulant matrix generated :\n");

    /* DO CIRCULANT */
    for( int p = 0; p < 4; p++ ) {
      rsp[0][p] = msg[p]; /* copy array x to first row of array y */
    }

    for (int k = 0; k < 4 - 1; k++) {
      int start = msg[0]; /* take the first value of the 1D array aside */
      
      for (int l = 0; l < 4 - 1; l++) { /* add and shift values in array */
        rsp[k + 1][l] = msg[l + 1]; /* copy the remaining part of the 1D array into a single row in the 2D array */
        msg[l] = msg[l + 1]; /* shift values of the 1D array */
      }

      rsp[k + 1][4 - 1] = start; /* add the start to the end of array y[i][end] */
      msg[4 - 1] = start; /* add start to the end of array x */
    }
    /* ! End OF DO CIRCULANT */

    /* print circulant matrix generated */
    for(int m = 0; m < 4; m++) {
      for(int n = 0; n < 4; n++) {
        printf("%d ", rsp[m][n]);
      }
      printf("\n");
    }

    printf("\n");

    /* send circulant matrix back to client */
    if (send(client_sock, &rsp, sizeof(rsp), 0) < 0) {
      perror("Send failed. Error");
    return 1;
    }
  }

  /* print on connection termination */
  if (read_size == 0) {
      puts("Client disconnected. Success");
  }
  else if (read_size == -1) {
      perror("Receive failed. Error");
  }

  return 0;
}