#include <stdio.h>
/*�Ķ���ͷ� ���� �ϳ��� �Ѱ��ָ� �� ���ڸ�ŭ ��('*')�� ȭ�鿡 ����ϴ� �Լ��� ������. �׸��� ����ڷκ��� 10 ���� ���ڸ� �Է¹��� ��, �� �Լ��� ����ؼ� 10�ٿ� ���ļ� �� ���ڸ�ŭ�� ���� ȭ�鿡 ��½��Ѷ�.

�Լ� ������ ������ ����.

void PrintStar(int size);

�Ķ����:size : ����� ���� ����

���ϰ� : ����

���೻�� : size ������ŭ '*' ���� ��� �� ����*/

void PrintStar(size){
  int i;
  for( i = 0; i < size; i++){
    printf("*");
  }
  printf("\n");
}

int main(void) {
  int size[10];
  int i;

  printf("���� 10���� �Է� ");

  for(i = 0; i < 10; i++){
    scanf("%d", &size[i]);
  }

  for(i = 0; i < 10; i++){
    PrintStar(size[i]);
  }


  return 0;
}
