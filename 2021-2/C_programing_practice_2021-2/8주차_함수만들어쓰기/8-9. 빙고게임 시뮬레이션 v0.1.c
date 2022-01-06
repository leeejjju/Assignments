#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*5*5 ũ���� ��������� �����ϴ� ����� �����ϰ� �ùķ��̼� �Ϸ��� �Ѵ�.

�Է¹��� ��ȣ�� �ش��ϴ� ĭ�� ���ؼ� �˻��ϰ� ��ũ�ϴ� �۾��� markBingo()��� �Լ��� �����Ͽ� ����϶�.

����ڷκ��� ĭ ��ȣ�� �Է¹޾� �ش� ��ȣ�� ��Ʈ���� ĭ�� ���� 0���� 1�� �ٲٴ� �۾��� �ݺ��ؼ� �����Ѵ�. ���� ��� 12���� �Է¹�����, 3��° �� 2��° ĭ�� �ش�ǹǷ� ������ ���� ���� �ٲٸ� �ȴ�.

���� �̹� 1�� �ٲ� ĭ�� �ٽ� �Է��ϸ� "�ߺ�!"�̶�� ǥ���Ѵ�.

1~25�� �ƴ� ���ڰ� �ԷµǸ� �ݺ��� �����Ѵ�.

�׸��� ���ݱ��� 1�� ǥ�õ� ĭ���� ���̵��� ��Ʈ������ ����϶�. 
*/

int markBingo(int num, int b[5][5]);
void printBingo(int b[5][5]);
int i, j; //�ݺ��� ����� ���� ���� 

int main(void){
  int bingo[5][5]={0};    // ����� ��Ʈ����
  int num;
  

  while(1){ //1-25 ���� ���ڰ� ���ö����� �ݺ� 

    printf("Enter a number(1~25) > ");
    scanf("%d", &num);
    if(num > 25 || num <= 0){
      printf("EXIT!");
      break;
    }

    if (markBingo(num, bingo) == 0){ //��ũ�����Լ� ����, ��� �Է��� num�� �ߺ��̶�� �ߺ����� ��� 
      printf("�ߺ�!\n");
    }
  }


  printBingo(bingo);
  return 0;
}


int markBingo(int num, int b[5][5]){
  int mark = 1;
  if(num%5 == 0){ //5�� ����� ��� 
    if(b[num/5-1][4] == 0){ //����ִ� ĭ�ΰ�?
      b[num/5-1][4] = 1; //ä���
    }else{ //�̹� ���ִ� ĭ�ΰ�? 
      mark = 0; //�ߺ��Է¹޾Ҵٴ� �� 
    }
  }else{
    if(b[num/5][num%5-1] == 0){ //����ִ� ĭ�ΰ�?
      b[num/5][num%5-1] = 1; //ä���
    }else{ //�̹� ���ִ� ĭ�ΰ�? 
      mark = 0; //�ߺ��Է¹޾Ҵٴ� �� 
    }
  }

  return mark;
}



void printBingo(int b[5][5]){

  printf("\nBINGO MATRIX\n---------------------\n");
  for(i = 0; i < 5; i ++){
    printf("|");
    for(j = 0; j  < 5; j++){
      printf(" %d |", b[i][j]);
    }
    printf("\n");
  }
  printf("---------------------");

  return;
}


