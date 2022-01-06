#include <stdio.h>
/*11-6 문제에서 생성된 사용자 정보 파일과 같은 user.txt로부터 모든 사용자 정보를 읽어 들여 출력하라.

파일의 내용을 구조체에 먼저 담아야한다.

다음과 같은 구조체를 사용해서 문제를 풀어나가면 된다.*/

struct st_user{
char userid[20];
char userpw[20];
};

int main(void) {
  struct st_user s[10]; //유저정보를 저장할 구조체 배열

  FILE* file;
  file = fopen("user.txt", "r");

  //읽어내서 구조체에 저장 

  for(int i = 0; i < 10; i++){ 
    fscanf(file, "%s %s", s[i].userid, s[i].userpw);
  }

  fclose(file);

  printf("등록된 사용자 목록\n");
  printf("No ID   Password\n");
  for(int i = 0; i < 10; i++){
    printf("%-2d %-4s %s\n", i+1, s[i].userid, s[i].userpw );
  }

	return 0;
}
