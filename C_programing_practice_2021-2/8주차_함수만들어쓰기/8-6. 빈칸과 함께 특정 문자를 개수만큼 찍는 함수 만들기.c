#include <stdio.h>
/*�Ķ���ͷ� ���� �ϳ��� ���� �� ���� �Ѱ��ָ� �� �ٿ� ù ��° ���ڸ�ŭ ��ĭ�� ����� ��, �ٷ� �̾ �� ��° ���ڸ�ŭ �Ѱܹ��� ���ڸ� ȭ�鿡 ����ϴ� �Լ��� ������. �׸��� ����ڷκ��� ���(���� �ϳ�) �� ����, ������ �Է¹��� ��, �� �Լ��� ����ؼ� �Է��� ũ�⸸ŭ�� ����� ���̸� ���� ������ �ﰢ���� �Է��� ���ڸ������ ȭ�鿡 ��½��Ѷ�.

�Լ� ������ ������ ����.

void PrintCharWithBlank(int blanks, int size, char ch);

�Ķ����: blanks : ��ĭ�� ����, size : ����� ������ ����,ch : ����� ����

���ϰ� : ����

���೻�� : blanks ���ڸ�ŭ ��ĭ ���, size ������ŭ ch ���� ��� �� ����*/

void PrintCharWithBlank(blank, height, ch){

  int i, j;       // �ݺ��� ����� ���� ���� 

  for(i = 1; i <= height; i++){
    for(j = 0; j <(height+blank)- i ; j++){
      printf(" ");
    }
    for(j=0;j< i; j++){
      printf("%c", ch);
    }
    printf("\n");
  }

}

int main(void) {
  /*printf("Hello World\n");
  return 0;*/
  char ch;
  int height, blank;

  printf("����� ����? ");
  scanf("%c", &ch);
  printf("���̿� ������ ũ��? ");
  scanf("%d %d", &height, &blank);

  if(height < 0 || blank < 0){
    printf("�߸� �Է��ϼ̽��ϴ�.");
  }else{
    PrintCharWithBlank(blank, height, ch);
  }


}





