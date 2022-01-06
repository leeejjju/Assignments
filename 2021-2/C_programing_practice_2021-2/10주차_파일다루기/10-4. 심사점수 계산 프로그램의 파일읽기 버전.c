#include <stdio.h>
/*data.txt ���Ϸκ��� �ɻ�����(0.0~10.0) 10���� �Է¹޾� �迭�� ������ ��, 10���� �ɻ� ������ ����ϰ�, �� �� �ִ������� �ּ������� ������ 8���� ������ ���� ����� ����Ͽ� ����϶�.

��, �� �迭�� �Ķ���ͷ� �Ͽ� ���� ū ������ ���ϴ� findMax() �� ���� ���� ������ ���ϴ� findMin()�� �����Ͽ� ����϶�. */

float findMax(float num[], int size);
float findMin(float num[], int size);

int main(void) {
  int i, j;
  float sum = 0;
  float number[10];

  FILE* file;//�ڵ鷯 ����
  file = fopen("data.txt", "r");

  for(i = 0; i < 10; i++){
    fscanf(file, "%f", &number[i]);
    printf("%d�� �ɻ����� : %.1f\n", i+1, number[i]);
  }
  fclose(file);

  for(i = 0; i < 10; i++){
    if(number[i] != findMax(number, 10) && number[i] != findMin(number, 10)){
      sum += number[i];
    }
  }

  printf("���� ū ������ ���� ���� ������ ������ 8���� ������ ���� ����� %.1f �Դϴ�. ", sum/8.0 );

  return 0;
}

float findMax(float num[], int size){
  float max;
  for(int i = 0; i < 10; i++){
    if(max < num[i]){
      max = num[i];
    }
  }
  return max;
}
//�Ķ����: num[] : ���ڹ迭, size : �迭�ǿ�Ұ���
//���ϰ� : ���� �迭���� ���� ū ��

float findMin(float num[], int size){
  float min;
  for(int i = 0; i < 10; i++){
    if(min > num[i]){
      min = num[i];
    }
  }
  return min;
  
}
//�Ķ����: num[] : ���� �迭, size : �迭�� ��� ����
//���ϰ� : ���� �迭���� ���� ���� ��
