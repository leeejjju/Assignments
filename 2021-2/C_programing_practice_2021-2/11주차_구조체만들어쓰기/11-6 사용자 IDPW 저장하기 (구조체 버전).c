#include <stdio.h>
/*����ü�� ����ؼ� 10���� ����� ������ �ؽ�Ʈ����(user.txt)�� �����ϴ� ���α׷��� �ۼ��϶�. ����� ������ ID, PW 2�����̴�.*/

struct st_user{
char userid[20];
char userpw[20];
};

int main(void) {
  struct st_user s[10]; //���������� ������ ����ü �迭

  FILE* file;
  file = fopen("user.txt", "w");

  for(int i = 0; i < 10; i++){
    printf("%d��° ��� ID Password? ", i+1);
    scanf("%s %s", s[i].userid, s[i].userpw);
    fprintf(file, "%s %s", s[i].userid, s[i].userpw);
  }

  printf("��ϵ� ����� ���\n");
  printf("No ID Password\n");
  for(int i = 0; i < 10; i++){
    printf("%-1d %s %s\n", i+1, s[i].userid, s[i].userpw );
  }
  printf("user.txt�� ������");


  fclose(file);

	return 0;
}
