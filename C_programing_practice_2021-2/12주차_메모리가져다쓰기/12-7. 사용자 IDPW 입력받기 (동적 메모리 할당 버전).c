#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*����ü�� ����ؼ� ����� ������ �Է¹޾� ����ϴ� ���α׷��� �ۼ��϶�.
��, main()������ ����ü �����͸� �����ϰ�, �Լ� getUser()���� �������� �޸� �Ҵ� ��, ������ �Է¹޾� ����� ����ü�� �����͸� �����ϵ��� �Ѵ�. �� ��, ����� ID�� ��й�ȣ�� ��� 4���� �̻��̾�� �Ѵ�. ����, ȭ�鿡 ����� ���� ��й�ȣ�� ó�� 2�ڸ� �ܿ��� * ǥ�÷� ����϶�.*/

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
      printf("-> 4���� �̻� �Է��� ��\n");
    }
  }

  while(1){
    printf("Password? ");
    scanf("%s", p->userpw);

    if(strlen(p->userpw) >3){
      break;
    }else{
      printf("-> 4���� �̻� �Է��� ��\n");
    }
  }


  return p;

}
//�Լ� getUser()���� �������� �޸� �Ҵ� ��, ������ �Է¹޾� ����� ����ü�� �����͸� �����ϵ��� �Ѵ�. �� ��, ����� ID�� ��й�ȣ�� ��� 4���� �̻��̾�� �Ѵ�. ����, ȭ�鿡 ����� ���� ��й�ȣ�� ó�� 2�ڸ� �ܿ��� * ǥ�÷� ����϶�.

