#include <stdio.h>

int main(void) {

  float score[10];      // �ɻ�����
  float max = 0, mim = 100, maxNum, mimNum;       // ���� ū ����, ���� ���� ����
  float total = 0;          // ���� �� �հ�
  float average;        // �������
  int i;                // �ݺ����� ���� ����

  for(i = 0; i < 10; i++){ //���� �迭�� ����, �ִ��ּ��� �ε��� ��ȣ ���� 
    printf("%d�� �ɻ�����? ", i+1);
    scanf("%f", &score[i]);

    if(score[i] > max){
      maxNum = i;
      max = score[i];
    }
    if(score[i] < mim){
      mimNum = i;
      mim = score[i];
    }
  }

  for(i = 0; i < 10; i++){ //�ִ�,�ּ����� ������ ���� ���� ��� 
    if(i != maxNum && i != mimNum){
      total += score[i];
    }
  }

  average = total/8.000;

  printf("���� ū ������ ���� ���� ������ ������ 8���� ������ ���� ����� %.1f�Դϴ�.", average);

  return 0;
}
