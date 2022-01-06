/*1101코딩T_03)_22100579
3. 다음 예와 같은 형태로 array를 선언하여 프로그램을 작성하시오. 
n값을 증가시켜 확장하여도 정확한 값이 출력되도록 작성할 것. 
주어진 array에서 두번째로 큰 값은 무엇인가?*/

#include <stdio.h>
#define N 10

int main(void){
  int a[N] = {3, 7, 2, 6, 9, 4, 8, 1, 3, 3}; //주어진 배열 
  int i; //반복문용
  int max = 0, max_index, sed_max = 0;

  for(i = 0; i < N; i++){ //최대값 찾아내기 
    if(max < a[i]){
      max = a[i];
      max_index = i;
    }
  }

  for(i = 0; i < N; i++){ //차대값 찾아내기 
    if(i != max_index && (sed_max < a[i])){
      sed_max = a[i];
    }
  }

  printf("두번째로 큰 값은 %d", sed_max);

  return 0;
}

