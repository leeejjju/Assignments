/*
	This program counts numbers using multiple child threads.
	The main() function randomly chooses the upper bound and delay of each thread.
	Then, it creates threads, each of whitch displays numbers on a column.
	The output should be similar to the following example.

	Example) ./a.out 3
		thread 0: upper = 10, delay = 3
		thread 1: upper = 6, delay = 1
		thread 2: upper = 7, delay = 2
		1
		   1
			  1
		   2
			  2
		   3
		2
		   4
			  3
		   5
		   6
		3
			  4
			  5
		4
			  6
		5
			  7
		6
		7
		8
		9
		10
		Bye!

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREAD 10

typedef struct {
	int thread_idx;
	int upper;
	int delay;
} ThreadParam;

void* thread_fn(void *arg);

void ExclusivePuts(char *str);

int main(int argc, char *argv[])
{
	pthread_t tid[MAX_THREAD];
	ThreadParam param[MAX_THREAD];

	if(argc < 2){
		printf("Usage: %s <# of threads>\n", argv[0]);
		return 0;
	}

	srand(time(NULL));

	int no_thread = atoi(argv[1]);
	if(no_thread > MAX_THREAD)
		no_thread = MAX_THREAD;

	int t = 0;

	// TO DO: prepare parameters for the thread function
	// 	for each t in [0, no_thread - 1]
	//		set param[t].thread_idx to t
	//		set param[t].upper to a random number between 5 and 10 (rand() % 6 + 5)
	//		set param[t].delay to a random number between 1 and 3 (rand() % 3 + 1)
	//		for debug, display the upper bound and delay of each thread
	for(int i = 0; i < no_thread; i++){
		param[i].thread_idx = i;
		param[i].upper = (rand() % 6 + 5);
		param[i].delay = (rand() % 3 + 1);
		printf("[main] upper = %d, delay = %d\n", param[i].upper, param[i].delay);
	}

	// TO DO: create threads using tid[t], thread_fn, and param[t]
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	for(int i = 0; i < no_thread; i++){
		pthread_create(&tid[i], &attr, thread_fn, &param[i]);
	}

	// TO DO: wait for all child threads to terminate
	for(int i = 0; i < no_thread; i++){
		pthread_join(tid[i], NULL);
	}







	printf("Bye!\n");

	return 0;
}

//	read the following code carefully, but DO NOT modify them
void* thread_fn(void *arg)
{
	ThreadParam *param = (ThreadParam*)arg;

	char buffer[256] = "";
	int pos = 3 * param->thread_idx;
	for(int j = 0; j < pos; j++)
		buffer[j] = ' ';
	buffer[pos] = 0;			// for safety

	for(int i = 1; i <= param->upper; i++){
		sprintf(buffer + pos, "%d", i);
		ExclusivePuts(buffer);
		sleep(param->delay);
	}

	return NULL;
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void ExclusivePuts(char *str)
{
	pthread_mutex_lock(&mutex);

	puts(str);

	pthread_mutex_unlock(&mutex);
}

