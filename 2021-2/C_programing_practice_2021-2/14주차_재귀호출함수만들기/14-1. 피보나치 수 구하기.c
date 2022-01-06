#include <stdio.h>
/*n�� 1���� 20���� �����ϴ� ������ �Ǻ���ġ �� fibonacci(n)�� ����϶�.
�Ǻ���ġ ���� ������ ���� �����Ѵ�. ��, ����Լ��� �����϶�.
fibonacci(n) = 1
                                 (n = 1 �Ǵ� n = 2�� ���) 
               fibonacci(n-1) + fibonacci(n-2)   (n > 2�� ���)
fibonacci(n) = 1                                 (n = 1 �Ǵ� n = 2�� ���) 
               fibonacci(n-1) + fibonacci(n-2)   (n > 2�� ���)
 */

int fibonacci(int n);

int main(void) {
  
  printf("1���� 20���� �Ǻ���ġ ��\n");
  for(int i = 0; i<20; i++){
    printf("%d��°: %d\n", i+1, fibonacci(i+1));
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
