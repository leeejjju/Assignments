#include <stdio.h>
/*메인 함수에서 정수 3개(num1, num2, num3)를 입력받은 후, 이 숫자들의 주소값을 넘겨주면 크기가 큰 순서대 로 num1, num2, num3에 저장되도록 변경하는 함수를 제작하여 테스트하라.

단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라.*/

void sort3Num(int* n1, int* n2, int* n3);

int main(void) {
  int num1, num2, num3;
  printf("숫자 3개 입력 ");
  scanf("%d %d %d", &num1, &num2, &num3); 
  sort3Num(&num1, &num2, &num3);
  printf("정렬 결과 %d %d %d\n", num1, num2, num3); return 0;
}

void sort3Num(int* n1, int* n2, int* n3){
  int ary[3] = {*n1, *n2, *n3};
  int i;
  int max = 0, min = 999, mid = *n2;
  int max_index, min_index;

  //max = (*n1 > *n2) ? ((*n1 > *n3) ? *n1 : *n3) : ((*n2 > *n3) ? *n2 : *n3);
  //min = (*n1 < *n2) ? ((*n1 < *n3) ? *n1 : *n3) : ((*n2 < *n3) ? *n2 : *n3);

  for(i = 0; i < 3; i ++){
    if(ary[i] > max){
      max = ary[i];
      max_index = i;
    }
  }
  for(i = 0; i < 3; i ++){
    if(ary[i] < min){
      min = ary[i];
      min_index = i;
    }
  }


  for(i = 0; i < 3; i ++){
    if(max_index != i && min_index != i){
      mid = ary[i];
    }
  }

  *n1 = max, *n2 = mid, *n3 = min;

}
//파라미터 : 정수포인터 3개
//수행내용 : 정수포인터 3개의 실제 값을 기준으로 가장 큰 수부터 정렬되도록 변수값 변경함

