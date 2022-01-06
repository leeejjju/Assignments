#include <stdio.h>
/*n의 a승 계산할 수 있는 <math.h>내의 pow() 함수와 같은 일을 하는 power() 함수를 재귀함수로 구현하라.

그리고 숫자 2개(num1, num2)를 입력받아 num1의 num2승을 계산하라.*/

int power( int n, int a ); 

int main(void) {\
  int n, a;

  printf("숫자 2개를 입력 ");
  scanf("%d %d", &n, &a);
  printf("%d의 %d승은 %d", n, a, power(n, a));
  

  return 0;
}

int power( int n, int a ){
  if(a == 0){
    return 1;
  }else if(a == 1){
    return n;
  }else if(a>1 && a%2 == 0){
    return power(n, a/2) * power(n, a/2);
  }else{
    return power(n, a/2) * power(n, a/2) * n;
  }

}
