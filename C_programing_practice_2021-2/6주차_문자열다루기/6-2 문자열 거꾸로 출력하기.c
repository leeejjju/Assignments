#include <stdio.h>
#include <string.h>

/*하나의 문자열을 입력받은 후에 이 문자열 안에 들어있는 문자들의 순서를 거꾸로 바꾸어 저장한 문자열을 출력하라.*/

int main(void) {
  
  char str[100];      // 입력받은 문자열
  char reverse[100];  // 순서를 거꾸로 바꾼 문자열
  int i; //반복문 사용을 위한 변수 

  printf("문자열 입력 ");
  fgets(str, 100, stdin);

  for(i = 0; i < strlen(str); i++){
    reverse[i] = str[strlen(str)-1-i];
  }

  printf("역순으로 변환한 문자열은 ");
  for(i = 1; i < strlen(str); i++){
    printf("%c", reverse[i]);
  }

  return 0;
}

