#include <stdio.h>
#include <math.h>

int main(void) {
  float x1, x2;   // x��ǥ ��
  float y1, y2;   // y��ǥ �� 

  printf("ù��° ��ǥ�� x��? ");
  scanf("%f", &x1);
  printf("ù��° ��ǥ�� y��? ");
  scanf("%f", &y1);
  printf("�ι�° ��ǥ�� x��? ");
  scanf("%f", &x2);
  printf("�ι�° ��ǥ�� y��? ");
  scanf("%f", &y2);


  printf("�� ��ǥ ������ �Ÿ��� %.1f", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));


  return 0;
}
