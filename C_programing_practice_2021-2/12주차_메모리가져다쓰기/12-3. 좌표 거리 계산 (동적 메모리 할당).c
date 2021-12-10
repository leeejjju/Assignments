#include <stdio.h>
#include<math.h>
#include <stdlib.h>
/*����ü�� �̿��Ͽ� 2���� ��ǥ �����͸� �Է¹޾� �̸� ����ϰ�, �� ��ǥ ������ �Ÿ��� ����϶�

��ǥ �Է��� ���� �Լ��� �����Ͽ� ����ϵ�, �ݵ�� �Լ� ������ ���� �޸� �Ҵ��� �����Ͽ��� �Ѵ�.

�� ��ǥ ������ �Ÿ� ����� ���� �Լ��� ����� ����ϵ�, ��� ����� ((x���� ������ ����)+(y���� ������ ����))�� �������̴�. ����� ���� sqrt()�� pow()�Լ��� ����϶�.*/

struct st_point{ 
 float x; // x��ǥ �� 
 float y; // y��ǥ �� 
}; 

struct st_point* getPoint();  // �޸� �Ҵ�޾� ��ǥ ����ü�� x,y ���� �Է¹޾� �� �ּҰ��� ������

float calcDistance(struct st_point* p1, struct st_point* p2); // �� ���� �Ÿ� ���ϴ� �Լ�

int main(void) {
  struct st_point* point1; 	// ù��° ��ǥ�� ���� ������
  struct st_point* point2; 	// �ι�° ��ǥ�� ���� ������ 

  printf("ù��° ��ǥ\n");
  point1 = getPoint();
  printf("�ι�° ��ǥ\n");
  point2 = getPoint();

  printf("\n�� ��ǥ ������ �Ÿ��� %.1f", calcDistance(point1, point2));


  return 0;
}

struct st_point* getPoint(){

  struct st_point* p;
  p = malloc(sizeof(struct st_point));

  printf("x��? ");
  scanf("%f", &p->x);
  printf("y��? ");
  scanf("%f", &p->y);

  return p;
}  
// �޸� �Ҵ�޾� ��ǥ ����ü�� x,y ���� �Է¹޾� �� �ּҰ��� ������

float calcDistance(struct st_point* p1, struct st_point* p2){
  float dis;
  dis = sqrt(pow((p1->x) - (p2->x),2)+pow((p1->y) - (p2->y),2));
  return dis;
}
// �� ���� �Ÿ� ���ϴ� �Լ�

