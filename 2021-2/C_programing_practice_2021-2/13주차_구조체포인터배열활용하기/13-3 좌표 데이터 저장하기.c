#include <stdio.h>
#include <stdlib.h>
/*13-2 ������ Ȱ���Ͽ� ��ǥ�� ������ ��� ��, �׸�ŭ�� ��ǥ ���� �Է¹޾� ��ǥ �����͸� point.txt ���Ͽ� �����϶�.
��ǥ �Է��� �Լ��� ����ϵ�, �ݵ�� �Լ� ������ ���� �޸� �Ҵ��� �����Ͽ��� �Ѵ�.

������ �ڵ� main() ���� �Ұ�
*/

struct st_point{ 
    float x; 		// x��ǥ �� 
    float y; 		// y��ǥ �� 
}; 

struct st_point* getPoint();
void savePoints(struct st_point* list[], char* filename, int size); 

int main()
{
    struct st_point* mypoint[50]; // �ִ� 50���� ��ǥ ����� 
    int size;
    printf("��ǥ�� ������? > ");
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        printf("%d��° ��ǥ\n", i+1);
        mypoint[i] = getPoint();
    }
    savePoints(mypoint, "point.txt", size);
    return 0;
}

void savePoints(struct st_point* list[], char* filename, int size){

  FILE* file;
  file = fopen(filename, "w");

  for(int i = 0; i < size; i++){
    fprintf(file, "%.1f %.1f\n", list[i]->x, list[i]->y);
  }

  fclose(file);

  printf("\n%d���� ��ǥ�� �����Ͽ����ϴ�.\n", size);
}
//�Ķ���� : ��ǥ ��� (����ü������ �迭), ������ �����̸�, ���ڵ� ����
//���ϰ� : ����

struct st_point* getPoint(){
  struct st_point* p;
  p = malloc(sizeof(struct st_point));

  printf("x, y��? ");
  scanf("%f %f", &p->x, &p->y);

  return p;
} 
// �޸� �Ҵ�޾� ��ǥ ����ü�� x,y ���� �Է¹޾� �� �ּҰ��� ������
