/*1101코딩T_02)_22100579
2. 일정 갯수의 정수값들이 주어졌을 때 이들 중 가장 빈도가 많은 값을 찾는 프로그램을 작성하시오.
(동일 빈도의 값이 여러개이면 첫번째로 발견된 값을 출력 )
*/
#include <stdio.h>
#include <string.h>

int main(void){
  int size;
  int i, j, max = 0, max_index;

  printf("size: ");
  scanf("%d", &size);

  int num[size], count[size];

  printf("input: ");
  for(i = 0; i < size; i++){ //입력받고 카운트 1로 초기화... 
    scanf("%d", &num[i]);
    count[i] = 1;
  }

  for(i = 0; i < size; i++){
    for(j = i+1; j < size; j++){
      if(num[i] == num[j]){
        count[i] ++;
        break;
      }
    }
  }

  for(i = 0; i < size; i++){
    if(max < count[i]){
      max = count[i];
      max_index = i;
    }
  }

  printf("%d", num[max_index]);



  return 0;
}

