#include <stdio.h>
/*�Ķ���ͷ� ���� �ϳ��� ���� �ϳ��� �Ѱ��ָ� �� ���ڸ�ŭ �Ѱܹ��� ���ڸ� ȭ�鿡 ����ϴ� �Լ��� ������. �׸��� ����ڷκ��� ���� �ϳ��� 10���� ���ڸ� �Է¹��� ��, �� �Լ��� ����ؼ� 10�ٿ� ���ļ� �� ���ڸ�ŭ�� ���ڸ� ȭ�鿡 ��� ���Ѷ�.

�Լ� ������ ������ ����.

void PrintChar(int size, char ch);

�Ķ����: size : ����� ������ ����, ch : ����� ����

���ϰ� : ����

���೻�� : size ������ŭ ch ���� ��� �� ����*/

void PrintStar(ch, size){
  int i;
  for( i = 0; i < size; i++){
    printf("%c", ch);
  }
  printf("\n");
}

int main(void) {
  int size[10];
  char ch;
  int i;

  printf("����� ����? ");
  scanf("%c", &ch);

  printf("���� 10��? ");

  for(i = 0; i < 10; i++){
    scanf("%d", &size[i]);
  }

  for(i = 0; i < 10; i++){
    PrintStar(ch, size[i]);
  }


  return 0;
}
