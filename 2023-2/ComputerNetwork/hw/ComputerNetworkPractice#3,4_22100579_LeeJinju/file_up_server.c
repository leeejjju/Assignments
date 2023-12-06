#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 32
void error_handling(char *message);

// 22100579
//week10-1

int main(int argc, char *argv[])
{
	int serv_sd, clnt_sd;
	FILE * fp;
	char file_name[BUF_SIZE];
	char buf[BUF_SIZE];
	int read_cnt;
	
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;
	
	if (argc != 2) {
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sd = socket(PF_INET, SOCK_STREAM, 0);   
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	
	bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
	listen(serv_sd, 5);
	
	clnt_adr_sz = sizeof(clnt_adr);    
	clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

	// TODO: Receive file name 
	if((read_cnt = read(clnt_sd, file_name, sizeof(file_name))) == -1){
		printf("error while reading\n");
	}

	// TODO: Open file with received file name
	if((fp = fopen(file_name, "wb")) == NULL){
		printf("error during open file\n");
	}
	
	// TODO: Receive file data from client 
	while((read_cnt = read(clnt_sd, buf, sizeof(buf))) != 0){
		fwrite((void*)buf, 1, read_cnt, fp);
	}
	
	printf("Received file data: %s \n", file_name);
	
	// TODO: Send complete message to client 
	write(clnt_sd, "Thank you", 10);
	
	fclose(fp);
	close(clnt_sd); 
	close(serv_sd);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
