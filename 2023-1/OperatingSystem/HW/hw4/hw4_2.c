/*
	This program reads an integer expression from the user and computes the result using a child process.
	The parent and child processes communicate with each other through message passing.
	Implement this program following the instructions.
	Append "[parent]" and "[child]" to all messages in Parent() and Child respectively.

	Example)
		p2c = 0, c2p = 1				// the ids of the message queues
		[parent] Input an integer binary expressions(type "quit" to finish.): 5 + 1 	// this user typed "5 + 1"
		[parent] msgsnd() returned = 0
		[child] received 0-th message "5 + 3", ret = 136
		[child] sending 0-th message "8"
		[child] msgsnd() returned = 0
		[parent] msgrcv() returned = 136
		[parent] 5 + 3 = 8
		[parent] Input an integer binary expressions(type "quit" to finish.): 7 *2 	// this user typed "7 *2"
		[parent] msgsnd() returned = 0
		[child] received 1-th message "7 *2", ret = 136
		[child] sending 1-th message "14"
		[child] msgsnd() returned = 0
		[parent] msgrcv() returned = 136
		[parent] 7 *2 = 14
		[parent] Input an integer binary expressions(type "quit" to finish.): 9/2 		// this user typed "9/2"
		[parent] msgsnd() returned = 0
		[child] received 2-th message "9/2", ret = 136
		[child] sending 2-th message "4"
		[child] msgsnd() returned = 0
		[parent] msgrcv() returned = 136
		[parent] 9/2 = 4
		[parent] Input an integer binary expressions(type "quit" to finish.): quit 		// this user typed "quit"
		[parent] msgsnd() returned = 0
		[child] received 3-th message "quit", ret = 136
		Terminating Parent.
		Terminating Child.


	You can use the following Linux commands to list or remove message queues
		ipcs				// show infromation on IPC facilities
		ipcrm -q <msgq-id>	// delete a message queue

	After the program terminates, there should be no remaining message queue.
	Example)
		$ ipcs
		------ Message Queues --------
		key        msqid      owner      perms      used-bytes   messages

		// nothing

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define	_DEBUG				// do not disable this macro

#define MAX_LEN 128

void Parent(int p2c, int c2p);
void Child(int p2c, int c2p);
int Evaluate(char *expression);

#define MSG_P2C 1
#define MSG_C2P 2

typedef struct {
	long type;				// the type of the message (in this program, MSG_P2C or MSG_C2P)
							// [IMPORTANT] type should not be zero
	int index;				// the index of the message. starting from 0, increase
	char content[MAX_LEN];	// the content of the message
} Message;

int main(int argc, char *argv[])
{
/*
	char msg[100], rst[20];
	fgets(msg, 100, stdin);
	sprintf(rst, "%d", Evaluate(msg));
	printf("received: %s = %s\n", msg, rst);


*/
	// TO DO: create two message queues:
	// 		one is for messages from the parent to the child.
	// 		the other is for messages from the child to the parent.
	// 		on failure, display an error message and quit.
	// 		otherwise, display the ids of the two message queues for debug.

	int p2c, c2p;
	if((p2c = msgget((key_t)1234, IPC_CREAT|0666)) == -1 || (c2p = msgget((key_t)5678, IPC_CREAT|0666)) == -1){
		printf("[main] error: failed to create msg queues\n");
		exit(1);
	}else{
		printf("p2c = %d, c2p = %d\n", p2c, c2p);				// the ids of the message queues
	}

	// TO DO: create a child process
	// 		on failure, display an error message, destroy the message queues, and terminate.
	// 		In the parent process, call the Parent() function passing the two message queues.
	//		In the child process, call the Child() function passing the two message queues.

	pid_t child_pid = fork();
	
	if(child_pid < 0){
		printf("[main] error: fork failed.\n");
		if(msgctl(p2c, IPC_RMID, NULL) == -1 || msgctl(c2p, IPC_RMID, NULL) == -1) printf("[main] error: failed to destroy the message queues.\n");//destroy the message queues
		exit(1);
	}else if(child_pid == 0){
		Child(p2c, c2p);
	}else{
		Parent(p2c, c2p);
	}

	return 0;
}


