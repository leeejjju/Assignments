#include <stdio.h>
/*Ackermann's Function A 는 다음과 같이 정의된다.

이를 참고하여 ackermann( i, j ) 를 재귀 호출 함수로 만들고, 이 함수를 이용하여 ackermann(0,0) 에서 ackermann(3,3)까지 16개 값을 구하라.

Ackermann's Function A(i,j):

A(0, j) = j+1                  (i = 0 이고, j ≥ 0 인 경우)
A(i, 0) = A(i-1, 1)            (i > 0 이고 j = 0 인 경우)
A(i, j) = A(i-1, A(i, j-1))    (i와 j 모두 0보다 큰 경우)*/

int ackermann(int i, int j); 

int main(void) {
  
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      printf("Ackermann(%d, %d) = %d\n", i, j, ackermann(i, j));
    }
  }
  return 0;
}


int ackermann(int i, int j){
  if(i == 0 && j >= 0){
    return j+1;
  }else if(i > 0 && j == 0){
    return ackermann(i-1, 1);
  }else{
    return ackermann(i-1, ackermann(i, j-1));
  }

  return 0;
}
