#include <stdio.h>
#include <stdlib.h>
/*13-3 �������� ������ point.txt ���Ϸκ��� ���� ���� ��ǥ�� �о�ͼ� ��ġ�� �м��϶�.

��ġ �˻� ���
1��и��� x��, y���� ��� ���, 2��и��� x���� ����, y���� ���, 3��и��� x��, y���� ��� �� ��, 4��и��� x���� ���, y���� ������ ����̴�.

������ �ڵ� main() ���� �Ұ�*/

struct st_point{ 
    float x; 	// x��ǥ �� 
    float y; 	// y��ǥ �� 
}; 
int loadPoints(struct st_point* list[], char* filename); 
int getPosition(struct st_point* p);

int main()
{
    struct st_point* mypoint[50]; // �ִ� 50���� ��ǥ ����� 
    int size; // ��ǥ �� ����
    int count[5]={0}; // ��ǥ��ġ�� ���� (0:�� ��ǥ ����, 1~4:1~4�и� ��ǥ ����)
    size = loadPoints(mypoint, "point.txt");
    for(int i=0;i<size;i++){
        int pos = getPosition(mypoint[i]);
        count[pos]++;
    }
    printf("���� ��ǥ�� ��� %d��\n", count[0]);
    for(int i=1;i<=4;i++)
        printf("%d��и��� ��ǥ�� ��� %d��\n", i, count[i]);
    return 0;
}

int loadPoints(struct st_point* list[], char* filename){
  int count = 0;

  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    list[count] = malloc(sizeof(struct st_point));
    int r = fscanf(file, "%f %f", &list[count]->x, &list[count]->y);
    if(r < 2){
      break;
    }else{
      count ++;
    }
  }

  printf("%s���� %d���� ��ǥ������ �о����ϴ�.\n", filename, count);

  return count;
}
//�Ķ���� : �����ؾ� �ϴ� ��ǥ ���(����ü ������ �迭), �о���� �����̸�
//���ϰ� : �о���� ��ǥ�� ���� 
//���೻�� : ���Ϸκ��� ��ǥ�����͸� �о���̵� ���� �޸� �Ҵ��� ���־�� �ϸ�, �о���� ��ǥ�� ������ ������


int getPosition(struct st_point* p){

  if(p->x == 0 || p->y == 0){ //�� �Ÿ��� 
    return 0;
  }else if(p->x > 0){
    if(p->y > 0){
      return 1;
    }else{
      return 4;
    }
  }else{
    if(p->y > 0){
      return 2;
    }else{
      return 3;
    }
  }
}
// ���ϰ� : ��ǥ�� ��и� ��ġ (0:��, 1:1��и�, 2:2��и�, 3:3��и�, 4:4��и�)
// ���೻�� : ���޹��� ��ǥ�� ��ġ�� �ľ��Ͽ� ��ġ��ȣ(0~4)�� ������

