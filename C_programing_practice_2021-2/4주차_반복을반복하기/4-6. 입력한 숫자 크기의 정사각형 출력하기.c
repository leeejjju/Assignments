#include <stdio.h>

int main(void) {
  int length;   // �Է¹��� ���簢�� �� ���� ���� 
  int i, j;     // �ݺ��� ����� ���� ���� 

  printf("���簢���� ũ�⸦ �Է��Ͻÿ�. ");
  scanf("%d", &length);

  for(i = 0;i < length; i++){
    for(j = 0; j< length; j++){
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
