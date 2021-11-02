/*1101코딩T_05)_22100579
5. 어떤 id설정을 위해서 후보 string을 입력받아 다음 네가지 조건을 점검하는 프로그램을 작성하시오.(한글은 고려하지 않음)
1) 영문자 및 숫자로 구성되며 5자리 이상 12자리 이하의 길이를 갖는다.
2) 영문자와 숫자 둘 모두를 반드시 포함(영문자와 숫자를 반드시 포함하여야 합니다.)
3) 영문자나 숫자 외의 문자는 사용할 수 없음
4) 동일 문자나 숫자를 연속으로 3회 이상 사용할 수 없음(동일문자를 3회 이상 사용할 수 없습니다.)
충족시(정상적인 id입니다.)*/
#include <stdio.h>
#include <string.h>

int main(void){
  char id[50];
  int alpha = 0, num = 0, other = 0, error = 0;
  int pre, prepre;
  int i;

  printf("enter ID: ");
  scanf("%s", id);

  if(strlen(id) < 5 || strlen(id) > 13){ //조건 1번 
    printf("5글자 이상 12글자 이하로 입력하시오.\n");
    error = 1;
  }
  
  for(i = 0; i < strlen(id); i++){ //조건 2번 
    if((id[i] <= 90 && id[i] >= 65) || (id[i] <= 122 && id[i] >= 97)){ //알파벳 
    alpha = 1;
    }else if(id[i] <= 57 && id[i] >= 48){ //숫자
      num = 1;
    }else{ //그외 문자
      other = 1;
    }
  }

  if(!(alpha && num)){
    printf("영문자와 숫자를 반드시 포함하여야 합니다.\n");
    error = 1;
  }

  if(other){
    printf("영문자와 숫자로만 구성되어야 합니다.\n");
    error = 1;
  }

  for(i = 0; i < strlen(id)-2; i++){ //조건 4번  
    prepre = id[i];
    pre = id[i+1];
    if((id[i+2] == pre) && (pre == prepre)){
      printf("동일문자를 3회 이상 사용할 수 없습니다.\n");
      error = 1;
      break;
    }

  }

  if(error != 1){ //아무 조건에도 안 걸리면  
    printf("정상적인 id입니다.");
  }

  return 0;
}

