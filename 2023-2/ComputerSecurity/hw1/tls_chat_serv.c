#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 100
#define MAX_CLNT 256
#define SERVER_CERT "keys/server.crt"
#define SERVER_KEY "keys/server.key"
#define TEXT 0
#define FILE_UPLOAD 1
//#define BREAK break;
#define BREAK ;

//#define DEBUG
//#define ALIVE printf("im alive!:%d\n",idx++);
#define ALIVE idx++;

void *handle_clnt(void * arg);
void send_msg(SSL *ssl, char * msg, int len);
void error_handling(char * msg);
void remove_disconnected_client_ssl(SSL *clnt_ssl);
void info_callback(const SSL *ssl, int type, int val);
int getFile(SSL* ssl, char* filename);
int sendFile(char* filename);

int clnt_cnt = 0;
SSL *clnt_ssls[MAX_CLNT];
pthread_mutex_t mutx;
SSL_CTX *ctx; 
int idx = 0;
char MODE[2][20] = {"TEXT", "FILE_UPLOAD"};


int main(int argc, char *argv[]){
	
	#ifdef DEBUG
		printf("[main]: im in!\n");
	#endif

	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	SSL *ssl;
	SSL_library_init();	
	OpenSSL_add_ssl_algorithms();
	SSL_load_error_strings();
	ERR_print_errors_fp(stderr);
	
	ctx = SSL_CTX_new(TLS_server_method()); // SSL context 생성
    if( SSL_CTX_use_certificate_file(ctx, SERVER_CERT, SSL_FILETYPE_PEM) <= 0 || SSL_CTX_use_PrivateKey_file(ctx, SERVER_KEY, SSL_FILETYPE_PEM) <= 0){
		printf("faild to useing crt, key files\n");
        exit(1);
	}
	SSL_CTX_set_cipher_list(ctx, "TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384");
	//SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
	SSL_CTX_set_ecdh_auto(ctx, 1);

	ALIVE //0

	pthread_mutex_init(&mutx, NULL);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	ALIVE //1

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; 
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	
	if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");
	
    ALIVE //2

	while (1){
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_sz);
		
		ssl = SSL_new(ctx);
		#ifdef DEBUG
		SSL_set_info_callback(ssl, info_callback);
		#endif
		SSL_set_fd(ssl, clnt_sock);
		SSL_set_options(ssl, SSL_OP_ALL);
		int ret;
   		//if ((ret = SSL_connect(ssl)) == -1){
   		if ((ret = SSL_accept(ssl)) <= 0){
        	int ssl_err = SSL_get_error(ssl, ret);
        	if (ssl_err == SSL_ERROR_SSL) ERR_print_errors_fp(stderr);
        	else fprintf(stderr, "SSL_connect failed with error code: %d\n", ssl_err);
        	SSL_free(ssl);
			close(clnt_sock);
			continue;
    	}
		// SSL/TLS 핸드셰이크에서 협상된 암호화 알고리즘 확인
		const SSL_CIPHER *cipher = SSL_get_current_cipher(ssl);
		const char *cipher_name = SSL_CIPHER_get_name(cipher);
		printf("Negotiated Cipher: %s\n", cipher_name);
		
		pthread_mutex_lock(&mutx);
		clnt_ssls[clnt_cnt++] = ssl; //SSL: added for multithreading
		pthread_mutex_unlock(&mutx);
	
		pthread_create(&t_id, NULL, handle_clnt, (void*)ssl);
		pthread_detach(t_id);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
		
		//SSL_shutdown(ssl);
        //SSL_free(ssl);
		//close(clnt_sock);
	}

	ALIVE //3
	
	//TODO idk if it is needed...
	for (int i = 0; i < MAX_CLNT; ++i) if(clnt_ssls[i] != NULL){
		SSL_shutdown(clnt_ssls[i]);
		SSL_free(clnt_ssls[i]);
	}
		
	#ifdef DEBUG
		printf("[main]: im out!\n");
	#endif

	ALIVE //4

	close(serv_sock);
	SSL_CTX_free(ctx);
	return 0;
}

//not working
int getFile(SSL* ssl, char* filename){
	#ifdef DEBUG
		printf("[getFile]: im in!\n");
	#endif

	char buf[BUF_SIZE];
	int readsize = 0, writesize = 0;

	FILE* fp = fopen(filename, "wb");
	//recv header -> filesize filecontents
	int filesize;
	SSL_read(ssl, &filesize, sizeof(int));

	while(filesize > 0){
		
		if((readsize = SSL_read(ssl, buf, BUF_SIZE)) <= 0) BREAK
		printf("read from client: %d\n", readsize); //xxx
		buf[readsize-1] = 0;
		printf("[getFile] %s###", buf);
		if((writesize = fwrite(buf, readsize, 1, fp)) <= 0) BREAK	
		printf("write to file: %d\n", readsize); //xxx	
		#ifdef DEBUG
			printf("[getFile] %s", buf);
		#endif
		filesize -= readsize;
	}
	#ifdef DEBUG
		printf("[getFile]: im out!\n");
	#endif


	//fclose file
	fclose(fp);
	return 0;
	
}

