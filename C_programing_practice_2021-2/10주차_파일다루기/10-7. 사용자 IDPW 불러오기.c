#include <stdio.h>
#include <string.h>

int main(void) {
	char userid[10][20];
	char userpw[10][20]; 
  FILE* file;
  char line[100];
  int i = 0;

  file = fopen("user.txt", "r");

  printf("��ϵ� ����� ���\n");
  printf("No ID   Password\n");


  while(!feof(file)){

    if(i > 9){
      break;
    }

    fgets(line, 100, file);

    if(i == 9){ //���������̰Ը³�..
      printf("%d %s\n", i+1, line);
    }else if(i == 8){
      line[strlen(line)-1] = '\0'; //�ǳ��� ���� �����
      printf("%d  %s\n", i+1, line);
    }else{
      line[strlen(line)-1] = '\0'; //�ǳ��� ���� �����
      line[strlen(line)-1] = '\0'; //�� �տ� ���� �����
      printf("%d  %s\n", i+1, line); 
    }
    i++;
  }
  fclose(file);
 
	
	return 0;
}
