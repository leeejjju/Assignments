#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUF_SIZE 65536
#define SYN 0
#define ACK -1

#define HEADER_SIZE sizeof(struct iphdr)+sizeof(struct tcphdr)
// Before run this code, execute the command below 
// $ sudo iptables -A OUTPUT -p tcp --tcp-flags RST RST -j DROP

unsigned short checksum(unsigned short* buf, int size);
char* fill_ip_header(char* buffer, int data);
char* fill_tcp_header(char* sbuffer, char* rbuffer, int data);
int get_d_port(char* buffer);
unsigned long get_seqnum(char* buffer);
unsigned long get_acknum(char* buffer);
void fill_tcp_checksum(char* packet, char* data);

// TODO: pseudo header needed for tcp header checksum calculation
struct pseudo_header{
	u_int32_t saddr;
	u_int32_t daddr;
	u_int8_t zero;
	u_int8_t ptcl;
	u_int16_t tcpLen;
};

char *s_ip, *d_ip; //for string form source addr, destination addr, port
int s_port, d_port;

void print_header(char* head, int size){
	char* tmp = head;
	int loop = size*8/32;
	printf("--------------header--------------\n");
	for(int i = 0; i < loop; i++) printf("%08b %08b %08b %08b\n", *(tmp++), *(tmp++), *(tmp++), *(tmp++));
	printf("----------------------------------\n");
}
// TODO 
int main(int argc, char *argv[]){
	if (argc != 4){
		printf("Usage: %s <Source IP> <Destination IP> <Destination Port>\n", argv[0]);
		return 1;
	}

	//get the arguments
	s_ip = argv[1];
	d_ip = argv[2];
	d_port = atoi(argv[3]);
	printf("%s -> %s(%d)\n", s_ip, d_ip, d_port);

	srand(time(NULL));

	int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
	if (sock == -1){
		perror("socket");
        exit(EXIT_FAILURE);
	}

	// Source IP
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	s_port = rand() % 65535;
	saddr.sin_port = htons(s_port); // random client port
	printf("s_port: %d -> d_port: %d\n", s_port, d_port);

	if (inet_pton(AF_INET, argv[1], &saddr.sin_addr) != 1){
		perror("Source IP configuration failed\n");
		exit(EXIT_FAILURE);
	}

	// Destination IP and Port 
	struct sockaddr_in daddr;
	daddr.sin_family = AF_INET;
	daddr.sin_port = htons(atoi(argv[3]));
	if (inet_pton(AF_INET, argv[2], &daddr.sin_addr) != 1){
		perror("Destination IP and Port configuration failed");
		exit(EXIT_FAILURE);
	}

	// Tell the kernel that headers are included in the packet
	int one = 1;
	const int *val = &one;
	if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) == -1){
		perror("setsockopt(IP_HDRINCL, 1)");
		exit(EXIT_FAILURE);
	}

	ssize_t len = 0;
	char spacket[BUF_SIZE], rpacket[BUF_SIZE], message[BUF_SIZE];


	// TCP Three-way Handshaking 
	// Step 1. Send SYN (no need to use TCP options)
	fill_tcp_header(fill_ip_header(spacket, 0), NULL, SYN);
	fill_tcp_checksum(spacket, NULL);
	if((len = sendto(sock, spacket, HEADER_SIZE, 0, (struct sockaddr*)&daddr, (socklen_t)sizeof(daddr))) <= 0) perror("send error: ");
	printf("%d SYN packet sended...\n", len);

	// Step 2. Receive SYN-ACK
	while(get_d_port(rpacket) != s_port) {
		if((len = recv(sock, rpacket, HEADER_SIZE, 0)) <= 0) perror("recv error: ");
		printf("port %d receved...\n", get_d_port(rpacket));
	}

	printf("%d SYN-ACK packet receved...\n", len);

	// Step 3. Send ACK 
	fill_tcp_header(fill_ip_header(spacket, 0), rpacket, ACK);
	fill_tcp_checksum(spacket, NULL);
	if((len = sendto(sock, spacket, HEADER_SIZE, 0, (struct sockaddr*)&daddr, (socklen_t)sizeof(daddr))) <= 0) perror("send error: ");
	printf("%d ACK packet sended...\n", len);


	// Data transfer 
	while (1) {
		fputs("Input spacket(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);
		
		if (!strcmp(message, "q\n") || !strcmp(message,"Q\n")) break;
		if (strlen(message) == 0) continue;

		// Step 4. Send an application spacket (with PSH and ACK flag)! 
		char* data = fill_tcp_header(fill_ip_header(spacket, strlen(message)), rpacket, strlen(message));
		memcpy(data, message, strlen(message));
		fill_tcp_checksum(spacket, message);
		//len = sendto(sock, spacket, sizeof(spacket), 0, (sockaddr_in*)&daddr, sizeof(daddr));
		if((len = sendto(sock, spacket, HEADER_SIZE+strlen(message), 0, (struct sockaddr*)&daddr, (socklen_t)sizeof(daddr))) <= 0) perror("send error: ");
		printf("%d PSH packet sended...\n", len);
		
		// Step 5. Receive ACK
		while(get_d_port(rpacket) != s_port) len = recv(sock, rpacket, BUF_SIZE, 0);
		printf("%d ACK packet recved...\n");
	}

	close(sock);
	return 0;
}


