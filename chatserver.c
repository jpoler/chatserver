#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int serversock, s;
	//getaddrinfo with hints
	struct getaddrinfo hints, *res, *p;
	memset((void *)&hints, 0, sizeof(hints));
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_STREAM;
	if (getaddrinfo(NULL, argv[1], &hints, &res) != 0) {
		perror("getaddrinfo");
		exit(1);
	} 


	//for loop with socket and bind calls

	//listen if successful

	//main loop
		// select on set of fds
		// if serversock, then accept and add to set
		// else read from sock and send message to everyone else
}
