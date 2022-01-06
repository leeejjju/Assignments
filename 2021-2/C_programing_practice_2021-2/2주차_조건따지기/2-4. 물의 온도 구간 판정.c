#include <stdio.h>

int main(void) {
  float input_degree; // 입력받은 온도 

  printf("degree? ");
  scanf("%f", &input_degree);

  if(input_degree >= 80){
    printf("끓는 물입니다.");
  }else if(input_degree >= 40){
    printf("온수 입니다.");
  }else if(input_degree >= 25){
    printf("미온수 입니다.");
  }else if(input_degree >= 0){
    printf("냉수 입니다. ");
  }else{
    printf("잘못입력하셨습니다.");
  }
  return 0;
}
