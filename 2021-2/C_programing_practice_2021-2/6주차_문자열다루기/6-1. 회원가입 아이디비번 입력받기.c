#include <stdio.h>
#include <string.h>

int main(void) {
  
  char userid[30]; //����� ���̵�     
  char password[30]; //����� ��й�ȣ 
  char name[30]; //����� �̸� 
  int i; //�ݺ��� ����� ���� ����

  printf("User Id? ");
  fgets(userid, 30, stdin); //Ű����κ��� �ִ� 30�� �Է¹޾� userid�� ���� 
  
  while(1){
    printf("Password? ");
    fgets(password, 30, stdin);
    if(password[3] == '\0'){ //2���� ������ ��� 
      printf("-> 3���� �̻� �Է��� ��\n");
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

