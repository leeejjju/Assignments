#include <stdio.h>
/*11-6 �������� ������ ����� ���� ���ϰ� ���� user.txt�κ��� ��� ����� ������ �о� �鿩 ����϶�.

������ ������ ����ü�� ���� ��ƾ��Ѵ�.

������ ���� ����ü�� ����ؼ� ������ Ǯ����� �ȴ�.*/

struct st_user{
char userid[20];
char userpw[20];
};

int main(void) {
  struct st_user s[10]; //���������� ������ ����ü �迭

  FILE* file;
  file = fopen("user.txt", "r");

  //�о�� ����ü�� ���� 

  for(int i = 0; i < 10; i++){ 
    fscanf(file, "%s %s", s[i].userid, s[i].userpw);
  }

  fclose(file);

  printf("��ϵ� ����� ���\n");
  printf("No ID   Password\n");
  for(int i = 0; i < 10; i++){
    printf("%-2d %-4s %s\n", i+1, s[i].userid, s[i].userpw );
  }

	return 0;
}
