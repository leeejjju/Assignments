#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>
#define SEC_WEBSOCKET_KEY "erPKMz5t9vwqkJI+RmHnLw=="
#define BUFFER_SIZE 1024


//for convert 64bit data to network byte order...
uint64_t htonll(uint64_t value) {
    return ((uint64_t)htonl(value & 0xFFFFFFFF) << 32) | htonl(value >> 32);
}

void printFrame(char* frame, int framelen){

	for(int i = 0; i < framelen; i++) {
		uint8_t offset = 1 << 7;
		for(int j = 0; j < 8; j++){
			printf("%d", ((frame[i]&offset)!=0)?1:0);
			offset >>= 1;
		}
		printf(" ");
		if((i+1)%4 == 0) printf("\n");
	}
	printf("\n");

}

//fill frame and return framelen
int fill_frame(int op, char* payload, int paylen, char* frame){

	int framelen = 0;

	//send flags and opcode
	uint8_t flag_op = 128 | op; //FIN=1, opcode=1
	*(frame + framelen) = flag_op;
	framelen += 1;

	//send mask and payload len
	uint8_t mask_paylen = 128; //0b10000000
	if(paylen <= 125){
		mask_paylen |= paylen; //mask using = 1, paylen = payload_len
		*(frame + framelen) = mask_paylen;
		framelen += 1;
	}else if(paylen <= 65535){
		mask_paylen &= 126; //mask using = 1, paylen = 126
		*(frame + framelen) = mask_paylen;
		framelen += 1;
		*(frame + framelen) = htonl(paylen);
		framelen += 2;
		
	}else{
		mask_paylen &= 127; //mask using = 1, paylen = 127
		*(frame + framelen) = mask_paylen;
		framelen += 1;
		*(frame + framelen) = htonll(paylen);
		framelen += 8;
	}

	//send masking key (4byte)
	char masking_key[4];
	for(int i = 0; i < 4; i++) masking_key[i] = 0;//rand()%128;
	memcpy((frame+framelen), masking_key, sizeof(uint32_t));
	framelen += 4;

	//send payload data (masked...)
	for(int i = 0; i < paylen; i++) payload[i] ^= masking_key[i%4];
	memcpy((frame+framelen), payload, paylen);
	framelen += paylen;

	return framelen;


}

//recv frame, fill payload, return paylen
void recv_payload(int sock, char* payload){

    char buffer[BUFFER_SIZE];
	int len, recv_paylen;
	if((len = recv(sock, buffer, sizeof(buffer), 0)) < 0) perror("send");
	buffer[len] = 0;

	//get payload
	memset(payload, 0, sizeof(payload));
	recv_paylen = *(buffer + 1)&127;
	if(recv_paylen <= 125) strcpy(payload, (buffer+2));
	else if(recv_paylen <= 126) strcpy(payload, (buffer+4));
	else if(recv_paylen <= 127) strcpy(payload, (buffer+10));


}

int main(int argc, char *argv[]) {
    
    // Declare variables 
    char buffer[BUFFER_SIZE];
	char payload[BUFFER_SIZE];
	int len;

    // Check command line arguments.
    if(argc != 4){
        printf("Usage: %s <host> <port> <text>\n"  \
               "Example: \n" \
               "        %s 192.168.10.25 8080 \'Hello, world!\'\n", argv[0], argv[0]); 
        return -1;
    } else strcpy(payload, argv[3]);

    // Connect to host 
	struct sockaddr_in serv_addr;
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) perror("connect");


    // Send WebSocket handshake request
    char *request = "GET %s HTTP/1.1\r\n"
                    "Host: %s:%d\r\n"
                    "Upgrade: websocket\r\n"
                    "Connection: Upgrade\r\n"
                    "Sec-WebSocket-Key: %s\r\n"
                    "Sec-WebSocket-Version: 13\r\n"
                    "\r\n";                    
    sprintf(buffer, request, argv[1], argv[1], atoi(argv[2]), SEC_WEBSOCKET_KEY);


	//initial handhsake? 
	if(send(sock, buffer, strlen(buffer), 0) < 0) perror("send");
    // Wait for HTTP response from server
	if((len = recv(sock, buffer, sizeof(buffer), 0)) < 0) perror("send");
	buffer[len] = 0;
	printf("%s\n", buffer);

    // Verify accept key -> no need to implement 
	/*
	char* accept_key = strtok(buffer, "\n");
	accept_key = strtok(NULL, "\n");
	accept_key = strtok(NULL, "\n");
	accept_key = strtok(NULL, "\n");
	printf("accpet_key: %s\n", accept_key);
	*/

    // Send WebSocket message   
	char* frame = (char*)malloc(sizeof(char)*(16 + strlen(payload)));
	int framelen = fill_frame(1, payload, strlen(payload), frame);
	if(send(sock, frame, framelen, 0) < 0) perror("send");
	printf("Send message to server: %s\n", argv[3]);
//	printFrame(frame, framelen);

	// Wait for echo response message from server
	recv_payload(sock, payload);
	printf("Receive message from server: %s\n", payload);
//	printFrame(frame, framelen);

    // Send close frame: Close code = 1000 
    // Close code must be converted to network byte order via htons() 
	free(frame);
	uint16_t status_code = 1000;
    frame = (char*)malloc(sizeof(char)*(16 + sizeof(status_code)));
	framelen = fill_frame(8, (char*)&status_code, sizeof(status_code), frame);
	if(send(sock, frame, framelen, 0) < 0) perror("send");
//	printf("Send closing msg to server\n");
//	printFrame(frame, framelen);

    // Receive close response from server 
	uint16_t recv_status_code;
    recv_payload(sock, (char*)&recv_status_code);
//	printf("Receive closing msg from server\n");
//	printFrame(frame, framelen);
	
    // Close socket descriptor
	close(sock);
        
    return 0;
}
