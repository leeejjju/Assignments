#include <stdio.h>
#include <string.h>
/*ȸ�� �α��� �ÿ� ���̵�� ����� �Է¹��� �� ������ ���� �˻����� ����϶�.

1) �α��� ����

2) ���̵�� �´µ� ����� Ʋ��

3) �׷� ���̵� ����*/

int main(void) {
  char username[5][20]={"kim", "lee", "park", "hong", "choi"}; 
  char password[5][20]={"1111", "1234", "3456", "3535", "7777"};
  char inputId[20], inputPw[20]; //�Է¹��� ���� ������ ���� 
  int id = 0, pw = 0; //���̵�� ��й�ȣ�� �´��� ���� 
  int i, j; //�ݺ��� ����� ���� ���� 

  printf("���̵� �Է��Ͻÿ�. ");
  scanf("%s", inputId);

  printf("��й�ȣ�� �Է��Ͻÿ�. ");
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
      printf("�α��� ����");
    }else{
      printf("���̵�� �´µ� ����� Ʋ��");
    }
  }else{
    printf("�׷� ���̵� ����");
  }


  
  
  


  return 0;
}


