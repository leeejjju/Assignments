#include <stdio.h>
/*���ڸ� 10�� �Է¹��� ��, �� ���� �߿��� ���� ū ��, ���� ���� ���� ����϶�.

��, ������ main() �Լ� �ڵ带 �������� �Լ� ���븸 �ۼ��϶�. �Ʒ��� MaxMinOfTen() �Լ��� �����Ͽ� �ִ� �� �ּڰ��� ���������� �϶�.*/

void maxMinOfTen(int number[10], int* max, int* min);

int main(void) { 
  int num[10];      // 10���� ���ڸ� ���� �迭
  int max_num;      // ���� ū ���ڸ� ���� ���� ����, 
  int min_num;      // ���� ���� ���ڸ� ���� ���� ����

  for(int i=0;i<10;i++){ //������ ���ڸ� �Է¹޾� �迭�� ���� 
    printf("%d��° ���ڸ� �Է��Ͻÿ�. ", i+1);
    scanf("%d", &num[i]); 
  }

  maxMinOfTen(num, &max_num, &min_num);

  printf("���� ū ���� %d�̰�, ���� ���� ���� %d�Դϴ�.\n", max_num, min_num); 

  return 0;
}

void maxMinOfTen(int number[10], int* max, int* min){ //���� �迭���� ���� ū ���� ���� ���� ���� ã�Ƽ� max, min ������ ������ ������

  int i; 

  for(i = 0; i < 10; i++){
    if(number[i] > *max){
      *max = number[i];
    }
  }
  for(i = 0; i < 10; i++){
    if(number[i] < *min){
      *min = number[i];
    }
  }

}




