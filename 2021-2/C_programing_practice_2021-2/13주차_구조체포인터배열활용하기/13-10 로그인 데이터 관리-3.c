#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*13-9 문제를 기반으로 user.txt를 읽어서 모든 로그인데이터를 구축한 후, ID와 Password를 입력받아 로그인이 가능한 지 검사하는 기능을 구현하고 로그인이 성공할 때까지 계속 입력받도록 하라.

단, 로그인 정보를 확인하는 함수는 다음과 같이 제작하여 사용하라. 그리고 이 함수를 호출하여 사용하는 방식으로 getUser() 함수를 변경하라..*/

struct st_user{
    char userid[20];
    char userpw[20];
};
struct st_user* getUser(struct st_user* list[], int size);
int checkUser(struct st_user* list[], int size, struct st_user* temp);
int loadUser(struct  st_user* userlist[], char* filename);

int main(void) {
    struct st_user* userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열

    int size = loadUser(userlist, "user.txt"); //로그인 데이터 읽어오기 
    getUser(userlist, size);
    
    return 0;
}

//-----------------------------------------------------

int loadUser(struct  st_user* userlist[], char* filename){
  int size = 0;
  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    userlist[size] = malloc(sizeof(struct st_user));
    int r = fscanf(file, "%s %s", userlist[size]->userid, userlist[size]->userpw);
    if(r < 2){
      break;
    }else{
      size++;
    }
  }
  fclose(file);

  printf("%d명의 로그인 정보를 읽었습니다.\n", size);
  return size;

}
//파라미터 : 저장할 사용자 목록 공간, 읽어올 파일명
//파일로부터 사용자 정보를 읽어서 공간 할당하고 거기에 저장하는 함수 


struct st_user* getUser(struct st_user* list[], int size){
  struct st_user* p = malloc(sizeof(struct st_user));

  while(1){
    printf("로그인하려는 ID, PW를 입력하시오. > ");
    scanf("%s %s", p->userid, p->userpw);

    if(checkUser(list, size, p) == 1){
      printf("로그인 성공! : 어서오세요 %s님\n", p->userid);
      break;
    }else if(checkUser(list, size, p) == 3){
      printf("로그인 실패! : 존재하지 않는 ID입니다.\n");
    }else if(checkUser(list, size, p) == 2){
      printf("로그인 실패! : 비밀번호가 틀렸습니다.\n");
    }

  }

  return p;

}
//id pw 입력받아 checkUser호출, 결과에 따라 문구출력, 조건달성시까지 반복 

int checkUser(struct st_user* list[], int size, struct st_user* temp){

  int idok = 0, idIndex;

  for(int i = 0; i < size; i++){
    if(!strcmp(list[i]->userid, temp->userid)){
      idok = 1; 
      idIndex = i;
      break;
    }
  }

  if(idok == 0){ //일치하는 id 없었으면 
    return 3;

  }else{ //있었으면 비번검사 시작 
    if(!strcmp(list[idIndex]->userpw, temp->userpw)){
      return 1; //동일인덱스 pw와 일치하면 
    }else{
      return 2; //불일치하면 
    }
  }




}
//파라미터 : 로그인 전체목록, 목록 개수, 검사하려는 로그인 정보(입력받은 내용으로 구축한 구조체의 포인터)
//리턴값 : 검사결과 1:아이디와 비밀번호 둘다 맞음, 2:아이디는 맞는데 비밀번호 틀림, 3:일치하는 아이디 없음