unsigned short checksum(unsigned short* buf, int size){

	printf("size to calculate checksum: %d\n", size);
	int loop = (size*8)/16; //how many loop...
	int remain = (size*8)%16; //remain bits...
	int sum = 0;
	unsigned short result = 0;

	//add all the fragmented 16bit contents
	for(int i = 0; i < loop; i++){
		//printf("   %016b\n + %016b\n", sum, *buf);	
		sum += *buf;
		buf++;
		//printf("   %016b\n\n", sum);
	}

	//add remain of contents
	if(remain) sum += *buf;
	//if(remain) sum += (*buf >> 16);
	//add carry if exist
	if(sum >> 16) sum += (sum >> 16);

	
	//printf("sum: %016b\n", sum);
	//reverse it
	sum ^= 0xFFFF;	
	result = sum;
	//printf("sum: %016b\n", sum);
	//printf("sum: %016b\n", result);

	return sum;
}


// fill the ip header
// return the next start point of buffer
char* fill_ip_header(char* buffer, int data){
	memset(buffer, 0, BUF_SIZE); //initialize the buffer

	//fill the IP header
	struct iphdr *ip = (struct iphdr*)buffer;
	ip->version = IPPROTO_IPIP; //4 for IPv4
	ip->ihl = 5; //header size 4*n, n=5
	ip->tot_len = htons(40+data); //ip header size(20byte) + tcp header size(20byte) + payload(0)
	ip->id = 0; //randomly...
	ip->frag_off = htons(1 << 14); //010 for no fragmentation, others are 0
	ip->ttl = 64; //randomly...
	ip->protocol = IPPROTO_TCP; //6 for tcp
	ip->saddr = inet_addr(s_ip);
	ip->daddr = inet_addr(d_ip);
	ip->check = htons(checksum((unsigned short*)ip, sizeof(*ip))); 

//	printf("ip\n");
//	print_header((char*)ip, sizeof(*ip));

	return (buffer + sizeof(struct iphdr));

}

// fill the tcp header
// param type-> 0: SYN, -1: ACK, 0 < : PSH and the number is data size
char* fill_tcp_header(char* sbuffer, char* rbuffer, int data){

	unsigned long seqnum = 0, acknum = 0;
	struct tcphdr *tcp = (struct tcphdr*)sbuffer;
	if(data == SYN){
		tcp->syn = 1;
		seqnum = 0;
	}else if(data == ACK){
		tcp->ack = 1;
		seqnum = ntohl(get_acknum(rbuffer));
		acknum = ntohl(get_seqnum(rbuffer)) + 1;
		printf("sibal's seq: %d\n", ntohl(get_seqnum(rbuffer)));
	}else{
		tcp->ack = 1;
		tcp->psh = 1;
		seqnum = htonl(get_acknum(rbuffer));
		acknum = ntohl(get_seqnum(rbuffer));
	}

	tcp->source = htons(s_port);
	tcp->dest = htons(d_port);
	tcp->seq = htonl(seqnum);
	tcp->ack_seq = htonl(acknum);
	tcp->doff = 5; //header size: 4*n, n=5
	tcp->window = htons(16000); //randomly...
	tcp->check = 0; //later...
	
//	printf("tcp\n");
//	print_header((char*)tcp, sizeof(*tcp));
	return (sbuffer + sizeof(struct tcphdr));

}

/*
struct pseudo_header{
	unsigned long saddr;
	unsigned long daddr;
	char zero;
	char ptcl;
	unsigned short tcpLen;
}
*/
void fill_tcp_checksum(char* packet, char* data){

	char buffer[BUF_SIZE];
	struct iphdr *ip = (struct iphdr*)packet;
	struct tcphdr *tcp = (struct tcphdr*)(packet + sizeof(struct iphdr));

	//fill the pseudo_header
	struct pseudo_header *phdr = (struct pseudo_header*)buffer;
	phdr->saddr = ip->saddr;
	phdr->daddr = ip->daddr;
	phdr->zero = 0;
	phdr->ptcl = IPPROTO_TCP;
	if(data) phdr->tcpLen = htons(sizeof(struct tcphdr) + strlen(data));
	else phdr->tcpLen = htons(sizeof(struct tcphdr));	
	
//	printf("pseudo header\n");
//	print_header((char*)phdr, sizeof(struct pseudo_header));

	//attach the tcphdr and data(if exist)
	memcpy(buffer+sizeof(struct pseudo_header), tcp, sizeof(struct tcphdr));

	if(data != NULL){
		memcpy(buffer+sizeof(struct pseudo_header)+sizeof(struct tcphdr), data, strlen(data));
		tcp->check = checksum((unsigned short*)buffer, sizeof(struct pseudo_header)+sizeof(struct tcphdr)+strlen(data));
	}else{
		tcp->check = checksum((unsigned short*)buffer, sizeof(struct pseudo_header)+sizeof(struct tcphdr));
	}
	

//	print_header(buffer, sizeof(struct pseudo_header)+sizeof(struct tcphdr));
//	printf("tcp\n");
//	print_header((char*)tcp, sizeof(struct tcphdr));
}

int get_d_port(char* buffer){
	struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct iphdr));
	return (int)ntohs(tcp->dest);
	
}

unsigned long get_seqnum(char* buffer){
	struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct iphdr));
	return tcp->seq;
}

unsigned long get_acknum(char* buffer){
	struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct iphdr));
	return tcp->ack_seq;
}





