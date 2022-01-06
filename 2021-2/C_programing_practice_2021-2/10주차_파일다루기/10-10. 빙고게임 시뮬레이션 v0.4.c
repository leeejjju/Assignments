#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
/*9-10 �������� ���׷��̵带 �����϶�. ��, ������ main()�Լ� �ڵ�� �������� �� ��.

�ֿ䳻�� : bingo �迭�� ���� 1���� 25������ ���ڷ� ä��� ������ ������ ����Ͽ� �����. �� 1���� 25������ ���ڴ� �ݵ�� 1������ ������ �Ѵ�. */

int markBingo(int num, int b[25]); 
void shuffleBingo(int b[25]);
void printBingo(int b[25]);

int main(void) { 
  int bingo[25];  // ����� ��Ʈ����
  int count=0;    // �õ� Ƚ��
  int number;     // �Է¹޴� ��ȣ
  int check;      // ����˻� �����
  int i;
  srand(time(0)); // ���� �ʱ�ȭ
  // �����Ʈ���� �ʱ�ȭ(1���� 25���� ������� ����) 
  for(i=0;i<25;i++) bingo[i]= i+1;

  shuffleBingo(bingo); // ���� ��Ʈ���� ���� 
  printBingo(bingo);   // ���� ��Ʈ���� ��� 
  while(1){
    printf("Enter a number(1~25) > "); 
    scanf("%d", &number); 
    if((number<1||number>25)) {
      printf("EXIT!\n");
      break; 
    }
    else {
      check = markBingo(number, bingo); 
      if(check!=0) count++;
      if(check==1) break;
    } 
  }
  printBingo(bingo);  // ���� ��Ʈ���� ���
  printf("%d�� �õ���!\n", count); 
  return 0;
}

void shuffleBingo(int b[25]){ //������ ����� 
	int x,y, temp;
	for(int i=0;i<50;i++){
		x = rand()%25;
		y = rand()%25;
		temp = b[x];
		b[x] = b[y];
		b[y] = temp;
	}
}

int markBingo(int num, int b[25]){ //�Է��� ���� ��ũ�ϰ� ����üũ 
  int hoBing = 1;
  int veBing = 1;

  for(int i = 0; i < 25; i++){
    if( b[i] == num){
      b[i] = 0; //��ũ�ϱ� 
      //����˻� *i��° �迭�� i/5��° �� i%5��° ĭ. 
      for(int j = 0; j < 25; j++){
        if(j/5 == i/5){ //������ �˻� 
          if(b[j] != 0){
            hoBing = 0;
          }
        }
        if(j%5 == i%5){ //������ �˻� 
          if(b[j] != 0){
            veBing = 0;
          }
        }
      }
      if (hoBing || veBing){
        return 1;
      }else{
        return -1;
      }
    }
  }
	return 0;
}
/*
b �迭���� num�̶�� ���� �ִ��� ã�Ƽ� (i=0 ~ 24)
	������ --> ��ũ!! num�̶�� ����� 0�� ����
		==> ���� �˻�..
		=====> ���� �˻�� ��� �ұ�? ���� �˰� �ִ� ������ ��� ���� num�� ����ִ� ĭ�� ��ũ�Ǿ��ٴ� ��!!
		�� ĭ�� ��, ĭ ��ȣ�� �˾Ƴ���.. i��° ĭ�� ���° ��, ���° ĭ�̳�? 
			i/5 ��°��, i%5 ��°ĭ �ΰ��� �˾Ƴ���...
			5���� �ݺ��ϸ鼭 i/5��°���� ��� ĭ���� 0�� ���� ī��Ʈ
			==> (i/5)*5 ��°ĭ���� 5���� ĭ�� �˻�..

			5���� �ݺ��ϸ鼭 i%5��°ĭ�� ��� �ٿ��� 0�� ���� ī��Ʈ
			==> (i%5)��° ĭ���� +5�� �ǳʶ�鼭 5���� ĭ�� �˻� 
			
			==> �����(ī��Ʈ�� 5�̸�) return 1
			===> �ƴϸ� return -1
	������ --> ���� ĭ�� üũ..
������ ���µ��� ������ �̹� ��ũ�� return 0
*/

void printBingo(int b[25]){ //�������  
  int i;
  printf("BINGO MATRIX\n"); 
  for(i=0;i<25;i++){
    if(i%5==0) 
      printf("--------------------------\n|");
    printf(" %2d |",b[i]);
    if(i%5==4) printf("\n"); 
  }
  printf("--------------------------\n"); 
}
