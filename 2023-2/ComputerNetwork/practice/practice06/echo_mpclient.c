#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_routine(int sock, char *buf);
void write_routine(int sock, char *buf);

//22100579

int main(int argc, char *argv[])
{
	int sock;
	pid_t pid;
	char buf[BUF_SIZE];
	struct sockaddr_in serv_adr;
	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock = socket(PF_INET, SOCK_STREAM, 0);  
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));
	
	if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("connect() error!");
	
	// TODO: fork
	pid = fork();

	// TODO: parent process calls read routine and 
	//       child process calls write routine
	if(pid == 0){
		write_routine(sock, buf);
	}

	else if(pid > 0){
		read_routine(sock, buf);
	}

	close(sock);
	return 0;
}

void read_routine(int sock, char *buf)
{
	int recv_len = 0;
	while (1)
	{
		// TODO: Read message from the echo server 
		recv_len = read(sock, buf, BUF_SIZE-1);
		//if (() == 0) break;
		buf[recv_len]=0;
		if (!strcmp(buf,"q\n") || !strcmp(buf,"Q\n")) break;
		printf("Message from server: %s\n", buf);
	}
}
void write_routine(int sock, char *buf)
{
	while (1)
	{
		// TODO: Write message to the echo server
		fputs("Input message(Q to quit): ", stdout);
		fgets(buf, BUF_SIZE, stdin);
		
		if (!strcmp(buf,"q\n") || !strcmp(buf,"Q\n")) break;
		if(write(sock, buf, strlen(buf)) == 0) break;
	}
}
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}