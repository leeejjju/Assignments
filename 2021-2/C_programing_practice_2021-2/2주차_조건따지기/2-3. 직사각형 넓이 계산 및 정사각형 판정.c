#include <stdio.h>

int main(void) {
  int width, height;  // ����ũ��, ����ũ�� 
  int area;           // �簢���� ����

  printf("width? ");
  scanf("%d", &width);
  printf("height? ");
  scanf("%d", &height);

  area = width * height;

  if( width == height){
    printf("���̴� %d�̰� ���簢���Դϴ�.", area);
  }else{
    printf("���̴� %d�̰� ���簢���� �ƴմϴ�.", area);
  }
return 0;
}
