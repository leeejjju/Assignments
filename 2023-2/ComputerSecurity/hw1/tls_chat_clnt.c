#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/stat.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#define BUF_SIZE 100
#define NAME_SIZE 20
#define TEXT 0
#define FILE_UPLOAD 1
#define BREAK break;
//#define BREAK ;
//#define DEBUG
//#define ALIVE printf("im alive!:%d\n",idx++);
#define ALIVE idx++;

void *send_msg(void * arg);
void *recv_msg(void * arg);
void error_handling(char * msg);
void info_callback(const SSL *ssl, int type, int val);
int getFile(char* filename);
int sendFile(char* filename);

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];
SSL_CTX *ctx; 
SSL *ssl;
int idx = 0;


int main(int argc, char *argv[]){
	#ifdef DEBUG
		printf("[main]: im in!\n");
	#endif

	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void * thread_return;
	if (argc != 4) {
		printf("Usage : %s <IP> <port> <name>\n", argv[0]);
		exit(1);
	 }

	ALIVE //0
	
	//SSL: init and create SSL context
	SSL_load_error_strings();
	OpenSSL_add_ssl_algorithms();
	SSL_library_init();
    if(!(ctx = SSL_CTX_new(TLS_client_method()))){
		printf("error during init ctx\n");
		exit(1);
	}
	SSL_CTX_set_cipher_list(ctx, "TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384");
	//SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
	SSL_CTX_set_ecdh_auto(ctx, 1);
	ERR_print_errors_fp(stderr);
	SSL_CTX_set_session_cache_mode(ctx, SSL_SESS_CACHE_SERVER);

	sprintf(name, "[%s]", argv[3]);
	sock = socket(PF_INET, SOCK_STREAM, 0);

	ALIVE //1

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	  
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");

	ALIVE //2

	//creat SSL and connect it with socket
	ssl = SSL_new(ctx);
	#ifdef DEBUG
		SSL_set_info_callback(ssl, info_callback);
	#endif
	SSL_set_fd(ssl, sock);
	SSL_set_options(ssl, SSL_OP_ALL);
	int ret;
	ALIVE //3
	
	if ((ret = SSL_connect(ssl)) == -1){
		printf("error during SSL_connect()\n");
        int ssl_err = SSL_get_error(ssl, ret);
		if (ssl_err == SSL_ERROR_SYSCALL) perror("Error during SSL_connect");
		else if (ssl_err == SSL_ERROR_SSL) ERR_print_errors_fp(stderr);
		else fprintf(stderr, "SSL_connect failed with error code: %d\n", ssl_err);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        error_handling("SSL_connect() error");
    }
	// SSL/TLS 핸드셰이크에서 협상된 암호화 알고리즘 확인
	#ifdef DEBUG
	const SSL_CIPHER *cipher = SSL_get_current_cipher(ssl);
	const char *cipher_name = SSL_CIPHER_get_name(cipher);
	printf("Negotiated Cipher: %s\n", cipher_name);
	#endif
	ALIVE //4

	pthread_create(&snd_thread, NULL, send_msg, (void*)&ssl);
	ALIVE //5
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&ssl);
	ALIVE //6
	pthread_join(snd_thread, &thread_return);
	ALIVE //7
	pthread_join(rcv_thread, &thread_return);
	ALIVE //8
	
	SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
	#ifdef DEBUG
		printf("[main]: im out!\n");
	#endif

	return 0;
}
	
