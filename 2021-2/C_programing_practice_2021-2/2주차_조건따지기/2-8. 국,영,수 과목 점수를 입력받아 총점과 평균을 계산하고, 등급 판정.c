#include <stdio.h>

int main(void) {
  int kor, eng, math;   // ��������, ��������, ��������
  int total;            // ����
  float average;        // �������

  printf("���� ������ �Է��ϼ��� ");
  scanf("%d", &kor);

  printf("���� ������ �Է��ϼ��� ");
  scanf("%d", &eng);

  printf("���� ������ �Է��ϼ��� ");
  scanf("%d", &math);

  total = eng + math + kor;
  average = total / 3.0;

  printf("�Է��Ͻ� ������ ������ %d �̰�,\n", total);
  printf("����� %.1f �Դϴ�.", average);

  if(kor >= 90){
    printf("\n���������� ����մϴ�.");
  }
  if(eng >= 90){
    printf("\n���������� ����մϴ�.");
  }
  if(math >= 90){
    printf("\n���������� ����մϴ�.");
  }


  return 0;
}
