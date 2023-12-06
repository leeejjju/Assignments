#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

//2210579

#define FILE_LEN 32
#define BUF_SIZE 1024
void error_handling(char *message);
void *handle_client(void *arg);

int main(int argc, char *argv[])
{
	int serv_sd, clnt_sd;
	pthread_t thread; 
	
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
	
	if (bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sd, 5) == -1)
		error_handling("listen() error");

	while (1) {
		clnt_adr_sz = sizeof(clnt_adr);    
		clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);	

		// TODO: pthread_create & detach 
		if(pthread_create(&thread, NULL, handle_client, &clnt_sd) && pthread_detach(thread)){
			printf("error during create or detach\n");
			exit(1);
		}
		printf("Connected client IP(sock=%d): %s \n", clnt_sd, inet_ntoa(clnt_adr.sin_addr));
	}
	
	close(serv_sd);
	return 0;
}

void *handle_client(void *arg)
{
	// TODO: file receiving 
	int clnt_sd = *((int *)arg);
	char filename[FILE_LEN];
	char buf[BUF_SIZE];
	int readlen, read_cnt, written;
	FILE * fp;

	readlen = read(clnt_sd, filename, FILE_LEN);
	fp = fopen(filename,"w");

	while(1){
		if ((read_cnt = read(clnt_sd, buf, BUF_SIZE)) == 0) {
			printf("Complete!: %s \n", filename);
			write(clnt_sd, "Thank you", 10);
			printf("Closed client: %d \n", clnt_sd);

			close(clnt_sd);
			fclose(fp);
			break;
		}else{
			written = 0;
			while(written < read_cnt){
				if(read_cnt - written > BUF_SIZE){
					written += fwrite(buf, 1, BUF_SIZE, fp);
				} else written += fwrite(buf, 1, read_cnt - written, fp);
			}
		}
	}
	return NULL;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
