#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*����ü�� �̿��Ͽ� 3���� �����͸� �Է¹޾� �̸� �Ѳ����� ����϶�.
��, 3���� �����͸� �Է¹ޱ� ���� ����ü ���� 3���� ���Ƿ� �����Ͽ� ����϶�.*/

struct st_person{
  char name[20];
  char address[80];
  int age;
}; 

int main(void) {
  struct st_person p[3]; //���������� �޾� ������ ����ü �迭
  char num[3][10] = {"ù", "��", "��"};

  for(int i = 0; i < 3; i++){
    printf("%s ��° ��� ���������� �Է��Ͻÿ�.", num[i]);
    printf("\n�̸���? ");
    scanf("%s", p[i].name);
    printf("�ּҴ�? ");
    getchar(); //�տ��� ģ ���Ͱ� �ڿ� �Էµ��� �ʵ��� �޾��� 
    //scanf("%s", p[i].address);
    fgets(p[i].address, 80, stdin);
    p[i].address[strlen(p[i].address)-1] = '\0'; //���� �Էµ� ������ ���� ���� 
    printf("���̴�? ");
    scanf("%d", &p[i].age); 
  }

  for(int i = 0; i < 3; i++){
    printf("%s ��° ��� : %s/ %s/ %d\n", num[i], p[i].name, p[i].address, p[i].age);

  }

  return 0;
}

