#include <stdio.h>
#include <string.h>
/*하나의 문장을 입력받은 후에, 문자 포인터를 이용하여 이 문자열을 역순 문자열로 변경하는 함수를 만들고 테스트하라. */

void reverseString(char* str); 

int main(void) {
  char str[100]; //문자열 입력받을 공간 

  printf("문자열 입력 ");
  fgets(str, 100, stdin);

  str[strlen(str)-1] = '\0'; //마지막에 엔터 제거하기 

  reverseString(str); //역순으로 바꾸기 

  printf("역순으로 변환한 문자열은 %s", str);

  return 0;
}

void reverseString(char* str){
  char cmp; //임시로 저장할 공간 
  int i; //반복문용 

  for(i = 0; i < (strlen(str))/2; i++){
    cmp = str[i];
    str[i] = str[strlen(str)-i-1];
    str[strlen(str)-i-1] = cmp;
  }
}
//파라미터 : 문장 1개
//리턴값 : 없음
//수행내용 : 이 문자열을 역순으로 변경함
//방법 : 문장의 첫번째 문자와 마지막 문자를 맞바꾸는 작업을 중간 위치의 문자까지 반복한다.
