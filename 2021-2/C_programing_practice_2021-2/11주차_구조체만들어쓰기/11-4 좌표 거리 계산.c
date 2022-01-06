#include <stdio.h>
#include <math.h>
/*���� ����ü�� �̿��Ͽ� 2���� ��ǥ �����͸� �Է¹޾� �̸� ����ϰ�, �� ��ǥ ������ �Ÿ��� ����϶�. 
��, �� ��ǥ ������ �Ÿ� ����� ������ �Լ��� ����� ����ϵ�,
��� ����� (x���� ����)^2+(y���� ����)^2�� �������̴�.
����� ���� sqrt()�� pow()�Լ��� ����϶�.*/

struct point{ 
  float x; // x��ǥ �� 
  float y; // y��ǥ �� 
}; 

float calcDistance(struct point* p1, struct point* p2);

int main(void) {
  struct point p1, p2;

  printf("ù ��° ��ǥ�� x��? ");
  scanf("%f", &p1.x);
  printf("ù ��° ��ǥ�� y��? ");
  scanf("%f", &p1.y);
  printf("�� ��° ��ǥ�� x��? ");
  scanf("%f", &p2.x);
  printf("�� ��° ��ǥ�� y��? ");
  scanf("%f", &p2.y);

  printf("\n�� ��ǥ ������ �Ÿ��� %.1f", calcDistance(&p1, &p2));

  return 0;
}

float calcDistance(struct point* p1, struct point* p2){
  float dis;

  dis = sqrt(pow((p1->x) - (p2->x),2)+pow((p1->y) - (p2->y),2));

  return dis;
}
 // �� ���� �Ÿ� ���ϴ� �Լ�
