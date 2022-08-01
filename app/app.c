#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8080
#define RESPONSE_LENGTH 2028

int main() {
  struct   sockaddr_in server;
  int      client_fd;
  int	     server_fd = socket(AF_INET, SOCK_STREAM, 0);
  char     response[RESPONSE_LENGTH] = {0};
  char     *name = getenv("GREETING_NAME");
  char     *header = "HTTP/1.1 200 OK\r\nContent-Length: ";
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(server_fd, (struct sockaddr*) &server, sizeof(server));
  listen(server_fd, 128);
  while (1) {
    client_fd = accept(server_fd, NULL, NULL);
    sprintf(response, "%s%lu\r\n\r\nHello, %s\n", header, strlen(name) + 7, name);
    for (
	    int sent = 0;
	    sent < sizeof(response);
	    sent += send(client_fd, response+sent, sizeof(response)-sent, 0)
    );
    close(client_fd);
  }
  return 0;
}
