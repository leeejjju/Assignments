#include <stdio.h>

int main(void) {
  int birth_year; // 태어난 년도 
  int age; // 나이

  //사용자의 입력 안내메시지 출력
  printf("Birth year? ");
  //사용자가 태어난 년도 입력받아 birth_year에 저장
  scanf("%d", &birth_year);
  //입력된 birth_year을 이용하여 나이 계산, age에 저장
  age = 2021 - birth_year + 1;
  //age 출력 
  printf("%d", age);


  return 0;
}
