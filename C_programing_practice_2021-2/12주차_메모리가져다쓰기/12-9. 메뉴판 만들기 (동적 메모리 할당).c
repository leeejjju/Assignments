#include <stdio.h>
#include <stdlib.h>

/*� �Ĵ��� �޴����� ������ ������ ���� �����Ǿ� ���� ��, 1���� �޴� ������ ����ü �����ͷ� �����ϰ�, �Լ��� ���� ������ �Է¹޾� ����϶�.*/

struct st_menu{ 
 int no; 				// �޴���ȣ
 char name[20]; 			// �޴��� 
 char madein[20]; 			// ������ 
 int price; 				// ���� 
};

struct st_menu* getMenu();


int main(void) {
  struct st_menu *menu; 	// �޴� ����ü ������

  menu = getMenu();

  printf("�޴���ȣ �޴��̸� ������ 1�κа���\n");
  printf("   %d    %s %s   %d", menu->no, menu->name, menu->madein, menu->price);

  return 0;
}

struct st_menu* getMenu(){
  struct st_menu* p = malloc(sizeof(struct st_menu));

  printf("�޴���ȣ, �޴���, ������, ������ �Է��϶�. > ");
  scanf("%d %s %s %d", &p->no, p->name, p->madein, &p->price);

  return p;
}
// ���೻�� : �޴����� ����ü�� ���� �޸� �Ҵ� ��, �̰��� �޴� ������ �Է¹޾� ������ ��, �ּҰ� ������
