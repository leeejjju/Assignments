#include <stdio.h>

int main(void) {
  int a, b, c;          // 2�� �Լ��� ��� a, b, c
  int x_begin, x_end;   // x��ǥ�� ���� ���� �� �� 
  int x, y;             // x��ǥ, y��ǥ 
  int i;

  printf("2�� �Լ��� ��� a�� b�� c�� �Է� ");
  scanf("%d %d %d", &a, &b, &c);
  printf("x��ǥ�� ���� ���� �� ���� �Է� ");
  scanf("%d %d", &x_begin, &x_end);

  for(i = x_begin; i <= x_end; i++ ){
    x = i;
    y = (a * i * i) + (b * i) + c;
    printf("��ǥ (%d,%d)\n", x, y);

  }




  return 0;
}
