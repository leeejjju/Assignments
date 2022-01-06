#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*구조체를 사용해서 사용자 정보를 입력받아 출력하는 프로그램을 작성하라.
단, main()에서는 구조체 포인터를 선언하고, 함수 getUser()에서 동적으로 메모리 할당 후, 정보를 입력받아 저장된 구조체의 포인터를 리턴하도록 한다. 이 때, 사용자 ID와 비밀번호는 모두 4글자 이상이어야 한다. 또한, 화면에 출력할 때에 비밀번호의 처음 2자리 외에는 * 표시로 출력하라.*/

struct st_user{
 char userid[20];
 char userpw[20];
};

struct st_user* getUser();

int main(void) {
	struct st_user* p;
  p = getUser();

  printf("\nUser ID: %s\n", p->userid);
  printf("Password: ");
  for(int i = 0; i < strlen(p->userpw); i++){
    if(i <2){
      printf("%c", p->userpw[i]);
    }else{
      printf("*");
    }
  }


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
//함수 getUser()에서 동적으로 메모리 할당 후, 정보를 입력받아 저장된 구조체의 포인터를 리턴하도록 한다. 이 때, 사용자 ID와 비밀번호는 모두 4글자 이상이어야 한다. 또한, 화면에 출력할 때에 비밀번호의 처음 2자리 외에는 * 표시로 출력하라.

