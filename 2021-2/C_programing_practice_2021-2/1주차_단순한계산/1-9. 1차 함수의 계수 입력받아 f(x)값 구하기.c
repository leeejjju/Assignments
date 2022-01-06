#include <stdio.h>

int main(void) {
  int a, b; // 1차 함수의 계수 a, b
  int x;    // x값

  printf("1차 함수의 계수 a와 b를 입력 ");
  scanf("%d %d", &a, &b);
  printf("x값을 입력 ");
  scanf("%d", &x);

  printf("f(x)의 값은 %d입니다.", a * x + b);


  return 0;
}
