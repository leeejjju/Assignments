#include <stdio.h>
#include <math.h>
/*���� 14-1 ���� ������ �Ǻ���ġ �Լ� fibonacci(n)�� ����Ͽ� Ȳ�ݺ����� ã�Ƴ���.

n��° Ȳ�ݺ����̶� �Ǻ���ġ ������ �������� 2���� ������ ����(n+1��°�� / n��° ��)�� ���Ѵ�.

��, ����� ������ ������ ������ ���� �� ���̰� �鸸���� 1���� �۰� �Ǹ� ���ߵ��� �϶�.*/


int fibonacci(int n); 

int main(void) {
  int i = 1;
  float pregolden, golden;
  
  while(1){

    golden = (float)fibonacci(i+1)/fibonacci(i);

    printf("%d��° ���� (%d / %d) : %.6f\n", i, fibonacci(i+1), fibonacci(i), golden);

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
