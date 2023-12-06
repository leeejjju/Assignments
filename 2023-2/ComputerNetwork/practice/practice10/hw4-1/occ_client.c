#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>
#define BUF_SIZE 512
#define FILENAME_SIZE 256
	
void *send_msg(void * arg);
void *recv_msg(void * arg);
void error_handling(char * msg);
	
char filename[FILENAME_SIZE];
char msg[BUF_SIZE];

// uploads the C program to the server.
// receive the result from server (error/warring/displayed result) and print it

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void * thread_return;
	if (argc != 4) {
		printf("Usage : %s <IP> <port> <filename>\n", argv[0]);
		exit(1);
	 }
	
	strcpy(filename, argv[3]);
	sock = socket(PF_INET, SOCK_STREAM, 0);
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	  
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	
	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);
	close(sock);  
	return 0;
}
	
void *send_msg(void * arg){
	int sock = *((int*)arg);
	int fd, readLen;
	int filenamesize = strlen(filename);
//	printf("[send_msg] try to read file: %s\n", filename);
	if((fd = open(filename, O_RDONLY)) <= 0){
		perror("cannot open file: may the file not exist\n");
		exit(EXIT_FAILURE);
	}
	
	//header: filenamesize, filename, contents
	write(sock, &filenamesize, sizeof(int));
	write(sock, filename, filenamesize);
	
	while (readLen = read(fd, msg, BUF_SIZE)){
		//msg has the contents...
		//msg[readLen-1] = 0;
//		printf("$ %s\n", msg);
		write(sock, msg, readLen);
	}

//	printf("[send_msg] done sending file\n");
	shutdown(sock, SHUT_WR);
	close(fd);
	return NULL;

}
	
void *recv_msg(void * arg){
	int sock = *((int*)arg);
	char buf[BUF_SIZE];
	int readLen;
	printf("Result from Server\n");
	while (readLen = read(sock, buf, BUF_SIZE-1)){
		if (readLen == -1) 
			return (void*)-1;
		buf[readLen-1] = 0;
		printf("%s\n", buf);
	}

	return NULL;
}
	
void error_handling(char *msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}
