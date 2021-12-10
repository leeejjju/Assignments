#include <stdio.h>
#include <stdlib.h>
/*� �Ĵ��� �޴����� ������ ���� �����Ǿ� ���� ��, 5���� �޴� ������ �Է¹޾� menu.txt ���Ϸ� �����϶�.

������ �ҽ� main() ��������*/


struct st_menu{ 
    int no; 				// �޴���ȣ
    char name[20]; 			// �޴��� 
    char madein[20]; 		// ������ 
    int price; 				// ���� 
};

struct st_menu* getMenu();
void saveMenu(struct st_menu* list[], char* filename, int size);

int main()
{
    struct st_menu* menu[10]; 	// �ִ� 10���� �޴� ����� ������ �迭 
    for(int i=0;i<5;i++){
        printf("%d��° �޴�\n",i+1);
        menu[i] = getMenu();
    }
    saveMenu(menu,"menu.txt",5);
    return 0;
}

struct st_menu* getMenu(){
  struct st_menu* p;
  p = malloc(sizeof(struct st_menu));

  printf("�޴��� ��ȣ, �޴���, ������, ������ �Է��϶�. > ");
  scanf("%d %s %s %d", &p->no, p->name, p->madein, &p->price);

  return p;
}
// ���೻�� : �޴����� ����ü�� ���� �޸� �Ҵ� ��, �̰��� �޴� ������ �Է¹޾� ������ ��, �ּҰ� ������

void saveMenu(struct st_menu* list[], char* filename, int size){
  FILE* file;
  file = fopen(filename, "w");

  for(int i = 0; i < size; i++){
    fprintf(file, "%d %s %s %d\n", list[i]->no, list[i]->name, list[i]->madein, list[i]->price);
  }

  fclose(file);
  printf("menu.txt�� �����߽��ϴ�.\n");
}
// �Ķ���� : �޴� ���, ������ ���ϸ�, �޴� ����
// ���ϰ� : ���� 