void *send_msg(void * arg)   // send thread main
{
	#ifdef DEBUG
		printf("[send_msg]: im in!\n");
	#endif
	//SSL *ssl = (SSL*)arg;
	char name_msg[NAME_SIZE+BUF_SIZE];
	char *tmp, *filename;
	int mode = TEXT;

	while (1) {
		fgets(msg, BUF_SIZE, stdin);
		//msg[strlen(msg)-1] = 0;
		#ifdef DEBUG
			printf("[send_msg] input: %s\n", msg);
		#endif
		if (!strcmp(msg,"q\n") || !strcmp(msg,"Q\n")) {
			printf("leaving chatting room...\n");
			exit(0);
		}

		tmp = strtok(msg, ":");
		if(strcmp(tmp, "file_share") == 0){
			filename = strtok(NULL, ":");
			int size = sizeof(filename);
			filename[size-1] = 0;
			printf("sending file %s...\n", filename);
			
			mode = FILE_UPLOAD;
			//send header: mode filenamesize filename
			SSL_write(ssl, &mode, sizeof(mode));
			// SSL_write(ssl, &size, sizeof(size));
			// SSL_write(ssl, filename, size);
			// //send contents
			// sendFile(filename);
			printf("[system] We do not support file upload system yet, sorry\n");

		}else{
			sprintf(name_msg,"%s %s", name, msg);
			
			mode = TEXT;
			SSL_write(ssl, &mode, sizeof(mode));
			SSL_write(ssl, name_msg, strlen(name_msg));
		}

	}
	#ifdef DEBUG
		printf("[send_msg]: im out!\n");
	#endif

	return NULL;
}

	
void *recv_msg(void * arg)   // read thread main
{
	#ifdef DEBUG
		printf("[recv_msg]: im in!\n");
	#endif
	
	char name_msg[NAME_SIZE+BUF_SIZE];
	int str_len, mode = TEXT;
	while (1){
		#ifdef DEBUG
			printf("[recv_msg] waiting for msg from server...\n");
		#endif
		str_len = SSL_read(ssl, &mode, sizeof(mode));

		if(mode == TEXT){

			if((str_len = SSL_read(ssl, name_msg, NAME_SIZE+BUF_SIZE-1)) <= 0) break;
			name_msg[str_len] = 0;
			fputs(name_msg, stdout);
	
			#ifdef DEBUG
				printf("[recv_msg] recv %d bytes\n", str_len);
			#endif

		}else if(mode == FILE_UPLOAD){
			
			// int filenamesize;
			// SSL_read(ssl, &filenamesize, sizeof(filenamesize));
			// SSL_read(ssl, name_msg, filenamesize);
			// getFile(name_msg);
			printf("[system] We do not support file upload system yet, sorry\n");

		}
		
	}
	#ifdef DEBUG
		printf("[recv_msg]: im out!\n");
	#endif

	return NULL;
}


//not work
int getFile(char* filename){
	
	char buf[BUF_SIZE];
	int readsize = 0, writesize = 0;

	FILE* fp = fopen(filename, "wb");
	//recv header -> filesize filecontents
	int filesize;
	SSL_read(ssl, &filesize, sizeof(int));
	printf("[getFile] file size: %d\n", filesize);
	while(filesize > 0){
		if((readsize = SSL_read(ssl, buf, BUF_SIZE)) <= 0) BREAK
		buf[readsize-1] = 0;
		printf("read from file: %d\n", readsize); //xxx
		printf("%s", buf);
		if((writesize = fwrite(buf, readsize, 1, fp)) <= 0) BREAK	
		printf("write to file: %d\n", readsize); //xxx
		#ifdef DEBUG
			printf("[getFile] %s", buf);
		#endif
		filesize -= readsize;
	}

	fclose(fp);
	return 0;
	
}

//not work
int sendFile(char* filename){
	char buf[BUF_SIZE];
	int readsize = 0, writesize = 0, i = 0;

	FILE* fp = fopen(filename, "rb");
	//get fileLen
	int filenamesize = sizeof(filename);
	int filesize = 0, mode = FILE_UPLOAD;
	
	//TODO get filesize
	struct stat file_info;
	if (stat(filename, &file_info) != 0) {
        perror("Error getting file information");
        return 1;
    }
	filesize = file_info.st_size;
	SSL_write(ssl, &filesize, sizeof(int));

	printf("[sendFile] file size: %d\n", filesize);
	//send contents
	while(!feof(fp)){
		if((readsize = fread(buf, BUF_SIZE, 1, fp)) <= 0) BREAK
		buf[readsize-1] = 0;
		printf("read from file: %d\n", readsize); //xxx
		printf("[sendFile] %s", buf);
		if((writesize = SSL_write(ssl, buf, readsize)) <= 0) BREAK
		printf("write to client: %d\n", readsize); //xxx
	}
	#ifdef DEBUG
		printf("[sendFile] done sending %s\n", filename);
	#endif
	
	fclose(fp);
	return 0;
}


void error_handling(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}


void info_callback(const SSL *ssl, int type, int val){
    if (type & SSL_CB_ALERT) {
        fprintf(stderr, "Alert: %s:%s\n", SSL_alert_type_string_long(val), SSL_alert_desc_string_long(val));
    } else {
        fprintf(stderr, "Info: %s\n", SSL_state_string_long(ssl));
    }
}


