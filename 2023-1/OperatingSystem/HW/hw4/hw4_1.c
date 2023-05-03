//My previous solution was perfect, so I didn't modify it!


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>
#include <sys/stat.h>

#define _DEBUG			// do not disable this line

#define MAX_PATH 256

#define TRUE 1
#define FALSE 0

int CheckAndCreateDirectory(char *file_path);
int SplitCommandLine2(char *cmd, char *argv[]);

char working_dir[256] = "Working/";

int main()
{
	printf("Welcome to myshell.\n");
	printf("All commands will be executed in \"%s\".\n", working_dir);
	printf("Type \"quit\" to quit.\n");

	int ret = CheckAndCreateDirectory(working_dir);
	if(ret == FALSE){
		printf("Failed to find or create directory \"%s\".\n", working_dir);
		return -1;
	}

	// TO DO: move into the working directory (call chdir())
	//      on failure, display an error message
	if(chdir(working_dir) == -1){
		printf("Failed to move into the working directory \"%s\".\n", working_dir);
		return -1;
	}

	while(1){
		char cmd[256] = "";
		int argc = 0;
		char *argv[128];

		// read a command line
		printf("$ ");
		fgets(cmd, 256, stdin);
		cmd[strlen(cmd) - 1] = 0;

		// if the command is "quit", break the loop
		if(strcmp(cmd, "quit") == 0)
			break;

		argc = SplitCommandLine2(cmd, argv);

#ifdef	_DEBUG
		printf("argc = %d\n", argc);
		for(int i = 0; i < argc; i++)
			printf("argv[%d] = %s\n", i, argv[i]);
		printf("argv[%d] = %s\n", argc, argv[argc]);
#endif	//	_DEBUG

		// TO DO: if argc is greater than zero, run the command using fork() and execvp()
		// 		on failure of fork() or execvp(), display an error message
		//		for safety, call exit(-1) after execvp() in the child process
		//		the parent should wait for the child to terminate

		if(argc <= 0){
			printf("[error] no argv.\n");
			continue;
		}else {

			pid_t cid =  fork();
			if(cid < 0){
				printf("[error] failed to create child process.\n");
				continue;
			}else if(cid > 0){
				wait(NULL);
			}else{
				int ex = execvp(argv[0], argv);
				if(ex == -1) printf("Command %s not found\n", argv[0]);
				exit(-1);
			}
		}

	}

	printf("Bye!\n");			// this message MUST be displayed

	return 0;
}


int CheckAndCreateDirectory(char *file_path)
// TO DO: check if the desination directory exists. otherwise, create the destination directory.
// 		if the destination directory exists or successfully created, return TRUE
//		otherwise, return FALSE
//		reuse your solution to the presvious homework with slight modification
{
	static char subdir[MAX_PATH] = "";

    for(int i = 0; i < strlen(file_path); i++){
    
		if(file_path[i] == '/'){
        	strncpy(subdir, file_path, i);
            subdir[i] = '\0'; 
            int rst = mkdir(subdir, 0755);

            if(rst == -1 && errno == EEXIST){                 //if exist and writable, display a msg
                //printf("Found directory %s.\n", subdir);
            }else{
                if(!rst){
                    //mkdir
                    printf("Directory %s was created.\n", subdir);
                }else{
                    printf("Failed to create directory  %s.\n", subdir);
                    return FALSE; 
                }
            }
		}
	}

	return TRUE;

}

int SplitCommandLine2(char *cmd, char *argv[])
// TO DO: cut the command into arguments
//		return the number of arguments (argc)
//		set argv[argc] to NULL 
//		- if an argument starts with a quote ('\"' or '\''), extract all characters, including whitespaces, upto the closing quote.
//		- if an argument contains directories, discard directory names (e.g., "/home/user/test.c" --> "test.c")
//		- if an argument is "..", replace it with "."
{
	int argc = 0;
	int len = strlen(cmd);
	for(int i = 0; i < len; i++){
		//for quote 
		if(cmd[i] == '\"' || cmd[i] == '\''){
			argv[argc] = cmd + i + 1; //store this address as arg starting point
			while(1){ //increase i to the end of arg
				i++;
				if(cmd[i] == '\"' || cmd[i] == '\'') break;
				else if(cmd[i] == 0) break; 
				else if(cmd[i] == '/') argv[argc] = cmd + i + 1;//modify start point of this arg
			}
			argc++; 

			if(cmd[i] == 0) i--;
			else cmd[i] = 0; //split this arg as string
			
			if(!strcmp(argv[argc-1], "..")) strcpy(argv[argc-1], ".");

		}else if(!isspace(cmd[i])){
			argv[argc] = cmd + i;
			while(1){
				i++;
				if(cmd[i] == 0 || isspace(cmd[i])) break;
				else if(cmd[i] == '/') argv[argc] = cmd + i + 1;//modify start point of this arg
			}
			argc++; 
			if(cmd[i] == 0)	i--;
			else cmd[i] = 0; //split this arg as string

			if(!strcmp(argv[argc-1], "..")) strcpy(argv[argc-1], ".");
		}
	}
	argv[argc] = 0;
	return argc;
}

