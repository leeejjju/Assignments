#include <stdio.h>

int main(void) {
  int num1, num2;   // �Է¹��� �� ��
  int i;            // �ݺ����� ���� ����

  printf("2���� ���ڸ� �Է� ");
  scanf("%d %d", &num1, &num2);

  for(i=0; i<=100; i++){
    if(i % num1 == 0 || i % num2 == 0){ //���� �ϳ��� ����� �ֵ� 
      if(!(i % num1 == 0 && i % num2 == 0)){ //���߿��� ���� ������� �ƴѰ� ��� 
        printf("%d\n", i);
      }
    }
  }


  return 0;
}

