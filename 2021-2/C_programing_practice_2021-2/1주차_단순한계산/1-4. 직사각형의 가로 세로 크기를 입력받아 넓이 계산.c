#include <stdio.h>

int main(void) {

  int width, height;  // ����ũ��, ����ũ�� 
  int area;           // ���簢���� ���� 

  printf("width? ");
  scanf("%d", &width);
  printf("height? ");
  scanf("%d", &height);

  area = width * height;

  printf("area is %d.", area);


  return 0;
}
