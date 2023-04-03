#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TEXT 256
#define MAX_LEN 128
#define SIZE 512

typedef struct {
	int start, end;			// the start and end indices of the word
	char substr[MAX_LEN];	// substring (word)
} Substring;

Substring words[SIZE];	 	// array of structures to store words
int no_word = 0;			// the number of words

int issapce(char c);

int main()
{
	char *prompt = "input a text: ";
	int prompt_len = strlen(prompt);

	// read a text line
	char text[MAX_TEXT] = "";
	printf("%s", prompt);
	fgets(text, MAX_TEXT, stdin);
	int len = strlen(text) - 1;
	text[len] = 0;


	// previous code
	/*
		int flag = 1;
		char* subPointer;
		printf("              ");
		
		for(int i = 0; i <= len; i++){
			if(flag && !isspace(text[i])){
				words[no_word].start = i;
				printf("[");
				flag = 0;
			}else if((i == len || isspace(text[i])) && !flag){
				words[no_word].end = i-1;
				int lenOfSubstr = words[no_word].end - words[no_word].start;
				subPointer = (char*) malloc(sizeof(char)*lenOfSubstr); //allocate new string 
				for(int j = 0; j <= lenOfSubstr; j++){
					subPointer[j] = text[words[no_word].start+j];
				}
				strcpy(words[no_word].substr, subPointer);
				no_word++;
				printf("]");
				flag = 1; //put the next index as start
			}else printf(" ");
		}

		// DO NOT modify the following four lines
		putchar('\n');
		putchar('\n');
		for(int i = 0; i < no_word; i++)
			printf("words[%d] = (%d, %d, %s)\n", i, words[i].start, words[i].end, words[i].substr);
		printf("Bye!\n");

		//free the allocated spaces
		free(subPointer);
	*/

	// updated code
	int flag = 1;
	char* subPointer;
	printf("              ");
	
	for(int i = 0; i < len; i++){
		// 문장 끝에 공백이 들어가면 '['가 출력되는 것 같으니 다시 확인 부탁드려요!
		// -> cheked the range of for statement.
		if(flag && !isspace(text[i])){
			words[no_word].start = i;
			printf("[");
			flag = 0;
		}else if((i == len || isspace(text[i])) && !flag){
			// i-1이 아니라 i인 것 같습니다. 단어의 끝이 아니라 단어의 끝 다음에 오는 공백에 ']'가 있어야 됩니다.
			//-> check and modified!
			words[no_word].end = i;
			int lenOfSubstr = words[no_word].end - words[no_word].start-1;
			subPointer = (char*) malloc(sizeof(char)*lenOfSubstr); //allocate new string 
			for(int j = 0; j <= lenOfSubstr; j++){
				subPointer[j] = text[words[no_word].start+j];
			}
			strcpy(words[no_word].substr, subPointer);
			no_word++;
			printf("]");
			flag = 1; //put the next index as start
		}else printf(" ");
	}
	if(!flag) printf("]");

	// DO NOT modify the following four lines
	putchar('\n');
	putchar('\n');
	for(int i = 0; i < no_word; i++)
		printf("words[%d] = (%d, %d, %s)\n", i, words[i].start, words[i].end, words[i].substr);
	printf("Bye!\n");

	//free the allocated spaces
	free(subPointer);


	return 0;
}

int issapce(char c) {
	if (c == ' ') return 1;
	return 0;
}


