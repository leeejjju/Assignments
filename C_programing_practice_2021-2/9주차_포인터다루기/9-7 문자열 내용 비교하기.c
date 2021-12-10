#include <stdio.h>
#include <string.h>
/*2개의 영어단어를 입력받은 후에, 포인터를 이용하여 이 단어 중에서 영어사전 순서에 따를 때 먼저 나오게 될 단어 를 알아내는 함수를 만들고, 이를 사용하여 결과를 출력하라.

단, 각각의 문자를 비교할 때에 대소문자는 무시하라. */

int which_first(char * str1, char * str2);

int main(void) {
  char str1[100], str2[100]; //문자열을 입력받을 공간

  printf("첫번째 문자열을 입력하시오. -->");
  scanf("%s", str1);
  printf("두번째 문자열을 입력하시오. -->");
  scanf("%s", str2);

  if(which_first(str1,str2) == 1){
    printf("첫번째 문자열이 사전에 먼저 나옵니다.");
  }else if(which_first(str1,str2) == 2){
    printf("두번째 문자열이 사전에 먼저 나옵니다.");
  }else{
    printf("두 문자열은 동일합니다.");
  }


  return 0;
}

int which_first(char * str1, char* str2){
  int fst = 0;

  if(strcmp(str1, str2) < 0){
    fst = 1;
  }else if(strcmp(str1, str2) > 0){
    fst = 2;
  }else{
    fst = 0;
  }

  return fst;
}
//파라미터 : 영어단어 2개의 문자열을 나타내는 포인터
// 리턴값 : 사전상 먼저 나타날 문자열의 순서, 1(첫 번째 문자열) 또는 2(두번째 문자열)
//수행내용 : 두 문자열을 문자순서대로 비교해서 사전적으로 먼저나오는 문자열을 찾아 1,2 중에 하나를 리턴한다.

