#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*����ü�� �̿��Ͽ� 3���� �����͸� �Է¹޾� �̸� �Ѳ����� ����϶�.
��, 3���� �����͸� �Է¹ޱ� ���� ������ ���� ����ü ������ 3��¥�� �迭�� ����϶�.
�� ���������� �Է¹޴� ���� �Լ��� �����Ͽ� ����϶�.*/


struct st_person{
 char name[20];
 char address[80];
 int age;
}; 

struct st_person* getPerson();

int main(void) {
  struct st_person* p[3];

  //������ �ڵ� ? main() �Ϻ�
  for(int i=0; i<3; i++){
    printf("#%d ���������� �Է��Ͻÿ�.\n",i+1);
    p[i] = getPerson();
  }

  for(int i=0; i<3; i++){
    printf("#%d : %s/ %s/ %d\n",i+1, p[i]->name, p[i]->address, p[i]->age);
  }

  return 0;
}

struct st_person* getPerson(){
  struct st_person* p = malloc(sizeof(struct st_person));

  printf("�̸���? ");
  scanf("%s", p->name);
  printf("�ּҴ�? ");
  getchar();
  fgets(p->address, 80, stdin); //���� ���� �Է¹޾ƾ��ϴ�..
  p->address[strlen(p->address)-1] = '\0'; //������ ���� �����ְ� 
  printf("���̴�? ");
  scanf("%d", &p->age);

  return p;
}
// �޸𸮸� ���� �Ҵ��Ͽ� ���������� �Է¹޾� ������ �� ������ ����
