#include <stdio.h>

int main(void) {

  int height;     // �Է¹��� ����
  int blank;      // �Է¹��� ���� ũ��
  int i, j;       // �ݺ��� ����� ���� ���� 

  printf("height? ");
  scanf("%d", &height);
  printf("blank? ");
  scanf("%d", &blank);

  for(i = 1; i <= height; i++){
    for(j = 0; j <(height+blank)- i ; j++){
      printf(" ");
    }
    for(j=0;j< i; j++){
      printf("*");
    }
    printf("\n");
  }


  return 0;
}