//not working
int sendFile(char* filename){
	#ifdef DEBUG
		printf("[sendFile]: im in!\n");
	#endif


	char buf[BUF_SIZE];
	int readsize = 0, writesize = 0, i = 0;

	FILE* fp = fopen(filename, "rb");
	//get fileLen
	int filenamesize = sizeof(filename);
	int filesize = 0, mode = FILE_UPLOAD;
	
	//send header -> filenamesize filename filesize
	for (i = 0; i < clnt_cnt; i++) {
		SSL_write(clnt_ssls[i], &mode, sizeof(int));
		SSL_write(clnt_ssls[i], &filenamesize, sizeof(int));
		SSL_write(clnt_ssls[i], filename, sizeof(filename));
		SSL_write(clnt_ssls[i], &filesize, sizeof(int));
	}

	pthread_mutex_lock(&mutx);
	//send contents
	for (i = 0; i < clnt_cnt; i++){
		while(!feof(fp)){
			if((readsize = fread(buf, BUF_SIZE, 1, fp)) <= 0) BREAK
			buf[readsize-1] = 0;
			printf("read from file: %d\n", readsize); //xxx
			printf("[sendFile] %s###", buf);
			if((writesize = SSL_write(clnt_ssls[i], buf, readsize)) <= 0) BREAK
			printf("write to client: %d\n", readsize); //xxx
		}
		#ifdef DEBUG
			printf("[sendFile] send %s to one user\n", filename);
		#endif
	}
	pthread_mutex_unlock(&mutx);
	#ifdef DEBUG
		printf("[sendFile] done sending %s\n", filename);
	#endif



	fclose(fp);
	return 0;
}

void *handle_clnt(void * arg){	
	#ifdef DEBUG
		printf("[handle_clnt]: im in!\n");
	#endif

	//int clnt_sock = *((int*)arg);
	SSL *ssl = (SSL*)arg;
	int str_len, i, mode;
	char msg[BUF_SIZE];

	while(1){
		if((str_len = SSL_read(ssl, &mode, sizeof(mode))) <= 0) break;
		printf("[handle_clnt] recved mode: %s\n", MODE[mode]);

		if(mode == TEXT){
			if((str_len = SSL_read(ssl, msg, sizeof(msg))) <= 0) break;
			send_msg(ssl, msg, str_len);
			printf("[handle_clnt] recv message: %s\n", msg);
		}else if(mode == FILE_UPLOAD){
			
			// int size;
			// //recv header : filenamesize filename
			// if((str_len = SSL_read(ssl, &size, sizeof(size))) <= 0) break;
			// if((str_len = SSL_read(ssl, msg, size)) <= 0) break;
			// getFile(ssl, msg);
			// sendFile(msg);
			// printf("[handle_clnt] filename: %s\n", msg);
			printf("[system] We do not support file upload system yet, sorry\n");
		}
	}

	if (str_len < 0) {
	    int ssl_err = SSL_get_error(ssl, str_len);
	    if (ssl_err == SSL_ERROR_ZERO_RETURN) {
	    } else if (ssl_err == SSL_ERROR_SYSCALL) {
			perror("[handle_clnt] Error during SSL_read");
	    } else if (ssl_err == SSL_ERROR_SSL) {
	        ERR_print_errors_fp(stderr);
	    }
	}

	remove_disconnected_client_ssl(ssl);
	#ifdef DEBUG
		printf("[handle_clnt]: im out!\n");
	#endif
	return NULL;

}

//send to all
void send_msg(SSL *ssl, char * msg, int len){
	#ifdef DEBUG
		printf("[send_msg]: im in!\n");
	#endif

	int str_len, i, mode = TEXT;
	#ifdef DEBUG
		printf("[send_msg] try to sends message: %s\n", msg);
	#endif
	pthread_mutex_lock(&mutx);
	for (i = 0; i < clnt_cnt; i++){
		str_len = SSL_write(clnt_ssls[i],&mode, sizeof(mode));
		str_len = SSL_write(clnt_ssls[i], msg, len);
	}
	#ifdef DEBUG	
		printf("[send_msg] write %dbyte succesfully\n", str_len);
	#endif
	if (str_len <= 0) {
	    int ssl_err = SSL_get_error(clnt_ssls[i], str_len);
		if (ssl_err == SSL_ERROR_ZERO_RETURN) {
	    } else if (ssl_err == SSL_ERROR_SYSCALL) {
			perror("[send_msg] Error during SSL_write");
	    } else if (ssl_err == SSL_ERROR_SSL) {
	        ERR_print_errors_fp(stderr);
	    }
	}


	pthread_mutex_unlock(&mutx);
	#ifdef DEBUG
		printf("[send_msg]: im out!\n");
	#endif


}

void remove_disconnected_client_ssl(SSL *clnt_ssl) {
    #ifdef DEBUG
		printf("[remove_disconnected_client_ssl]: im in!\n");
	#endif

	pthread_mutex_lock(&mutx);
    for (int i = 0; i < clnt_cnt; i++) {
        if (clnt_ssl == clnt_ssls[i]) {
            while (i < clnt_cnt - 1) {
                clnt_ssls[i] = clnt_ssls[i + 1];
                i++;
            }
            break;
        }
    }
    clnt_cnt--;
    pthread_mutex_unlock(&mutx);

    // SSL 연결 종료
    SSL_shutdown(clnt_ssl);
    SSL_free(clnt_ssl);
	#ifdef DEBUG
		printf("[remove_disconnected_client_ssl]: im out!\n");
	#endif
}

void error_handling(char * msg){
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


