#include <stdio.h>

int main(void) {

  int height;     // 입력받은 높이
  int blank;      // 입력받은 여백 크기
  int i, j;       // 반복문 사용을 위한 변수 

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
