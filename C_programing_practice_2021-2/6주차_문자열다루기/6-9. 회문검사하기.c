#include <stdio.h>
#include <string.h>
/*문장을 1개 입력받아 이 문장이 회문(Palindrome)인지 판별하라.

회문이란 거꾸로 읽어도 동일한 알파벳 순서가 되는 문장이다.

단, 알파벳 이외의 문자는 제외하고, 모든 알파벳은 소문자라고 가정한다.*/


int main(void) {

  char str[100];      // 입력받은 문자열
  char str_pure[100] = {'\0'}; //알파벳만 남긴 문자열 
  char reverse[100];  // 순서를 거꾸로 바꾼 문자열
  int i, count = 0; //반복문 사용을 위한 변수 

  printf("Sentence > ");
  fgets(str, 100, stdin);
  str[strlen(str)] = '\0';

  for(i = 0; i < strlen(str); i++){//문자열에서 알파벳만 골라서 새로운 문자열을 만들기 
    if(str[i] >= 97 && str[i] <= 122){ //해당 글자가 알파벳이면 저장 
      str_pure[count] = str[i];
      count ++;
    }
  }

  str_pure[strlen(str_pure)] = '\0';

  for(i = 0; i < strlen(str_pure)+1; i++){ //문자열 거꾸로 만들기
    reverse[i] = str_pure[strlen(str_pure)-1-i];
  }

  //printf("pure = %s\n", str_pure);
  //printf("reverse = %s\n", reverse);

  if(strcmp(str_pure, reverse) != 0){
    printf("Not Palindrome!");
  }else{
    printf("Palindrome!");
  }



  return 0;
}

