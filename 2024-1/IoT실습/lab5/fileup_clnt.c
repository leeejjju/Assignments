#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error_handling(char *message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char *argv[]){
	int sock;
	char message[BUF_SIZE];
	int str_len, recv_len, recv_cnt;
	struct sockaddr_in serv_adr;

	if (argc != 4) {
		printf("Usage : %s <Server IP> <Server port> <File name>\n", argv[0]);
		exit(1);
	}

	FILE* fp;
	char* filename = argv[3];
	if((fp =fopen(filename, "rb")) == NULL) error_handling("fopen() error!");

	sock = socket(PF_INET, SOCK_STREAM, 0);   
	if (sock == -1) error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));
	
	if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) error_handling("connect() error!");
	else puts("Connected...........");

	//send file name's len and filename
	int filename_len = strlen(filename);
	str_len = write(sock, &filename_len, sizeof(int));
	str_len = write(sock, filename, strlen(filename));
	printf("send filename: %s\n", filename);

	//send file contents
	int read_bytes = 0; //total bytes of file
	while(1){
		str_len = fread(message, 1, BUF_SIZE, fp);
		read_bytes += str_len;
		if(str_len <= 0) break;
		str_len = write(sock, message, strlen(message));
		if(str_len <= 0) break;
		printf("read: %s\n", message);
	} 
	printf("send %dbytes successfully\n", read_bytes);

	close(sock);
	fclose(fp);
	return 0;
}


