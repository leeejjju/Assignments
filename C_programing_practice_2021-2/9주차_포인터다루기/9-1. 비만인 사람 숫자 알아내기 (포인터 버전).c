#include <stdio.h>
/*5명의 신장(cm단위)과 체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라.

단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라. 신장과 체중의 입력은 askHW() 함수를 통해 진행 하라.*/

void askHW(float* h, float* w);

int main(void) {

  float height, weight, bmi; 
  int count=0;

  for(int i=0;i<5;i++){
    askHW(&height, &weight);
    bmi = weight / (height*height); 
    if (bmi > 25){
      count++;
    }
  }
  printf("비만인 사람은 %d명입니다.\n", count); 
  return 0;
}

void askHW(float* h, float* w){ // 키(cm)과 몸무게(kg)을 화면에서 입력받아 h포인터에 미터(float)로 환산한 키, w포인터에 몸무게 (float)값 을 저장
  static int count = 0; //몇번째 입력인지 
  float cmh;
  printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ", count+1);
  scanf("%f %f", &cmh, w);
  *h = cmh * 0.01;

  count ++;
  return;
}
