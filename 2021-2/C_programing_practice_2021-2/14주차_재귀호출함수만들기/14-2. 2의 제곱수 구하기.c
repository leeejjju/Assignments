#include <stdio.h>
/*�ݺ��ؼ� ������ ���� n�� �Է¹��� �� 2�� n���� ����Ͽ� ����ϵ�, ����Լ��� �����϶�.

�� �� ����� ����Լ� powerOfTwo()�� ���Ǵ� ������ ����.

powerOfTwo(n) = 1                       (n = 0�� ���)
                2 * powerOfTwo(n-1)     (n > 0�� ���)*/

int powerOfTwo(int n);

int main(void) {
  int num;

  while(1){
    printf("���� �Է� (0 ����) : ");
    scanf("%d", &num);

    if(num == 0){
      break;
    }else{
      printf("2�� %d���� %d\n", num, powerOfTwo(num));
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
