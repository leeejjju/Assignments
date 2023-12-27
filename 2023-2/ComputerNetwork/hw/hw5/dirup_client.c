#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <arpa/inet.h>
#define BUF_SIZE 1024
// #define DEBUG

void *send_files(void* arg);
void *send_file(void * arg);
// void *recv_msg(void * arg);
void error_handling(char * msg);
int get_filecount(char* path);

char dirname[PATH_MAX];
char serv_ip[PATH_MAX];
int dirnamelen;
char msg[BUF_SIZE];
int filecount = 0;
int is_cancle = 0;
int new_port;
int done = 0;

//stop file uploading
void sigint_handler(int signum) {
    
    //TODO send cancle message
    printf("CTRL+C pressed!\n");
    is_cancle = 1;
    exit(1);
    
}

// uploads all files and subdirs to server
// receive the result from server and print it
int main(int argc, char *argv[]){
    signal(SIGINT, sigint_handler);
	
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void * thread_return;
	if (argc != 4) {
		printf("Usage : %s <IP> <port> <dirname>\n", argv[0]);
		exit(1);
	 } 
     strcpy(dirname, argv[3]);
     strcpy(serv_ip, argv[1]);
     dirnamelen = strlen(dirname);

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(serv_ip);
	serv_addr.sin_port = htons(atoi(argv[2]));
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	filecount = get_filecount(dirname);//get filecount of dir

    //서버에 뭐좀 보내것다~ 하고 말을 걸어봐
    write(sock, &dirnamelen, sizeof(int));
    write(sock, dirname, dirnamelen);
    write(sock, &filecount, sizeof(int));
    #ifdef DEBUG
    printf("%s(%d) : %d files\n", dirname, dirnamelen, filecount);
    #endif
    //나만의 작은 port를 받아와
    read(sock, &new_port, sizeof(new_port));
    #ifdef DEBUG
    printf("new port: %d\n", new_port);
    #endif

    
    //TODO 새로운 포트로 파일들을 마구마구 전송해버려... 
    pthread_t mainRoutine;
    pthread_create(&mainRoutine, NULL, send_files, (void*)&dirname);
    pthread_join(mainRoutine, NULL);
    printf("%d/%d files has been uploaded!", done, filecount);


	// pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
    // pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	// pthread_join(snd_thread, &thread_return);
    // //종료 메시지 보내
	// pthread_join(rcv_thread, &thread_return);
	// close(sock);
	// return 0;
    close(sock);
    return 0;

}

//search the dirs and send files in it, return num of file succesfully sends
void* send_files(void* arg){

    char* path = (char*) arg;
    DIR *dir;
    struct dirent *one;
    if (!(dir = opendir(path))) {
        perror("opendir");
        return NULL;
    }

    //check files in dir seqencly
    //if its file, make thread for upload it
    //if its dir, call send_files recursively
    pthread_t sendings[filecount];
    void* returnstat[filecount];
    int cnt = 0;
    void* thread_return;

    while((one = readdir(dir)) != NULL){
        char* dname = one->d_name;
        char filepath[PATH_MAX];
        sprintf(filepath, "%s/%s", path, one->d_name);
        #ifdef DEBUG
            printf("searcing %s...\n", filepath);
        #endif

        if(one->d_type == DT_DIR){ //dir: recursively explore 
            if (strcmp(one->d_name, ".") == 0 || strcmp(one->d_name, "..") == 0) continue;
            #ifdef DEBUG
            printf("Directory: %s\n", filepath);
            #endif
            send_files(filepath);

        }else if(one->d_type == DT_REG){ //file: copy it to destination path 
            #ifdef DEBUG
            printf("File: %s\n", filepath);
            #endif
            char* thread_param = strdup(filepath);
            pthread_create(&sendings[cnt++], NULL, send_file, (void*)thread_param);
        }
    }
    #ifdef DEBUG
    printf("    ## done exploring %s!\n", path);
    printf("    ## need to wait %d threads...\n", cnt);
    #endif

    //join the threads made.
    for(int i = 0; i < cnt; i++) pthread_join(sendings[i], &returnstat[i]);
	#ifdef DEBUG
    printf("[%s] done joining...\n", path);
    #endif
    void* exitstat = 0;
    for(int i = 0; i < cnt; i++) {
        if(returnstat[i] == exitstat) done++;
    }
    #ifdef DEBUG
    printf("    ## all threads are done with %s(%d)\n", path, done);
    #endif
    
    closedir(dir);
    return NULL;

}

//connect new sock, read file and send to server
void *send_file(void * arg){
    char* filepath = (char*)arg;
    
    struct sockaddr_in serv_addr;
	int send_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(serv_ip);
	serv_addr.sin_port = htons(new_port);
	if (connect(send_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");

    int filepathlen = strlen(filepath);
	int filesize = 999;                     //TODO filesize
    int len = 0;
    write(send_sock, &filepathlen, sizeof(int));
	write(send_sock, filepath, filepathlen);
	len = write(send_sock, &filesize, sizeof(int));
    if(len > 0) printf("[%s] send … %dbytes\n", filepath, filesize);
    else printf("[%s] error during write\n", filepath);

    //TODO send file contents

    char buf[BUF_SIZE];
	int fd;
	if((fd = open(filepath, O_RDONLY)) <= 0){
		perror("cannot open file: may the file not exist\n");
		exit(EXIT_FAILURE);
	}
	while (len = read(fd, buf, BUF_SIZE)){
		#ifdef DEBUG
        printf("$ %s\n", buf);
        #endif
        buf[len] = 0;
		write(send_sock, buf, len);
	}
	close(fd);
    shutdown(send_sock, SHUT_WR);

    #ifdef DEBUG
    printf("[%s] waiting for answer of server... \n", filepath);
    #endif
    char answer[PATH_MAX+BUF_SIZE];
	len = read(send_sock, &answer, sizeof(answer));
    if(len > 0) printf("[%s]%s", filepath, answer);
    else printf("[%s] error during read\n", filepath);
    
    close(send_sock);
    #ifdef DEBUG
    printf("[%s] succesfully closed\n", filepath);
    #endif
    return NULL;

}

int get_filecount(char* path){
    DIR *dir;
    struct dirent *entry;
    if (!(dir = opendir(path))) {
        perror("opendir");
        return -1;
    }

    int cnt = 0;
    while ((entry = readdir(dir)) != NULL) {
        // ignore . and .. 
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        struct stat statbuf;
        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) cnt += get_filecount(filepath);//dir
        else cnt ++;//file

    }
    closedir(dir);
    return cnt;
}

void error_handling(char *msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}
