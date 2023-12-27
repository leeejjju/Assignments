#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define MAX_CLNT 256

void *handle_clnt(void * arg);
void error_handling(char * msg);

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
  
	pthread_mutex_init(&mutx, NULL);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; 
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	
	if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");
	
	while (1)
	{
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_sz);
		
		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mutx);
	
		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
	}
	close(serv_sock);
	return 0;
}
	
void *handle_clnt(void * arg)
{
	int clnt_sock = *((int*)arg);
	int str_len, filenamesize, fd;
	char buf[BUF_SIZE];
	char path[10] = "result/";
	char filename[256];

	read(clnt_sock, &filenamesize, sizeof(int));
	read(clnt_sock, filename, filenamesize);
	
	strcat(path, filename);
	//printf("path: %s\n", path);

	if((fd = open(path, O_WRONLY | O_CREAT), 0666) < 0){
		perror("cannot open file");
		exit(EXIT_FAILURE);
	}

	printf("Received %s\n", filename);
	while ((str_len = read(clnt_sock, buf, BUF_SIZE))){
		//buf[str_len-1] = 0;
		//printf("recv:\n%s\n", buf);
		if( write(fd, buf, str_len) < 0) perror("cannot write to file");
	}



	char cmd[BUF_SIZE] = "chmod 0666 ";
	shutdown(clnt_sock, SHUT_RD);
	close(fd);
	strcat(cmd, path);
	FILE* fp = popen(cmd, "r");
	pclose(fp);
//	printf("command: %s\n", cmd);

	//execution...
	strcpy(cmd, "gcc "); 
	strcat(cmd, path);
	strcat(cmd, " -o ");
	path[strlen(path)-2] = 0;
	strcat(cmd, path);
//	printf("command: %s\n", cmd);
	fp = popen(cmd, "r");
	pclose(fp);

	strcpy(cmd, "./"); 
	strcat(cmd, path);
//	printf("command: %s\n", cmd);
	fp = popen(cmd, "r");

	while(fgets(buf, BUF_SIZE-1, fp)){
		if(strstr(buf, "warring:") != NULL){
			strcpy(buf, "Warring occured\0");
			write(clnt_sock, buf, strlen(buf));
			printf("send: %s\n", buf);	
			break;
		}
		if(strstr(buf, "error:") != NULL){
			strcpy(buf, "Error occured\0");
			write(clnt_sock, buf, strlen(buf));
			printf("send: %s\n", buf);	
			break;
		}else{
			write(clnt_sock, buf, strlen(buf));
			printf("%s", buf);
		}
	}


	pclose(fp);
	close(clnt_sock);
	return NULL;
}

void error_handling(char * msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
