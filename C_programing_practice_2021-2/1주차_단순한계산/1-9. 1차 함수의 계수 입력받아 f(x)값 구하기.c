#include <stdio.h>

int main(void) {
  int a, b; // 1�� �Լ��� ��� a, b
  int x;    // x��

  printf("1�� �Լ��� ��� a�� b�� �Է� ");
  scanf("%d %d", &a, &b);
  printf("x���� �Է� ");
  scanf("%d", &x);

  printf("f(x)�� ���� %d�Դϴ�.", a * x + b);


  return 0;
}
