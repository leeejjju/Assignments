#include <stdio.h>

int main(void) {
  int kor, eng, math;   // ��������, ��������, �������� 
  int total;            // ����
  float average;        // ������� 

  printf("Kor? ");
  scanf("%d", &kor);
  printf("Eng? ");
  scanf("%d", &eng);
  printf("Math? ");
  scanf("%d", &math);

  total = kor + eng + math;
  average = total / 3.0;

  printf("total is %d, ", total);
  printf("average is %.1f.", average);



  return 0;
}
