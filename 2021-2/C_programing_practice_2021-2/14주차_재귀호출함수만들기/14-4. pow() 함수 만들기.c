#include <stdio.h>
/*n�� a�� ����� �� �ִ� <math.h>���� pow() �Լ��� ���� ���� �ϴ� power() �Լ��� ����Լ��� �����϶�.

�׸��� ���� 2��(num1, num2)�� �Է¹޾� num1�� num2���� ����϶�.*/

int power( int n, int a ); 

int main(void) {\
  int n, a;

  printf("���� 2���� �Է� ");
  scanf("%d %d", &n, &a);
  printf("%d�� %d���� %d", n, a, power(n, a));
  

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
