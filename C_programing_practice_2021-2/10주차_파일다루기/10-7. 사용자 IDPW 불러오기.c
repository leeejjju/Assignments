#include <stdio.h>
#include <string.h>

int main(void) {
	char userid[10][20];
	char userpw[10][20]; 
  FILE* file;
  char line[100];
  int i = 0;

  file = fopen("user.txt", "r");

  printf("등록된 사용자 목록\n");
  printf("No ID   Password\n");


  while(!feof(file)){

    if(i > 9){
      break;
    }

    fgets(line, 100, file);

    if(i == 9){ //ㅋㅋㅋㅋ이게맞나..
      printf("%d %s\n", i+1, line);
    }else if(i == 8){
      line[strlen(line)-1] = '\0'; //맨끝에 엔터 지우고
      printf("%d  %s\n", i+1, line);
    }else{
      line[strlen(line)-1] = '\0'; //맨끝에 엔터 지우고
      line[strlen(line)-1] = '\0'; //그 앞에 공백 지우고
      printf("%d  %s\n", i+1, line); 
    }
    i++;
  }
  fclose(file);
 
	
	return 0;
}
