/*1101�ڵ�T_03)_22100579
3. ���� ���� ���� ���·� array�� �����Ͽ� ���α׷��� �ۼ��Ͻÿ�. 
n���� �������� Ȯ���Ͽ��� ��Ȯ�� ���� ��µǵ��� �ۼ��� ��. 
�־��� array���� �ι�°�� ū ���� �����ΰ�?*/

#include <stdio.h>
#define N 10

int main(void){
  int a[N] = {3, 7, 2, 6, 9, 4, 8, 1, 3, 3}; //�־��� �迭 
  int i; //�ݺ�����
  int max = 0, max_index, sed_max = 0;

  for(i = 0; i < N; i++){ //�ִ밪 ã�Ƴ��� 
    if(max < a[i]){
      max = a[i];
      max_index = i;
    }
  }

  for(i = 0; i < N; i++){ //���밪 ã�Ƴ��� 
    if(i != max_index && (sed_max < a[i])){
      sed_max = a[i];
    }
  }

  printf("�ι�°�� ū ���� %d", sed_max);

  return 0;
}

