#include <stdio.h>

int main(void) {
  int kor, eng, math;   // 국어점수, 영어점수, 수학점수 
  int total;            // 총점
  float average;        // 평균점수 

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
