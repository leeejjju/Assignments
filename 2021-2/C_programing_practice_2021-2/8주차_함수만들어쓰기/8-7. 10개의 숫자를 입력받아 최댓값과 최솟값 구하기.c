#include <stdio.h>
/*���ڸ� 10�� �Է¹��� ��, �� ���� �߿��� ���� ū ��, ���� ���� ���� ����϶�.

�Լ��� ����Ͽ� �ִ��� ��ȯ�ϴ� �Լ��� �ּڰ��� ��ȯ�ϴ� �Լ��� ���� ������.

�Լ� ������ ������ ����.

int maxOfTen(int number[10]);
�Ķ���� : �Է¹��� ���� �迭(number)
���ϰ� : ���� ū ��
���೻�� : ���� �迭���� ���� ū ���� ã�Ƽ� ���ο��� ����

int minOfTen(int number[10]);
�Ķ���� : �Է¹��� ���� �迭(number)
���ϰ� : ���� ���� ��
���೻�� : ���� �迭���� ���� ���� ���� ã�Ƽ� ���ο��� ����*/

int maxOfTen(int number[10]){
  int i;
  int max_num;
  for(i = 0; i < 10; i++){
    if(number[i] > max_num){
      max_num = number[i];
    }
  }
  return max_num;
}

int minOfTen(int number[10]){
  int i;
  int min_num;
  for(i = 0; i < 10; i++){
    if(number[i] < min_num){
      min_num = number[i];
    }
  }
  return min_num;
}



int main(void) {
  int number[10]={0};
  //int max=-10000,min=100000;

  for(int i=0;i<10;i++){
    printf("%d��° ���ڸ� �Է��Ͻÿ�. ",i+1);
    scanf("%d",&number[i]);
  }
  /*
  for(int i=0;i<10;i++){
    if(number[i]>max) max=number[i];
    if(min>number[i]) min = number[i];
  }
  */
  printf("���� ū ���� %d�̰�, ���� ���� ���� %d�Դϴ�.",maxOfTen(number) ,minOfTen(number));


  return 0;
}



