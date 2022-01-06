#include <stdio.h>
/*구조체를 사용해서 10명의 사용자 정보를 텍스트파일(user.txt)에 저장하는 프로그램을 작성하라. 사용자 정보는 ID, PW 2가지이다.*/

struct st_user{
char userid[20];
char userpw[20];
};

int main(void) {
  struct st_user s[10]; //유저정보를 저장할 구조체 배열

  FILE* file;
  file = fopen("user.txt", "w");

  for(int i = 0; i < 10; i++){
    printf("%d번째 사람 ID Password? ", i+1);
    scanf("%s %s", s[i].userid, s[i].userpw);
    fprintf(file, "%s %s", s[i].userid, s[i].userpw);
  }

  printf("등록된 사용자 목록\n");
  printf("No ID Password\n");
  for(int i = 0; i < 10; i++){
    printf("%-1d %s %s\n", i+1, s[i].userid, s[i].userpw );
  }
  printf("user.txt에 저장함");


  fclose(file);

	return 0;
}
