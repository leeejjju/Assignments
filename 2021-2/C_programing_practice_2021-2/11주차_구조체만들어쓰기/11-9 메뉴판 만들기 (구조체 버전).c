#include <stdio.h>
/*� �Ĵ��� �޴����� ������ ������ ���� �����Ǿ� ���� ��, �� �޴����� �޴� ������ ����ü�� �����ϰ�, 5���� �޴� ������ �Է¹޾� �̸� 5���� ����ü �迭�� ������ ��,

�޴������� ȭ�鿡 ����ϰ�, �� ������ menu.txt �� �����϶�.*/
/*
1. �Է¹޾� ����ü�� ����, ���Ͽ� ���
2. ����ü ��� 
*/

struct menu{ 
  int no; // �޴���ȣ
  char name[20];  // �޴��� 
  int price; // ���� 
};

int main(void) {
  struct menu mymenu[5]; 

  FILE* file;
  file = fopen("menu.txt", "w");

  for(int i = 0; i < 5; i++){
    printf("%d��° �޴��� ��ȣ, �޴���, ������ �Է�. ", i+1);
    scanf("%d %s %d", &mymenu[i].no, mymenu[i].name, &mymenu[i].price);
    fprintf(file, "%d %s %d\n", mymenu[i].no, mymenu[i].name, mymenu[i].price);
  }

  fclose(file);

  printf("�޴���ȣ �޴��̸� 1�κа���\n");
  for(int i = 0; i < 5; i++){
    printf("%4d %12s %8d\n", mymenu[i].no, mymenu[i].name, mymenu[i].price);
  }

  //printf("�ȳ��ϼ��� ");

  return 0;
}
