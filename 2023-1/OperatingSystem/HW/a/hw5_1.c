
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define	_DEBUG				// do not disable this macro

#define TRUE 1
#define FALSE 0

#define P2C 0				// parent to child
#define C2P 1				// child to parent

#define MAX_LEN 128

typedef struct {
	int is_loaded;			// is_loaded == TRUE indicates a data is loaded in buffer. otherwise, buffer is not ready
	char buffer[MAX_LEN];	// buffer to store the data
} SharedBuffer;

void* Parent(void *arg);
void* Child(void *arg);
int Evaluate(char *expression);

int main(int argc, char *argv[])
{
	//prevoius code
	/*
	SharedBuffer* shm_buffer = (SharedBuffer*)malloc(sizeof(SharedBuffer) * 2);

	int p2c = shmget(IPC_PRIVATE, sizeof(SharedBuffer)*2, S_IRUSR|S_IWUSR);
	char* t1 =	shm_buffer[P2C].buffer;
	t1 = (char*)shmat(p2c, NULL, 0);
	int c2p = shmget(IPC_PRIVATE, sizeof(SharedBuffer)*2, S_IRUSR|S_IWUSR);
	char* t2 = shm_buffer[C2P].buffer;
	t2 = (char*)shmat(c2p, NULL, 0);
	if(FALSE){
		printf("[main] error: cannot allocate shared memory bolck.\n");
		shmctl(p2c, IPC_RMID, NULL);//destroy shared memory bolck
		shmctl(c2p, IPC_RMID, NULL);//destroy shared memory bolck
		return(-1);
	}else printf("shmid = %d %d\n", p2c, c2p);


	// initialize shm_buffer[0] and shm_buffer[1] (set the is_loaded fields to FALSE and the buffer fields to an empty string.)
	shm_buffer[P2C].is_loaded = FALSE;
	shm_buffer[P2C].buffer[0] = 0;
	shm_buffer[C2P].is_loaded = FALSE;
	shm_buffer[C2P].buffer[0] = 0;

	pid_t cid = fork();
	if(cid == 0){
		Child(shm_buffer);
		shmdt(shm_buffer);//detatch
		exit(0);
	}else if(cid > 0){
		Parent(shm_buffer);
		shmdt(shm_buffer);//detatch
		shmctl(p2c, IPC_RMID, NULL);//destroy shared memory bolck
		shmctl(c2p, IPC_RMID, NULL);//destroy shared memory bolck
	}else{
		printf("[main] error: cannot create child process.\n");
		shmdt(shm_buffer);//detatch
		shmctl(p2c, IPC_RMID, NULL);//destroy shared memory bolck
		shmctl(c2p, IPC_RMID, NULL);//destroy shared memory bolck
	}


	system("ipcs");		// run 'icps' to check if the shared memory block was correctly deallocated
						// if your VM does not have icps, install it by running 'sudo apt install util-linux'
	printf("Bye!\n");

	return 0;
	*/

	//updated code
	SharedBuffer* shm_buffer = (SharedBuffer*)malloc(sizeof(SharedBuffer) * 2);
	
	//no need to call shmget and shmat twice time. use the instance is made before. 
	//세번째 파라미터로 권한 옵션을 추가해주면 좋을 것 같습니다. 
	int seg_id  = shmget(IPC_PRIVATE, sizeof(SharedBuffer)*2, IPC_CREAT|0666);
	shm_buffer = (SharedBuffer*)shmat(seg_id, NULL, 0);
	
	//seg_id의 리턴값을 통해 실패 여부를 확인할 수 있습니다. 
	if(seg_id < 0){
		printf("[main] error: cannot allocate shared memory bolck.\n");
		shmctl(seg_id, IPC_RMID, NULL);//destroy shared memory bolck
		return(-1);
	}else printf("shmid = %d\n", seg_id);

	// initialize shm_buffer[0] and shm_buffer[1] (set the is_loaded fields to FALSE and the buffer fields to an empty string.)
	shm_buffer[P2C].is_loaded = FALSE;
	shm_buffer[P2C].buffer[0] = 0;
	shm_buffer[C2P].is_loaded = FALSE;
	shm_buffer[C2P].buffer[0] = 0;

	pid_t cid = fork();
	if(cid == 0){ //child
		Child(shm_buffer);
		shmdt(shm_buffer);//detatch
		exit(0);
	}else if(cid > 0){ //parent
		Parent(shm_buffer);
		shmdt(shm_buffer);//detatch
		shmctl(seg_id, IPC_RMID, NULL);//destroy shared memory bolck
	}else{ //error
		printf("[main] error: cannot create child process.\n");
		shmdt(shm_buffer);//detatch
		shmctl(seg_id, IPC_RMID, NULL);//destroy shared memory bolck
	}

	system("ipcs");		// run 'icps' to check if the shared memory block was correctly deallocated
						// if your VM does not have icps, install it by running 'sudo apt install util-linux'
	printf("Bye!\n");
	return 0;
}

