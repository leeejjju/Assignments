#include <stdio.h>
/*data.txt 파일로부터 심사점수(0.0~10.0) 10개를 입력받아 배열에 저장한 후, 10개의 심사 점수를 출력하고, 이 중 최대점수와 최소점수를 제외한 8개의 점수에 대한 평균을 계산하여 출력하라.

단, 이 배열을 파라미터로 하여 가장 큰 점수를 구하는 findMax() 와 가장 작은 점수를 구하는 findMin()을 제작하여 사용하라. */

float findMax(float num[], int size);
float findMin(float num[], int size);

int main(void) {
  int i, j;
  float sum = 0;
  float number[10];

  FILE* file;//핸들러 선언
  file = fopen("data.txt", "r");

  for(i = 0; i < 10; i++){
    fscanf(file, "%f", &number[i]);
    printf("%d번 심사점수 : %.1f\n", i+1, number[i]);
  }
  fclose(file);

  for(i = 0; i < 10; i++){
    if(number[i] != findMax(number, 10) && number[i] != findMin(number, 10)){
      sum += number[i];
    }
  }

  printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f 입니다. ", sum/8.0 );

  return 0;
}

float findMax(float num[], int size){
  float max;
  for(int i = 0; i < 10; i++){
    if(max < num[i]){
      max = num[i];
    }
  }
  return max;
}
//파라미터: num[] : 숫자배열, size : 배열의요소개수
//리턴값 : 숫자 배열에서 가장 큰 값

float findMin(float num[], int size){
  float min;
  for(int i = 0; i < 10; i++){
    if(min > num[i]){
      min = num[i];
    }
  }
  return min;
  
}
//파라미터: num[] : 숫자 배열, size : 배열의 요소 개수
//리턴값 : 숫자 배열에서 가장 작은 값
