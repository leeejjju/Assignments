#include <stdio.h>

int main(void) {

  int height;     // �Է¹��� ����
  int i, j;       // �ݺ��� ����� ���� ���� 

  printf("height? ");
  scanf("%d", &height);

  for(i = 0; i < height; i++){
    for(j = 0; j <height - (i + 1) ; j++){
      printf(" ");
    }
    for(j=0;j< i*2 + 1; j++){
      printf("*");
    }  
    printf("\n");
  }


  return 0;
}