void Parent(int p2c, int c2p)
// TO DO: implement this function
// 		read integer expressions from the user
// 		send the expression to the child process by message passing
//		receive the result from the child by message passing
//		display the expression and result
{
	Message out_msg, in_msg;
	size_t msg_size = sizeof(Message) - sizeof(long);
	out_msg.type = MSG_P2C;	
	out_msg.index = 0;

	// Algorithm)
	//	repeat until the user types "quit"
	// 		read an integer expression as a string (e.g., "5+3", "7 * 5", etc.) - use fgets()
	// 		if the input is not an empty string,
	// 			send the expression to the child through the message queue p2c.
	// 				on failure, display an error message.
	//			for debug, display the return value of msgsnd().
	// 			if the input string is "quit", break the loop.
	// 			receive the result of the expression from the child through the message queue c2p.
	//				on failure, display an error message.
	//			for debug, display the return value of msgrcv().
	// 			display the expression and the result from the child.
	// 			increase the index of the outgoing message.
	//
	//	destroy the two message queues.
	//	display a message indicating that the parent is terminating.

	int rst;

	while(1){
		printf("[parent] Input an integer binary expressions(type \"quit\" to finish.):");
		fgets(out_msg.content, MAX_LEN, stdin); //get message from user
		out_msg.content[strlen(out_msg.content)-1] = 0;

		if(strlen(out_msg.content) > 0){
			//send the expressiono to chile through mesage queue p2c
			if((rst = msgsnd(p2c, &out_msg, msg_size, 0)) == -1) printf("[parent] error: cannot send the message to child.\n");
			printf("[parent] msgsnd() returned = %d\n", rst);
			
			if(!strcmp(out_msg.content, "quit")) break;

			//receive the result from child through message queue c2p
			if((rst = msgrcv(c2p, &in_msg, msg_size, 0, 0)) == -1) printf("[parent] error: cannot receive the message from child.\n");
			printf("[parent] msgrcv() returned = %d\n", rst);
			printf("[parent] %s = %s\n", out_msg.content, in_msg.content);
			out_msg.index++;
		}
	}

	if(msgctl(p2c, IPC_RMID, NULL) == -1 || msgctl(c2p, IPC_RMID, NULL) == -1) printf("[parent] error: failed to destroy the message queues.\n");
	

	printf("Terminating Parent.\n");

}

void Child(int p2c, int c2p)
// TO DO: implement this function
// 		receive an integer expressions from the parent by message passing
//		compute the result of the expression
// 		send the result to the parent process by message passing
{
	Message in_msg, out_msg;
	out_msg.type = MSG_C2P;
	out_msg.index = 0;
	size_t msg_size = sizeof(Message) - sizeof(long);

	// Algorithm)
	// 	repeat until the incomming message is "quit"
	// 		receieve an expression from the parent through the message queue p2c.
	// 			on failure, display an error message.
	// 		for debug, display the incoming message, its index, and the return value of msgrcv().
	// 		if the message is "quit", break the loop
	// 		compute the evaluation in the incoming message
	// 		for debug, display the outcoming message and its index.
	// 		send the result as a string to the parent through the message queue c2p.
	// 			on failure, display an error message.
	//		for debug, display the return value of msgsnd().
	// 		increase the index of outgoing message.
	//
	//	display a message indicating that the child is terminating.

	int rst;
	
	while(1){
		if((rst = msgrcv(p2c, &in_msg, msg_size, 0, 0)) == -1) printf("[child] error: cannot receive the message from parent.\n");
		printf("[child] received %d-th message \"%s\", ret = %d\n", in_msg.index, in_msg.content, rst);
		
		if(!strcmp(in_msg.content, "quit")) break;
		
		char tostr[20] = "";
		sprintf(tostr, "%d", Evaluate(in_msg.content));
		strcpy(out_msg.content, tostr);
		printf("[child] sending %d-th message \"%s\"\n", out_msg.index, out_msg.content);
		
		if((rst = msgsnd(c2p, &out_msg, msg_size, 0)) == -1) printf("[child] error: cannot send the message to the parent.\n");

		printf("[child] msgsnd() returned = %d\n", rst); 
		out_msg.index++;

	}

	printf("Terminating Child.\n");

}


int Evaluate(char *expression)
// TO DO: return the result of the expression
//		separate the operator and operands from the expression by calling the sscanf() function. (if necessary, search the Internet for sscanf().)
//			(the expression is composed of a left operand, an operator (+, - , *, or /), and a right operand., e.g., "5/2", "10 * 3", "7- 9")
//			for the division operator (/), return zero if the denominator is zero.
//		if the operator and the two operands were retrieved, compute the expression and return the result.
//		otherwise, return zero.
{
	int num1, num2;
	char op;

	int rst = sscanf(expression, "%d %c %d", &num1, &op, &num2);
	if(rst != 3) return 0;

	if(op == '+') return num1+num2;
	else if(op == '-') return num1-num2;
	else if(op == '*') return num1*num2;
	else if(op == '/'){
		if(!num2) return 0;
		else return num1/num2;
	}
	return 0;

}
