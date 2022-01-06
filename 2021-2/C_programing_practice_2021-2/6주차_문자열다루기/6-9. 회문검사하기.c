#include <stdio.h>
#include <string.h>
/*������ 1�� �Է¹޾� �� ������ ȸ��(Palindrome)���� �Ǻ��϶�.

ȸ���̶� �Ųٷ� �о ������ ���ĺ� ������ �Ǵ� �����̴�.

��, ���ĺ� �̿��� ���ڴ� �����ϰ�, ��� ���ĺ��� �ҹ��ڶ�� �����Ѵ�.*/


int main(void) {

  char str[100];      // �Է¹��� ���ڿ�
  char str_pure[100] = {'\0'}; //���ĺ��� ���� ���ڿ� 
  char reverse[100];  // ������ �Ųٷ� �ٲ� ���ڿ�
  int i, count = 0; //�ݺ��� ����� ���� ���� 

  printf("Sentence > ");
  fgets(str, 100, stdin);
  str[strlen(str)] = '\0';

  for(i = 0; i < strlen(str); i++){//���ڿ����� ���ĺ��� ��� ���ο� ���ڿ��� ����� 
    if(str[i] >= 97 && str[i] <= 122){ //�ش� ���ڰ� ���ĺ��̸� ���� 
      str_pure[count] = str[i];
      count ++;
    }
  }

  str_pure[strlen(str_pure)] = '\0';

  for(i = 0; i < strlen(str_pure)+1; i++){ //���ڿ� �Ųٷ� �����
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

