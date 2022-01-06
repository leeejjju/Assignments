#include <stdio.h>
#include <string.h>
/*회원 로그인 시에 아이디와 비번을 입력받은 후 다음과 같이 검사결과를 출력하라.

1) 로그인 성공

2) 아이디는 맞는데 비번이 틀림

3) 그런 아이디가 없음*/

int main(void) {
  char username[5][20]={"kim", "lee", "park", "hong", "choi"}; 
  char password[5][20]={"1111", "1234", "3456", "3535", "7777"};
  char inputId[20], inputPw[20]; //입력받은 것을 저장할 공간 
  int id = 0, pw = 0; //아이디와 비밀번호가 맞는지 여부 
  int i, j; //반복문 사용을 위한 변수 

  printf("아이디를 입력하시오. ");
  scanf("%s", inputId);

  printf("비밀번호를 입력하시오. ");
  scanf("%s", inputPw);

  for(i = 0; i < 5; i ++){
    if(strcmp(username[i], inputId) == 0){
      id = 1;
      if(strcmp(password[i], inputPw) == 0){
        pw = 1;
        break;
      }
    }
  }


  if(id == 1){
    if(pw == 1){
      printf("로그인 성공");
    }else{
      printf("아이디는 맞는데 비번이 틀림");
    }
  }else{
    printf("그런 아이디가 없음");
  }


  
  
  


  return 0;
}


