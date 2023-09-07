#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>

#define PORT 8080
#define CONNECTIONS 5

#define MY_SOC "my_socket.sock"

int main(int argc, char *argv [])
{
	const char msg[] = "Ya me arte\n";
	struct sockaddr_un server;
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	server.sun_family = AF_UNIX;
	strcpy(server.sun_path, MY_SOC);

	int ret = bind(socket_fd, (struct sockaddr *)&server, sizeof(server));

	ret = listen(socket_fd, 10);

	for(int i = 0; i < CONNECTIONS; i++)
	{
		int sock = accept(socket_fd,(struct sockaddr *) NULL, NULL);
		int nbytes = send(sock, msg, strlen(msg), 0);
		close(socket_fd);
	}
}
