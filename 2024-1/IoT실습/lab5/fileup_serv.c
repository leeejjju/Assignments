#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

/*
22100579 Jinju Lee
I choosed Edge-triggerd mode.
Because the way helps me to understatd logics "receiving pakcets" and "using them" separately. 
*/

#define BUF_SIZE 1024
#define EPOLL_SIZE 50
#define OPEN_MAX 1024
#define FILE_MAX 256

void setnonblockingmode(int fd){
	int flag=fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}
void error_handling(char *buf){
	fputs(buf, stderr);
	fputc('\n', stderr);
	exit(1);
}

FILE *clnt_fp[OPEN_MAX];

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t adr_sz;
	int str_len, i;
	char buf[BUF_SIZE];

	struct epoll_event *ep_events;
	struct epoll_event event;
	int epfd, event_cnt;

	if(argc!=2) {
		printf("Usage : %s <Listen port>\n", argv[0]);
		exit(1);
	}

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1) error_handling("bind() error");
	if(listen(serv_sock, 5)==-1) error_handling("listen() error");

	epfd=epoll_create(EPOLL_SIZE);
	ep_events=malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

	setnonblockingmode(serv_sock);
	event.events=EPOLLIN;
	event.data.fd=serv_sock;	
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

	printf("serv sock: %d\n", serv_sock);

	while(1){
		event_cnt=epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
		if(event_cnt==-1){
			puts("epoll_wait() error");
			break;
		} //else puts("return epoll_wait");

		for(i = 0; i < event_cnt; i++){
		
			int sock = ep_events[i].data.fd;
			printf("checking sock: %d\n", sock);	

			//server event: new client
			if(sock==serv_sock) {
				adr_sz=sizeof(clnt_adr);
				clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
				setnonblockingmode(clnt_sock);
				event.events=EPOLLIN|EPOLLET;
				event.data.fd=clnt_sock;
				epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
				printf("	new clinet %d added on serv %d\n", clnt_sock, sock);

			}else { //client event: file recved
				printf("	connected client: %d \n", sock);
				char filepath[BUF_SIZE+128];

				//save the filename and open new file on first step
				if(clnt_fp[sock] == NULL){
					int filename_size = 0;
					if(read(sock, &filename_size, sizeof(int)) < 0) error_handling("read(): ");
					if(read(sock, buf, filename_size) < 0) error_handling("read(): ");
					buf[filename_size] = 0;
					printf("	recved filename -> %s[%d]\n", buf, filename_size);
					sprintf(filepath, "dest/%s", buf);
					printf("	filepath: %s\n", filepath);
					if((clnt_fp[sock] = fopen(filepath, "wb")) == NULL) error_handling("fopen() error:");
				}

				while(1){
					str_len = read(sock, buf, BUF_SIZE);

					//close request
					if(str_len == 0) { 
						int x = 0;
						printf("	close request from clnt %d\n", sock);

						epoll_ctl(epfd, EPOLL_CTL_DEL, sock, NULL);
						close(sock);
						if(clnt_fp[sock] != NULL) fclose(clnt_fp[sock]); //close file
						printf("	closed client: %d | saved file on %s\n", sock, filepath);
						if(clnt_fp[sock] != NULL) clnt_fp[sock] = NULL; //flag reset
						break;

					} else if(str_len > 0){ //file save
						buf[str_len] = 0;
						printf("	recved contents -> %s[%d]\n", buf, str_len);
						fwrite(buf, 1, str_len, clnt_fp[sock]);			
					} else if(str_len < 0) if(errno==EAGAIN) break; //end of contents
				} //wihle
			} //else
		} //for
	} //while
	
	close(serv_sock);
	close(epfd);
	return 0;
}

