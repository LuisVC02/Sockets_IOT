#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define CONNECTIONS 5

int main(int argc, char *argv [])
{
	char buff[100];
	struct sockaddr_in server;
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_port   = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = connect(socket_fd, (struct sockaddr *)&server, sizeof(server));

	int bytes = recv(socket_fd, buff, 100, 0);

	printf("%s", buff);
	close(socket_fd);
	
}
