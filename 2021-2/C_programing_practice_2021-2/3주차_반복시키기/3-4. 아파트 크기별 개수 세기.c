#include <stdio.h>

int main(void) {
  float m2_area;        // 면적 (제곱미터)
  float pyung_area;     // 면적 (평수) 
  int count1 = 0;           // 소형 아파트 개수 
  int count2 = 0;           // 중소형 아파트 개수
  int count3 = 0;           // 중형 아파트 개수 
  int count4 = 0;           // 대형 아파트 개수 
  int i = 0;


  while(i<10){
    printf("아파트의 분양 면적(제곱미터)을 입력하시오. ");
    scanf("%f", &m2_area);

    pyung_area = m2_area / 3.305;

    printf("--> 이 아파트의 평형은 %.1f 입니다.\n", pyung_area);

    if(pyung_area >= 50){
      count4 ++;
    }else if(pyung_area >= 30){
      count3 ++;
    }else if(pyung_area >= 15){
      count2 ++;
    }else{
      count1 ++;
    }
    i++;
  }
  


  printf("\"소형 아파트\"의 개수는 %d 입니다.\n", count1);
  printf("\"중소형 아파트\"의 개수는 %d 입니다.\n", count2);
  printf("\"중형 아파트\"의 개수는 %d 입니다.\n", count3);
  printf("\"대형 아파트\"의 개수는 %d 입니다.\n", count4);

  return 0;
}
