#include <stdio.h>
/*Ackermann's Function A �� ������ ���� ���ǵȴ�.

�̸� �����Ͽ� ackermann( i, j ) �� ��� ȣ�� �Լ��� �����, �� �Լ��� �̿��Ͽ� ackermann(0,0) ���� ackermann(3,3)���� 16�� ���� ���϶�.

Ackermann's Function A(i,j):

A(0, j) = j+1                  (i = 0 �̰�, j �� 0 �� ���)
A(i, 0) = A(i-1, 1)            (i > 0 �̰� j = 0 �� ���)
A(i, j) = A(i-1, A(i, j-1))    (i�� j ��� 0���� ū ���)*/

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
