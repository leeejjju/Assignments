#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <fcntl.h>
#include <limits.h>
#include <libgen.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#define BUF_SIZE 1024
#define NEW_PORT_BASE 5000
// #define DEBUG

void *handle_clnt(void * arg);
void *recv_file(void * arg);
void error_handling(char * msg);
//make all directorys if not exits : nested mkdir
int makeDirectory(char* path, mode_t mode);



int clnt_cnt = 0;

typedef struct {
    int clnt_sock;
    char* clnt_ip;
	int clnt_port;
} ThreadArgs;

int main(int argc, char *argv[]) {
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
  
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; 
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	int enable = 1;
    if (setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        close(serv_sock);
        exit(EXIT_FAILURE);
    }
	if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1) error_handling("bind() error");
	if (listen(serv_sock, 5) == -1) error_handling("listen() error");

	ThreadArgs args;
	while (1) {
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_sz);
		args.clnt_sock = clnt_sock;
		args.clnt_ip = inet_ntoa(clnt_adr.sin_addr);
		pthread_create(&t_id, NULL, handle_clnt, (void *)&args);
		pthread_detach(t_id);
		
		#ifdef DEBUG
		printf("Connected client IP: %s [%d]\n", inet_ntoa(clnt_adr.sin_addr), atoi(argv[1]));
    	#endif
	}
	close(serv_sock);
	return 0;
}
	
void *handle_clnt(void * arg) {

	ThreadArgs* args = (ThreadArgs*) arg;
	int clnt_sock = args->clnt_sock;
	char* clnt_ip = args->clnt_ip;
	char dir_name[PATH_MAX];
	int dirnamelen;
	int filecount;

	//정보를 읽어와
	read(clnt_sock, &dirnamelen, sizeof(int));
    read(clnt_sock, dir_name, dirnamelen);
    read(clnt_sock, &filecount, sizeof(int));
    printf("%s(%d) : %d files\n", dir_name, dirnamelen, filecount);
	printf("sock: %d  ip: %s\n", clnt_sock, clnt_ip);

	//새로운 port를 보내드려
	int new_port = (NEW_PORT_BASE + clnt_cnt++)%49000;
	write(clnt_sock, &new_port, sizeof(new_port));

	//accept n connection and split them to threads...
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	int serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; 
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(new_port);
	if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1) error_handling("bind() error");
	if (listen(serv_sock, 5) == -1) error_handling("listen() error");
	
	pthread_t sendings[filecount];
	void* returnstat[filecount];

	for(int i = 0; i < filecount; i++) {
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_sz);
		ThreadArgs* new_args = malloc(sizeof(ThreadArgs));
		new_args->clnt_sock = clnt_sock;
		new_args->clnt_ip = inet_ntoa(clnt_adr.sin_addr);
		new_args->clnt_port = new_port;
		#ifdef DEBUG
		printf("Connected client IP: %s [%d] \n", inet_ntoa(clnt_adr.sin_addr), new_port);
		#endif
		pthread_create(&sendings[i], NULL, recv_file, (void *)new_args);
	}

	for(int i = 0; i < filecount; i++) pthread_join(sendings[i], &returnstat[i]);
	int done = 0;
	for(int i = 0; i < filecount; i++) if(returnstat[i] == 0) done++;
	

	printf("The client (%s) has completed the upload of %d/%d files!\n", args->clnt_ip, done, filecount);

	close(serv_sock);
	close(clnt_sock);
	return NULL;
}

//recv file from connection
void *recv_file(void * arg) {

	ThreadArgs* args = (ThreadArgs*) arg;
	int clnt_sock = args->clnt_sock;
	char* clnt_ip = args->clnt_ip;
	int new_port = args->clnt_port;
	
	int filepathlen;
	char filepath[PATH_MAX];
	int filesize;

	read(clnt_sock, &filepathlen, sizeof(int));
	read(clnt_sock, filepath, filepathlen);
	int len = read(clnt_sock, &filesize, sizeof(int));
	if(len < 0) printf("	error occured... [%s]\n", filepath);
	char *directory, *filename;
	directory = dirname(strdup(filepath));
	filename = basename(strdup(filepath));

	//make dir if needed
	makeDirectory(directory, 0777);

	//make file and save the contents
	char buf[BUF_SIZE];
	int fd;
	if((fd = open(filepath, O_WRONLY | O_CREAT)) <= 0){
		perror("cannot open file: may the file not exist\n");
		exit(EXIT_FAILURE);
	}
	while (len = read(clnt_sock, buf, BUF_SIZE)){
		#ifdef DEBUG
		printf("$ %s\n", buf);
		buf[len] = 0;
    	#endif
		write(fd, buf, len);
	}
	close(fd);

	printf("[%s] Received from %s … %d bytes\n", filepath, clnt_ip, filesize);

	char answer[PATH_MAX+BUF_SIZE];
	sprintf(answer, "[%s] Upload completed! … %dbytes\n", filepath, 0); //TODO count
	len = write(clnt_sock, &answer, strlen(answer));
	#ifdef DEBUG
	printf("[%s] send %d byte\n", filepath, len);
    #endif

	close(clnt_sock);
	free(arg);
	return NULL;

}

int makeDirectory(char* path, mode_t mode){

    char* tmp = (char*)malloc(sizeof(char)*strlen(path));
    strcpy(tmp, path);

    for(int i = 0; i < strlen(path); i++){
        if(path[i] == '/'){
            
            tmp[i] = 0; //slicing
            #ifdef DEBUG
            printf("[star] createing directory %s...\n", tmp);
            #endif
            if(mkdir(tmp, mode) == -1){
                #ifdef DEBUG
                printf("[star] directory %s exist!\n", tmp);
                #endif
            }
            strcpy(tmp, path);
        } 
    }

    #ifdef DEBUG
    printf("[star] createing directory %s...\n", tmp);
    #endif
    if(mkdir(tmp, mode) == -1){
        #ifdef DEBUG
        printf("[star] directory %s exist!\n", tmp);
        #endif
    }
    #ifdef DEBUG
    printf("[star] new directory %s created\n", path);
    #endif
    return EXIT_SUCCESS;

}


void error_handling(char * msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
