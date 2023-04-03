/*
	

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 2

#define MAX_PATH 256			// maximum length of pathnames
#define BUFFER_SIZE 512			// the size of buffer to copy files

int CheckAndCreateDirectory(char *file_path);
int CopyFile(char *src_path, char *dest_path);

int main(int argc, char *argv[])
{
	// display the command line arguments
	printf("%d arguments:\n", argc);
	for(int i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);


	// if argc < 3, display the usage and terminate.
	if(argc < 3){
		printf("Usage: %s <src_path> <dest_path>\n", argv[0]);
		return 0;
	}

	char *src_path = argv[1];
	char *dest_path = argv[2];

	// test if the source file exists and is readible.
	if(access(src_path, R_OK) != 0){
		printf("Error! File %s does not exist or is not readible!\n", src_path);
		exit(-1);
	}

	// check whether the destination directory exists. otherwise, create the directory
	printf("Preparing directory...\n");
	int success = CheckAndCreateDirectory(dest_path);
	printf("result = %d\n", success);

	// copy file
	printf("Copying file %s to %s\n", src_path, dest_path);;
	if(success)
		success = CopyFile(src_path, dest_path);

	// on success, run 'ls -al <dest_path>' by calling the system() function
	// otherwise, display an error message.
	if(success){
		printf("%s was successfully copied to %s\n", src_path, dest_path);

		char cmd[MAX_PATH] = "";
		sprintf(cmd ,"ls -al %s", dest_path);
		system(cmd);
	} else {
		printf("Failed to copy %s to %s!\n", src_path, dest_path);
	}

	return 0;
}

int CheckAndCreateDirectory(char *file_path)
// TO DO: check if the desination directory exists. otherwise, create the destination directory.
// 		if the destination directory exists or successfully created, return TRUE
//		otherwise, return FALSE
{
	
	//  Algorithm)
	// 	repeat for i from 0 to the length of file_path
	//		if file_path[i] is a delimitor ('/'),
	//			make a subdirectory path as a string with the characters from file_path[0] to file_path[i].
	//		 		(don't foreget to add '\0' at the end of the string)
	//			if the subdirectory exists and is writable,
	//				display a message indicating the subdirectory exists.
	//			otherwise,
	//				create the subdirectory.		// use mkdir() with mode 0766
	//				on success,
	//					display a message indicating the subdirectory is created
	//				otherwise,
	//					display an error message and return FALSE
	//
	//  return TRUE

	
	static char subdir[MAX_PATH] = "";
	
	for(int i = 0; i < strlen(file_path); i++){
		if(file_path[i] == '/'){
			strncpy(subdir, file_path, i);
			subdir[i] = '\0';

			int rst = mkdir(subdir, 0644);

			if(rst == -1 && errno == EEXIST){
				//if exist and writable, display a msg
				printf("Found directory %s.\n", subdir);
			}else{
				//else, create subdurectory (mkdir())
				if(!rst){
					//mkdir
					printf("Directory %s was created.\n", subdir);
				}else{
					printf("Failed to create directory  %s.\n", subdir);
					return 0; //FLASE? or 0? 
				}
			}
		}
	}
	return TRUE;
}

int CopyFile(char *src_path, char *dest_path)
// TO DO: copy src_path to dest_path
//		assume the destination directory exists
{
	int src = open(src_path, O_RDONLY, 0);
	printf("src = %d\n", src);	

	// TO DO: on failure, display an error message and return FALSE
	if(src == -1){
		printf("failed to opne the  file %s\n", src_path);
		return FALSE;
	}

	int dest = open(dest_path, O_WRONLY | O_CREAT, 0644);
	printf("dest = %d\n", dest);

	// TO DO: on failure, display an error message and return FALSE
	if(dest == -1){
		printf("failed to opne the  file %s\n", src_path);
		return FALSE;
	}

	static char buffer[BUFFER_SIZE];
	ssize_t read_size = 0, written_size = 0;

	// TO DO:
	// repeat until there is no more byte to read
	//		read maximum BUFFER_SIZE bytes from the source file into the buffer, storing the number of bytes actually read in a variable.
	//		write the buffer into the destination file

	int rsize, wsize;
	while(1){
		rsize = read(src, buffer, BUFFER_SIZE);
		if(!rsize) break;
		wsize = write(dest, buffer, rsize);
		printf("read_size = %d, weitten_size = %d\n", rsize, wsize);
	}

	// TO DO: close the source and destination files
	close(src);
	close(dest);



	return TRUE;
}

