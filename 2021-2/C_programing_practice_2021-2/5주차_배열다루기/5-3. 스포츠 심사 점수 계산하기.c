#include <stdio.h>

int main(void) {

  float score[10];      // 심사점수
  float max = 0, mim = 100, maxNum, mimNum;       // 가장 큰 점수, 가장 작은 점수
  float total = 0;          // 점수 총 합계
  float average;        // 평균점수
  int i;                // 반복문을 위한 변수

  for(i = 0; i < 10; i++){ //점수 배열에 저장, 최대최소의 인덱스 번호 추출 
    printf("%d번 심사점수? ", i+1);
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

  for(i = 0; i < 10; i++){ //최대,최소점수 제외한 점수 총합 얻기 
    if(i != maxNum && i != mimNum){
      total += score[i];
    }
  }

  average = total/8.000;

  printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f입니다.", average);

  return 0;
}
