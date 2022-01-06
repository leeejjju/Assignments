#include <stdio.h>
/*숫자를 10개 입력받은 후, 이 숫자 중에서 가장 큰 수, 가장 작은 수를 출력하라.

단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라. 아래의 MaxMinOfTen() 함수를 제작하여 최댓값 과 최솟값을 가져오도록 하라.*/

void maxMinOfTen(int number[10], int* max, int* min);

int main(void) { 
  int num[10];      // 10개의 숫자를 받을 배열
  int max_num;      // 가장 큰 숫자를 리턴 받을 변수, 
  int min_num;      // 가장 작은 숫자를 리턴 받을 변수

  for(int i=0;i<10;i++){ //열개의 숫자를 입력받아 배열에 저장 
    printf("%d번째 숫자를 입력하시오. ", i+1);
    scanf("%d", &num[i]); 
  }

  maxMinOfTen(num, &max_num, &min_num);

  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num); 

  return 0;
}

void maxMinOfTen(int number[10], int* max, int* min){ //받은 배열에서 가장 큰 수와 가장 작은 수를 찾아서 max, min 포인터 변수에 저장함

  int i; 

  for(i = 0; i < 10; i++){
    if(number[i] > *max){
      *max = number[i];
    }
  }
  for(i = 0; i < 10; i++){
    if(number[i] < *min){
      *min = number[i];
    }
  }

}




