#include <stdio.h>

int main(void) {
  
  int num[10];                // 10개의 숫자
  int first = 0, first_max_index; // 첫 번째로 큰 수
  int second = 0;                 // 두 번째로 큰 수
  int second_max_index;       // 두 번째로 큰 수의 인덱스 
  int i;                      // 반복문을 위한 변수

  for(i = 0; i < 10; i++){ //입력받아 저장하기, 가장 큰 수 찾아두기 
    printf("%d번째 수를 입력하시오. ", i+1);
    scanf("%d", &num[i]);

    if(first < num[i]){
      first = num[i];
      first_max_index = i;
    }

  } 

  for(i = 0; i < 10; i++){ //아까의 최대값 제외하고 가장 큰 수 찾기 
    if(i != first_max_index){
      if(second < num[i]){
      second = num[i];
      second_max_index = i+1;
      }
    }
  }

  printf("두번째로 큰 수는 %d번째 수 %d입니다.", second_max_index, second);

  return 0;
}
