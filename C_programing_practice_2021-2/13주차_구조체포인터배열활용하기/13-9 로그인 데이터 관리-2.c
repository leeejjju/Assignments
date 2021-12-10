#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*13-8 �������� ������ ���� ����� �߰��϶�.

����� ID�� �Է¹��� ���� �̹� ��ϵ� ����� ��Ͽ� ������ ID�� ������ �ٽ� �Է¹޵��� �Ѵ�.
�� ����� ������ ���� ������ getUser() �Լ��� �����ϰ�, �� �Լ������� ID �ߺ��� �˻��ϵ��� �϶�.*/

struct st_user{
    char userid[20];
    char userpw[20];
};

struct st_user* getUser(struct st_user* list[], int size);
void saveUser(struct  st_user* userlist[], int size, char* filename);

int main(void) {
    struct st_user* userlist[10]; // 10���� �α��� ������ ������ ������ �迭
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

      //���� �Էµ� ID�� �ߺ��˻�..!!!
      for(int i = 0; i < size; i++){
        if(!strcmp(list[i]->userid, p->userid)){ //���� ��ġ�� 
          printf("�ߺ��Ǵ� ID�Դϴ�. �ٽ� �Է��ϼ���.\n");
          joong = 1;
          break;
        }
      }

      if(joong == 0){
        break;
      }
      
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
// �Ķ���� : ������� ��ϵ� �α��ε����� ���, ����� ����
// ���೻�� : �α��� ���� �Է��� ������ ����������, �Ķ���ͷ� ���޵� �α��θ���� Ȱ���ؼ� ID�� �ߺ��Ǵ��� �˻��� ��.

void saveUser(struct  st_user* userlist[], int size, char* filename){
  FILE* file;
  file = fopen(filename, "w");

  for(int i = 0; i < size; i++){
    fprintf(file, "%s %s\n", userlist[i]->userid, userlist[i]->userpw);
  }

  fclose(file);
  printf("%s�� �����Ͽ����ϴ�.\n", filename);

}
//�Ķ���� : ����� ���, ����� ��, ���������ϸ�
//����������� ���Ͽ� �����ϴ� �Լ�
