#include <stdio.h>
#include <string.h>

/*�ϳ��� ���ڿ��� �Է¹��� �Ŀ� �� ���ڿ� �ȿ� ����ִ� ���ڵ��� ������ �Ųٷ� �ٲپ� ������ ���ڿ��� ����϶�.*/

int main(void) {
  
  char str[100];      // �Է¹��� ���ڿ�
  char reverse[100];  // ������ �Ųٷ� �ٲ� ���ڿ�
  int i; //�ݺ��� ����� ���� ���� 

  printf("���ڿ� �Է� ");
  fgets(str, 100, stdin);

  for(i = 0; i < strlen(str); i++){
    reverse[i] = str[strlen(str)-1-i];
  }

  printf("�������� ��ȯ�� ���ڿ��� ");
  for(i = 1; i < strlen(str); i++){
    printf("%c", reverse[i]);
  }

  return 0;
}

