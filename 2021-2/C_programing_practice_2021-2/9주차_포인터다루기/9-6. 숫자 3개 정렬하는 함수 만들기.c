#include <stdio.h>
/*���� �Լ����� ���� 3��(num1, num2, num3)�� �Է¹��� ��, �� ���ڵ��� �ּҰ��� �Ѱ��ָ� ũ�Ⱑ ū ������ �� num1, num2, num3�� ����ǵ��� �����ϴ� �Լ��� �����Ͽ� �׽�Ʈ�϶�.

��, ������ main() �Լ� �ڵ带 �������� �Լ� ���븸 �ۼ��϶�.*/

void sort3Num(int* n1, int* n2, int* n3);

int main(void) {
  int num1, num2, num3;
  printf("���� 3�� �Է� ");
  scanf("%d %d %d", &num1, &num2, &num3); 
  sort3Num(&num1, &num2, &num3);
  printf("���� ��� %d %d %d\n", num1, num2, num3); return 0;
}

void sort3Num(int* n1, int* n2, int* n3){
  int ary[3] = {*n1, *n2, *n3};
  int i;
  int max = 0, min = 999, mid = *n2;
  int max_index, min_index;

  //max = (*n1 > *n2) ? ((*n1 > *n3) ? *n1 : *n3) : ((*n2 > *n3) ? *n2 : *n3);
  //min = (*n1 < *n2) ? ((*n1 < *n3) ? *n1 : *n3) : ((*n2 < *n3) ? *n2 : *n3);

  for(i = 0; i < 3; i ++){
    if(ary[i] > max){
      max = ary[i];
      max_index = i;
    }
  }
  for(i = 0; i < 3; i ++){
    if(ary[i] < min){
      min = ary[i];
      min_index = i;
    }
  }


  for(i = 0; i < 3; i ++){
    if(max_index != i && min_index != i){
      mid = ary[i];
    }
  }

  *n1 = max, *n2 = mid, *n3 = min;

}
//�Ķ���� : ���������� 3��
//���೻�� : ���������� 3���� ���� ���� �������� ���� ū ������ ���ĵǵ��� ������ ������

