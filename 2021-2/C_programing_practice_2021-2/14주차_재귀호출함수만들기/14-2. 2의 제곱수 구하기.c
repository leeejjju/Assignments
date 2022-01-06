#include <stdio.h>
/*반복해서 임의의 숫자 n을 입력받은 후 2의 n승을 계산하여 출력하되, 재귀함수로 구현하라.

이 때 사용할 재귀함수 powerOfTwo()의 정의는 다음과 같다.

powerOfTwo(n) = 1                       (n = 0인 경우)
                2 * powerOfTwo(n-1)     (n > 0인 경우)*/

int powerOfTwo(int n);

int main(void) {
  int num;

  while(1){
    printf("숫자 입력 (0 종료) : ");
    scanf("%d", &num);

    if(num == 0){
      break;
    }else{
      printf("2의 %d승은 %d\n", num, powerOfTwo(num));
    }
  }

  return 0;
}

int powerOfTwo(int n){
  if(n == 0){
    return 1;
  }else{
    return 2*powerOfTwo(n-1);
  }


  return 0;
}
