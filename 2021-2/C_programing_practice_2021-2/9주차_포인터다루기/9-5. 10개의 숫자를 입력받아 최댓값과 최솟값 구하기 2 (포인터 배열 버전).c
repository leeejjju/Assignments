#include <stdio.h>
/*9-2�� ������ ������Ʈ�϶�. ���ڸ� 10�� �Է¹��� ��, �� ���� �߿��� ���� ū ��, ���� ���� ���� ����϶�. ��, ������ main() �Լ� �ڵ带 �������� �Լ� ���븸 �ۼ��϶�. �Ʒ��� maxMinOfTen() �Լ��� �����Ͽ� �ִ񰪰� �ּڰ��� ���������� �϶�.*/

void maxMinOfTen(int number[10], int* maxmin[]);

int main(void) {

  int num[10];      // 10���� ���ڸ� ���� �迭
  int* max_min[2];  // �ִ񰪰� �ּڰ��� ����ų ������ �迭 

  for(int i=0;i<10;i++){ //���� ���� �Է¹޾� �迭�� ���� 
    printf("%d��° ���ڸ� �Է��Ͻÿ�. ", i+1);
    scanf("%d", &num[i]); 
  }

  maxMinOfTen(num, max_min); //�ּ��ִ밪 ã�� �迭�� ���� 

  printf("���� ū ���� %d�̰�, ���� ���� ���� %d�Դϴ�.\n", *(max_min[0]), *(max_min[1])); 

  return 0;
}

void maxMinOfTen(int number[10], int* maxmin[]){
  int i; 
  //*maxmin[0] = 0;
  //*maxmin[1] = 9999;
  int max = 0, min = 99999;

  for(i = 0; i < 10; i++){ //�ִ밪 
    if(number[i] > max){
      max = number[i];
      maxmin[0] = &number[i]; //maxmin�� �����ͺ����� ������ max�� ��ü�� �ƴ� max���� ��ġ�� �ּҰ��� ��ƾ���. �׷��Ƿ� =max�� �ƴ� =&number[i]. 
    }
  }

  for(i = 0; i < 10; i++){ //�ּҰ� 
    if(number[i] < min){
      min = number[i];
      maxmin[1] = &number[i];
    }
  }
}
//�Ķ���� : �Է¹��� ���� �迭(number), �ִ񰪰� �ּڰ��� �����Ͱ� ����� �迭(mixmin)
//���೻�� : ���� �迭���� ���� ū ���� ���� ���� ���� ã�Ƽ� maxmin �����͹迭�� 0,1�� ������ ������ �ּҸ� ������. maxmin[0] -> �ִ��� ������, maxmin[1] -> �ּڰ��� ������

