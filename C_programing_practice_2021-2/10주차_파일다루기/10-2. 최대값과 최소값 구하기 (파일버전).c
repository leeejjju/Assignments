#include <stdio.h>
/*������ ���Ϸκ��� ���ڸ� 10�� �Է¹��� ��, �� ���� �߿��� ���� ū ��, ���� ���� ���� ����϶�.

��, ������ ���� MaxMinOfTen() �Լ��� ����Ͽ� �ִ񰪰� �ּڰ��� �����ϵ��� �Լ��� ������.*/

void maxMinOfTen(int number[10], int* max, int* min);

int main(void) { 
  int num[10];    // 10���� ���ڸ� ���� �迭
  int max_num;    // ���� ū ���ڸ� ���� ���� ����,
  int min_num;    // ���� ���� ���ڸ� ���� ���� ����
  char file[20];  // ���� �̸�
  FILE* data;
  // �� ���� �ڵ带 �ۼ��϶�.

  printf("���� �̸��� �Է��ϼ���. ");
  scanf("%s", file); //���ϴ� ���ϸ� �ޱ� 

  data = fopen(file, "r"); //�ش� ���� ���� 
  for(int i = 0; i < 10; i++){ //���ϼ� ������� �迭�� �����ϱ� 
    fscanf(data, "%d", &num[i]);
  }

  maxMinOfTen(num, &max_num, &min_num); //�ִ��ּ� ã�� �����ϴ� �Լ� ���� 

  printf("���� ū ���� %d�̰�, ���� ���� ���� %d�Դϴ�.\n", max_num, min_num); 
  fclose(data);//���� �ݱ� 

  return 0; 
}

void maxMinOfTen(int number[10], int* max, int* min){
  *max = *min = number[0]; //�ʱ�ȭ 
  
  for(int i = 0; i < 10; i++){
    if( *max < number[i]){
      *max = number[i];
    }
    if( *min > number[i]){
      *min = number[i];
    }
  }
}

//�Ķ���� : �Է¹��� ���� �迭(number), �ִ��� ������(max), �ּڰ��� ������ (min)
//���ϰ� : ����
//���೻�� : ���� �迭���� ���� ū ���� ���� ���� ���� ã�Ƽ� max, min ������ ������ ������
