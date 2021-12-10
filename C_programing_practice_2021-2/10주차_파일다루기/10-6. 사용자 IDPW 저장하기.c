#include <stdio.h>
#include <string.h>
/*10명의 사용자 정보(ID, PW)를 입력받아 출력하고 텍스트파일(user.txt)에 저장하는 프로그램을 작성하라.*/

/*
1. 사용자 정보 입력받아 배열에 저장
2. 입력받은 배열 파일에 작성 
3. 파일 읽기로 작성된 내용 출력 
*/

int main(void) {
	char userid[10][20];
	char userpw[10][20];
  char line[100] = {0,};
  char preLine[100] = "hehe";

  //1. 사용자 정보 입력받아 배열에 저장
  for(int i = 0; i < 10; i++){
    printf("%d번째 사람 ID Password? ", i+1);
    scanf("%s %s", userid[i], userpw[i]);
  }
  //2. 입력받은 배열 파일에 작성
  FILE* file;
  file = fopen("userData.txt", "w");

  fprintf(file, "등록된 사용자 목록\n");
  fprintf(file, "No ID Password\n");

  for(int i = 0; i < 10; i++){
    fprintf(file, "%d %s %s\n", i+1, userid[i], userpw[i]);
  }
  fclose(file);

  printf("\n");

  //3. 파일 읽기로 작성된 내용 출력 
  file = fopen("userData.txt", "r");
  int count = 0;

  while(!feof(file)){
    if(count > 11){
      break;
    }
    fgets(line, 100, file); //한줄을 받아오고(엔터까지..)
    printf("%s", line); //그 줄을 출력하고... 
    count ++;
  }

  fclose(file);

  printf("\nuser.txt에 저장함");


	return 0;
}
