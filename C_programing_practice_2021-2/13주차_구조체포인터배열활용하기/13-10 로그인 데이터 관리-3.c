#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*13-9 ������ ������� user.txt�� �о ��� �α��ε����͸� ������ ��, ID�� Password�� �Է¹޾� �α����� ������ �� �˻��ϴ� ����� �����ϰ� �α����� ������ ������ ��� �Է¹޵��� �϶�.

��, �α��� ������ Ȯ���ϴ� �Լ��� ������ ���� �����Ͽ� ����϶�. �׸��� �� �Լ��� ȣ���Ͽ� ����ϴ� ������� getUser() �Լ��� �����϶�..*/

struct st_user{
    char userid[20];
    char userpw[20];
};
struct st_user* getUser(struct st_user* list[], int size);
int checkUser(struct st_user* list[], int size, struct st_user* temp);
int loadUser(struct  st_user* userlist[], char* filename);

int main(void) {
    struct st_user* userlist[10]; // 10���� �α��� ������ ������ ������ �迭

    int size = loadUser(userlist, "user.txt"); //�α��� ������ �о���� 
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

  printf("%d���� �α��� ������ �о����ϴ�.\n", size);
  return size;

}
//�Ķ���� : ������ ����� ��� ����, �о�� ���ϸ�
//���Ϸκ��� ����� ������ �о ���� �Ҵ��ϰ� �ű⿡ �����ϴ� �Լ� 


struct st_user* getUser(struct st_user* list[], int size){
  struct st_user* p = malloc(sizeof(struct st_user));

  while(1){
    printf("�α����Ϸ��� ID, PW�� �Է��Ͻÿ�. > ");
    scanf("%s %s", p->userid, p->userpw);

    if(checkUser(list, size, p) == 1){
      printf("�α��� ����! : ������� %s��\n", p->userid);
      break;
    }else if(checkUser(list, size, p) == 3){
      printf("�α��� ����! : �������� �ʴ� ID�Դϴ�.\n");
    }else if(checkUser(list, size, p) == 2){
      printf("�α��� ����! : ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
    }

  }

  return p;

}
//id pw �Է¹޾� checkUserȣ��, ����� ���� �������, ���Ǵ޼��ñ��� �ݺ� 

int checkUser(struct st_user* list[], int size, struct st_user* temp){

  int idok = 0, idIndex;

  for(int i = 0; i < size; i++){
    if(!strcmp(list[i]->userid, temp->userid)){
      idok = 1; 
      idIndex = i;
      break;
    }
  }

  if(idok == 0){ //��ġ�ϴ� id �������� 
    return 3;

  }else{ //�־����� ����˻� ���� 
    if(!strcmp(list[idIndex]->userpw, temp->userpw)){
      return 1; //�����ε��� pw�� ��ġ�ϸ� 
    }else{
      return 2; //����ġ�ϸ� 
    }
  }




}
//�Ķ���� : �α��� ��ü���, ��� ����, �˻��Ϸ��� �α��� ����(�Է¹��� �������� ������ ����ü�� ������)
//���ϰ� : �˻��� 1:���̵�� ��й�ȣ �Ѵ� ����, 2:���̵�� �´µ� ��й�ȣ Ʋ��, 3:��ġ�ϴ� ���̵� ����


