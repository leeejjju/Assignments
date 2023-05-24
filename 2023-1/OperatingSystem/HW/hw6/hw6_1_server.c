#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>

//My previous solution was perfect, so I didn't modify it!
void Digit2Text(char *digit_string, char *alphabet_str);

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("Usage: %s <server-port>\n", argv[0]);
		return 0;
	}

	int ret = 0;
	int port = atoi(argv[1]);
	printf("port = %d\n", port);

	printf("creating socket...\n");
	
	int server_sockfd;
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("error: cannot create server socket.\n");
		exit(-1);
	}

	printf("Done.\n");

	struct sockaddr_in svr_addr = { 0 };
	
	bzero(&svr_addr, sizeof(svr_addr));
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	svr_addr.sin_port = htons(port);


	printf("socket binding...\n");
	
	if((ret = bind(server_sockfd, (struct sockaddr *)&svr_addr, sizeof(svr_addr))) < 0){
		printf("error: cannot bind the socket to address.\n");
		exit(-1);
	}



	printf("Done.\n");


	printf("listening socket...\n");

	if((ret = listen(server_sockfd, 5)) < 0){ //TODO idk if the num 5 is right... 
		printf("error: cannot listen the sever socket\n");
		exit(-1);
	}


	printf("Done.\n");

	struct sockaddr_in client_addr = { 0 };
	memset(&client_addr, 0, sizeof(client_addr));
	socklen_t client_addr_len = 0;

	printf("Waiting for connect request...\n");

	int client_sockfd;
	if((client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_addr, &client_addr_len)) < 0){
		printf("error: acnnot accept a connection request.\n");
		exit(-1);
	}

	printf("Connected.\n");

	char input[64] = "";
	char output[512] = "";


	while(1){
		read(client_sockfd, input, 64);
		if(!strcmp(input, "quit") || (strlen(input) <= 0)){
			write(client_sockfd, "", 1);
			break;
		}
		printf("input = [%s]\n", input);// received "1234" from the client
		strcpy(output, "");	
		Digit2Text(input, output);
		printf("output = [%s]\n", output);
		printf("Sending message...\n");				// sending "one two three four" to the client
		write(client_sockfd, output, strlen(output)+1);
		printf("Done.\n");
	}

	printf("Closing sockets\n");

	close(client_sockfd);
	close(server_sockfd);

	printf("Done.\n");
	printf("Bye!\n");

	return 0;
}

void Digit2Text(char *digit_str, char *alphabet_str){
	static char digit_name[][16] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};


	if(strlen(digit_str) <= 0){
		strcpy(alphabet_str, "");
		return;
	}
	
	for(int i = 0; i < strlen(digit_str); i++){
		if(isdigit(digit_str[i])){
			strcat(alphabet_str, digit_name[digit_str[i] - '0']);
			if(i != strlen(digit_str)-1) strcat(alphabet_str, " ");
		}else{
			strcpy(alphabet_str, "");
			return;
		}
	}

}

