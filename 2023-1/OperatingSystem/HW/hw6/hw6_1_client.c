#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 256

//My previous solution was perfect, so I didn't modify it!
int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("Usage: %s <server-ip> <server-port> <client-port>\n", argv[0]);
		return -1;
	}

	char *server_ip = argv[1];
	int server_port = atoi(argv[2]);

	// TO DO: create a socket
	//  on failure, display an error message and terminate
	int sockfd;
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("error: cannot create socket.\n");
		exit(-1);
	}


	printf("Connecting to %s:%d\n", server_ip, server_port);

	struct sockaddr_in svr_addr = { 0 };
	// TO DO: set svr_addr with appropriate values
	memset(&svr_addr, 0, sizeof(svr_addr));
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_addr.s_addr = inet_addr(server_ip);
	svr_addr.sin_port = htons(server_port);


	// TO DO: connect to svr_addr using the socket
	//  on failure, display an error message and terminate
	if(connect(sockfd, (struct sockaddr*)&svr_addr, sizeof(svr_addr)) == 1){
		printf("error: cannot connect to sever.\n");
		exit(-1);
	}

	printf("Done.\n");

	/* TO DO: repeat
		read a string from the user
		write the input string to the socket using write()
		read the conversion result from the socket using read()
		display the input string and the conversion result
		if the conversion result is an empty string, break
	*/
	char input[BUFFER_SIZE] = "";
	char output[BUFFER_SIZE] = "";
	while(1){
		printf("Input a number:");
		fgets(input, BUFFER_SIZE, stdin);
		input[strlen(input)-1] = 0;
		write(sockfd, input, strlen(input)+1);
		
		read(sockfd, output, BUFFER_SIZE);
		
		printf("%s ==> %s\n", input, output);

		if(strlen(output) == 0) break;

	}

	printf("Closing socket\n");

	// TO DO: close the socket
	close(sockfd);

	printf("Done.\n");
	printf("Bye!\n");

	return 0;
}
