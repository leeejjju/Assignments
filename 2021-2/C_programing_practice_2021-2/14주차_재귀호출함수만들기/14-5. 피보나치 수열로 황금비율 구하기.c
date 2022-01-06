#include <stdio.h>
#include <math.h>
/*문제 14-1 에서 제작한 피보나치 함수 fibonacci(n)를 사용하여 황금비율을 찾아내라.

n번째 황금비율이란 피보나치 수열의 연속적인 2개의 숫자의 비율(n+1번째수 / n번째 수)로 정한다.

단, 계산한 비율이 직전의 비율에 비해 그 차이가 백만분의 1보다 작게 되면 멈추도록 하라.*/


int fibonacci(int n); 

int main(void) {
  int i = 1;
  float pregolden, golden;
  
  while(1){

    golden = (float)fibonacci(i+1)/fibonacci(i);

    printf("%d번째 비율 (%d / %d) : %.6f\n", i, fibonacci(i+1), fibonacci(i), golden);

    if(sqrt(pow(golden-pregolden, 2)) < 0.000001){
      break;
    }
    pregolden = golden;

    i++;
  }

  return 0;
}

int fibonacci(int n){
  if(n == 1 || n == 2){
    return 1;
  }else{
    return fibonacci(n-1)+fibonacci(n-2);
  }
}
