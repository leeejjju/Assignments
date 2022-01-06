#include <stdio.h>
#include <string.h>

int main(void) {
  
  char userid[30]; //사용자 아이디     
  char password[30]; //사용자 비밀번호 
  char name[30]; //사용자 이름 
  int i; //반복문 사용을 위한 변수

  printf("User Id? ");
  fgets(userid, 30, stdin); //키보드로부터 최대 30자 입력받아 userid에 저장 
  
  while(1){
    printf("Password? ");
    fgets(password, 30, stdin);
    if(password[3] == '\0'){ //2글자 이하일 경우 
      printf("-> 3글자 이상 입력할 것\n");
    }else{
      break;
    }
  }
  printf("User Name? ");
  fgets(name, 30, stdin);

  printf("\n");

  printf("User Id: %s", userid);
  printf("Password: %c%c", password[0], password[1]);
  for(i = 0; i < strlen(password) - 3; i++){
    printf("*");
  }
  printf("\nUser Name: %s", name);
  
  

  return 0;
}

