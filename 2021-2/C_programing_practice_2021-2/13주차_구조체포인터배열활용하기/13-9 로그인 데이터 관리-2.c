#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*13-8 문제에서 다음과 같은 기능을 추가하라.

사용자 ID를 입력받을 때에 이미 등록된 사용자 목록에 동일한 ID가 있으면 다시 입력받도록 한다.
이 기능은 다음과 같이 기존의 getUser() 함수를 수정하고, 이 함수내에서 ID 중복을 검사하도록 하라.*/

struct st_user{
    char userid[20];
    char userpw[20];
};

struct st_user* getUser(struct st_user* list[], int size);
void saveUser(struct  st_user* userlist[], int size, char* filename);

int main(void) {
    struct st_user* userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
    for(int i=0; i<10; i++){
        printf("#%d User\n", i+1);
        userlist[i] = getUser(userlist, i);
    }
    saveUser(userlist, 10, "user.txt");
    return 0;
}

struct st_user* getUser(struct st_user* list[], int size){

  struct st_user* p = malloc(sizeof(struct st_user));
  int joong = 0;

  while(1){
    printf("User ID? ");
    scanf("%s", p->userid);
    if(strlen(p->userid) >3){
      joong = 0;

      //역대 입력된 ID와 중복검사..!!!
      for(int i = 0; i < size; i++){
        if(!strcmp(list[i]->userid, p->userid)){ //만약 겹치면 
          printf("중복되는 ID입니다. 다시 입력하세요.\n");
          joong = 1;
          break;
        }
      }

      if(joong == 0){
        break;
      }
      
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
// 파라미터 : 현재까지 등록된 로그인데이터 목록, 목록의 개수
// 수행내용 : 로그인 정보 입력은 기존과 동일하지만, 파라미터로 전달된 로그인목록을 활용해서 ID가 중복되는지 검사할 것.

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
