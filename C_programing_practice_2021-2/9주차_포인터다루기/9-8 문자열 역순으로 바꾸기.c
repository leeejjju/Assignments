#include <stdio.h>
#include <string.h>
/*�ϳ��� ������ �Է¹��� �Ŀ�, ���� �����͸� �̿��Ͽ� �� ���ڿ��� ���� ���ڿ��� �����ϴ� �Լ��� ����� �׽�Ʈ�϶�. */

void reverseString(char* str); 

int main(void) {
  char str[100]; //���ڿ� �Է¹��� ���� 

  printf("���ڿ� �Է� ");
  fgets(str, 100, stdin);

  str[strlen(str)-1] = '\0'; //�������� ���� �����ϱ� 

  reverseString(str); //�������� �ٲٱ� 

  printf("�������� ��ȯ�� ���ڿ��� %s", str);

  return 0;
}

void reverseString(char* str){
  char cmp; //�ӽ÷� ������ ���� 
  int i; //�ݺ����� 

  for(i = 0; i < (strlen(str))/2; i++){
    cmp = str[i];
    str[i] = str[strlen(str)-i-1];
    str[strlen(str)-i-1] = cmp;
  }
}
//�Ķ���� : ���� 1��
//���ϰ� : ����
//���೻�� : �� ���ڿ��� �������� ������
//��� : ������ ù��° ���ڿ� ������ ���ڸ� �¹ٲٴ� �۾��� �߰� ��ġ�� ���ڱ��� �ݺ��Ѵ�.
