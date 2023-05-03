#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// #define _DEBUG

void CatFile(const char *filename);

int main()
{
	CatFile("mycat.c");

	return 0;
}

#define BUFFER_SIZE 512
char buffer[BUFFER_SIZE];

void CatFile(const char *filename)
{
#ifdef	_DEBUG
	printf("pass (line = %d)\n", __LINE__);
#endif	//	_DEBUG

	// open
	int fd = open(filename, O_RDONLY, 0);
	if(fd <= 0){
		printf("Failed to open file %s\n", filename);
		return;
	}

#ifdef	_DEBUG
	printf("pass (line = %d)\n", __LINE__);
#endif	//	_DEBUG

	// repeat
	// 		read a block from the file
	// 		display all characters in the block
	ssize_t size = 0;
	while(1){
		size = read(fd, buffer, BUFFER_SIZE);
		if(size <= 0)
			break;

		for(int i = 0; i < size; i++)
			putchar(buffer[i]);
	}

#ifdef	_DEBUG
	printf("pass (line = %d)\n", __LINE__);
#endif	//	_DEBUG

	// close
	close(fd);

#ifdef	_DEBUG
	printf("pass (line = %d)\n", __LINE__);
#endif	//	_DEBUG
}
