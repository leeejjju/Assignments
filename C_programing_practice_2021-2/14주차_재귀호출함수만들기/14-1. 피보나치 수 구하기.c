#include <stdio.h>
/*n이 1부터 20까지 증가하는 각각의 피보나치 수 fibonacci(n)을 출력하라.
피보나치 수는 다음과 같이 정의한다. 단, 재귀함수로 구현하라.
fibonacci(n) = 1
                                 (n = 1 또는 n = 2인 경우) 
               fibonacci(n-1) + fibonacci(n-2)   (n > 2인 경우)
fibonacci(n) = 1                                 (n = 1 또는 n = 2인 경우) 
               fibonacci(n-1) + fibonacci(n-2)   (n > 2인 경우)
 */

int fibonacci(int n);

int main(void) {
  
  printf("1부터 20까지 피보나치 수\n");
  for(int i = 0; i<20; i++){
    printf("%d번째: %d\n", i+1, fibonacci(i+1));
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
