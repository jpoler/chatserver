#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int serversock, s;
	//getaddrinfo with hints
	struct addrinfo hints, *res, *p;
	memset((void *)&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(NULL, argv[1], &hints, &res) < 0) {
		printf("Exiting from here\n");
		perror("getaddrinfo");
		exit(1);
	} 

	for (p = res; p != NULL; p = p->ai_next) {
		if ((serversock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
			continue;
		if (bind(serversock, p->ai_addr, p->ai_addrlen) != 0) {
			close(serversock);
			continue;
		}
		break;
	}

	if (p == NULL) {
		printf("Could not bind a socket to a port properly\n");
		exit(2);
	}

	freeaddrinfo(res);
	//for loop with socket and bind calls

	//listen if successful

	//main loop
		// select on set of fds
		// if serversock, then accept and add to set
		// else read from sock and send message to everyone else
}
