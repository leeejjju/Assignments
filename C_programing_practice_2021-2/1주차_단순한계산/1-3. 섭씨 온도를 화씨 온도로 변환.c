#include <stdio.h>

int main(void) {
  float c_degree; // ���� �µ� 
  float f_degree; // ȭ�� �µ� 

  printf("���� �µ��� �Է��Ͻÿ�. ");
  scanf("%f", &c_degree);
  f_degree = c_degree * 1.8 + 32;
  printf("ȭ�� �µ��� %.1f�� �Դϴ�.", f_degree);

 
  return 0;
}