void* Parent(void *arg)
{
	SharedBuffer *shm_buffer = (SharedBuffer *)arg;


	//prevoius code
	/*
	char expression[MAX_LEN] = "";
	char result[MAX_LEN] = "";

	while(1){
		printf("[parent] Input an integer binary expressions(type \"quit\" to finish.):");
		fgets(expression, MAX_LEN, stdin); //get message from user
		expression[strlen(expression)-1] = 0;

		if(strlen(expression) > 0){
			while(shm_buffer[P2C].is_loaded);//wait
			sprintf(shm_buffer[P2C].buffer,"%s", expression);
			shm_buffer[P2C].is_loaded = TRUE;
			
			if(!strcmp(expression, "quit")) break;

			while(!shm_buffer[C2P].is_loaded); //wait
			strcpy(result, shm_buffer[C2P].buffer);
			shm_buffer[C2P].is_loaded = FALSE;

			printf("[parent] %s = %s\n",expression, result);
		}
	}

	printf("Terminating Parent.\n");
	*/

	//updated code
	char expression[MAX_LEN] = "";
	char result[MAX_LEN] = "";

	while(1){
		printf("[parent] Input an integer binary expressions(type \"quit\" to finish.):");
		fgets(expression, MAX_LEN, stdin); //get message from user
		expression[strlen(expression)-1] = 0;

		if(strlen(expression) > 0){
			while(shm_buffer[P2C].is_loaded);//wait
			sprintf(shm_buffer[P2C].buffer,"%s", expression);
			shm_buffer[P2C].is_loaded = TRUE;
			
			if(!strcmp(expression, "quit")) break;

			while(!shm_buffer[C2P].is_loaded); //wait
			strcpy(result, shm_buffer[C2P].buffer);
			shm_buffer[C2P].is_loaded = FALSE;

			printf("[parent] %s = %s\n",expression, result);
		}
	}
	sleep(0);
	printf("[parent] Terminating Parent.\n");
}

void* Child(void *arg)

{
	SharedBuffer *shm_buffer = (SharedBuffer *)arg;

	//previous code
	/*
	char expression[MAX_LEN] = "";
	char result[MAX_LEN] = "";

	while(1){
		
		//read
		while(!shm_buffer[P2C].is_loaded); //wait
		strcpy(expression, shm_buffer[P2C].buffer);
		shm_buffer[P2C].is_loaded = FALSE;
		printf("[child] received expression \"%s\"\n", expression);
		
		if(!strcmp(expression, "quit")) break;
		
		//write
		sprintf(result, "%d", Evaluate(expression));
		while(shm_buffer[C2P].is_loaded);//wait
		sprintf(shm_buffer[C2P].buffer,"%s", result);
		shm_buffer[C2P].is_loaded = TRUE;

		printf("[child] sending result \"%s\"\n", result);
		
	}
	printf("Terminating Child.\n");
	*/

	//updated code
	char expression[MAX_LEN] = "";
	char result[MAX_LEN] = "";

	while(1){
		
		//read
		while(!shm_buffer[P2C].is_loaded); //wait
		strcpy(expression, shm_buffer[P2C].buffer);
		shm_buffer[P2C].is_loaded = FALSE;
		printf("[child] received expression \"%s\"\n", expression);
		
		if(!strcmp(expression, "quit")) break;
		
		//write
		sprintf(result, "%d", Evaluate(expression));
		while(shm_buffer[C2P].is_loaded);//wait
		sprintf(shm_buffer[C2P].buffer,"%s", result);
		shm_buffer[C2P].is_loaded = TRUE;

		printf("[child] sending result \"%s\"\n", result);
		
	}
	sleep(0);
	printf("[child] Terminating Child.\n");
}

int Evaluate(char *expression)
{
	int op1 = 0, op2 = 0;
	char op = 0;
	int result = 0;

	int ret = sscanf(expression, "%d %c %d", &op1, &op, &op2);
	if(ret == 3){
		switch(op){
		case '+':
			result = op1 + op2;
			break;

		case '-':
			result = op1 - op2;
			break;

		case '*':
			result = op1 * op2;
			break;

		case '/':
			if(op2 != 0)
				result = op1 / op2;
			break;
		}
	}

	return result;
}

