#include <stdio.h>

int main(void) {
  int height, weight;     // 신장(cm), 체중(kg) 
  float bmi;              // 비만도 수치
  int people; 
  int i;            // 비만인 사람의 수 

  for(i = 0; i < 5; i++){
    printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ", i+1);
    scanf("%d %d", &height, &weight);

    bmi = weight / (height * height * 0.0001);
    if(bmi >= 25){
      people ++;
    }
  }

  printf("비만인 사람은 총 %d명입니다.", people);
  
  return 0;
}
