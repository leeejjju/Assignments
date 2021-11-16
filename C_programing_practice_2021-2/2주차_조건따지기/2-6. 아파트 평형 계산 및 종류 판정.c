#include <stdio.h>

int main(void) {

  float m2_area;      // 면적 (제곱미터) 
  float pyung_area;   // 면적 (평수) 

  

  printf("아파트의 분양 면적(제곱미터)을 입력하시오. ");
  scanf("%f", &m2_area);
 
  pyung_area = m2_area / 3.305;

  printf("아파트의 평형은 %.1f 입니다.\n", pyung_area);
  
  if(pyung_area >= 50){
    printf("대형 아파트 입니다.");
  }else if(pyung_area >= 30){
    printf("중형 아파트 입니다.");
  }else if(pyung_area >= 15){
    printf("중소형 아파트 입니다.");
  }else{
    printf("소형 아파트 입니다.");
  }
  return 0;
}
