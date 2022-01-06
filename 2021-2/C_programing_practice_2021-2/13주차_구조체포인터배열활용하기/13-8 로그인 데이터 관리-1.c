#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*10명의 로그인 데이터를 입력받아 구축하고, 이를 user.txt에 저장하라.*/

struct st_user{
    char userid[20];
    char userpw[20];
};

struct st_user* getUser(); 
void saveUser(struct  st_user* userlist[], int size, char* filename);

int main(void) {
    struct st_user* userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
    for(int i=0; i<10; i++){
        printf("#%d User\n", i+1);
        userlist[i] = getUser();
    }
    saveUser(userlist, 10, "user.txt");
    return 0;
}

struct st_user* getUser(){
  struct st_user* p = malloc(sizeof(struct st_user));

  while(1){
    printf("User ID? ");
    scanf("%s", p->userid);

    if(strlen(p->userid) >3){
      break;
    }else{
      printf("-> 4글자 이상 입력할 것\n");
    }
  }

  while(1){
    printf("Password? ");
    scanf("%s", p->userpw);

    if(strlen(p->userpw) >3){
      break;
    }else{
      printf("-> 4글자 이상 입력할 것\n");
    }
  }

  return p;

}

void saveUser(struct  st_user* userlist[], int size, char* filename){
  FILE* file;
  file = fopen(filename, "w");

  for(int i = 0; i < size; i++){
    fprintf(file, "%s %s\n", userlist[i]->userid, userlist[i]->userpw);
  }

  fclose(file);
  printf("%s에 저장하였습니다.\n", filename);

}
//파라미터 : 사용자 목록, 사용자 수, 저장할파일명
//사용자정보를 파일에 저장하는 함수
