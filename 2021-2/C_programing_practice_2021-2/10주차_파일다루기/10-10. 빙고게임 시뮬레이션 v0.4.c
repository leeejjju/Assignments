#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
/*9-10 문제에서 업그레이드를 진행하라. 단, 제공된 main()함수 코드는 수정하지 말 것.

주요내용 : bingo 배열의 값을 1부터 25까지의 숫자로 채우되 임의의 순서를 사용하여 만든다. 즉 1부터 25까지의 숫자는 반드시 1번씩만 들어가도록 한다. */

int markBingo(int num, int b[25]); 
void shuffleBingo(int b[25]);
void printBingo(int b[25]);

int main(void) { 
  int bingo[25];  // 빙고용 매트릭스
  int count=0;    // 시도 횟수
  int number;     // 입력받는 번호
  int check;      // 빙고검사 결과값
  int i;
  srand(time(0)); // 랜덤 초기화
  // 빙고매트릭스 초기화(1부터 25까지 순서대로 넣음) 
  for(i=0;i<25;i++) bingo[i]= i+1;

  shuffleBingo(bingo); // 빙고 매트릭스 섞기 
  printBingo(bingo);   // 빙고 매트릭스 출력 
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
  printBingo(bingo);  // 빙고 매트릭스 출력
  printf("%d번 시도됨!\n", count); 
  return 0;
}

void shuffleBingo(int b[25]){ //빙고판 쓰까묵기 
	int x,y, temp;
	for(int i=0;i<50;i++){
		x = rand()%25;
		y = rand()%25;
		temp = b[x];
		b[x] = b[y];
		b[y] = temp;
	}
}

int markBingo(int num, int b[25]){ //입력한 수로 마크하고 빙고체크 
  int hoBing = 1;
  int veBing = 1;

  for(int i = 0; i < 25; i++){
    if( b[i] == num){
      b[i] = 0; //마크하기 
      //빙고검사 *i번째 배열은 i/5번째 줄 i%5번째 칸. 
      for(int j = 0; j < 25; j++){
        if(j/5 == i/5){ //가로줄 검사 
          if(b[j] != 0){
            hoBing = 0;
          }
        }
        if(j%5 == i%5){ //세로줄 검사 
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
b 배열에서 num이라는 값이 있는지 찾아서 (i=0 ~ 24)
	있으면 --> 마크!! num이라는 값대신 0을 넣음
		==> 빙고 검사..
		=====> 빙고 검사는 어떻게 할까? 현재 알고 있는 정보는 방금 전에 num이 들어있는 칸이 마크되었다는 것!!
		이 칸의 줄, 칸 번호를 알아내자.. i번째 칸은 몇번째 줄, 몇번째 칸이냐? 
			i/5 번째줄, i%5 번째칸 인것을 알아냈음...
			5번을 반복하면서 i/5번째줄의 모든 칸에서 0의 값을 카운트
			==> (i/5)*5 번째칸부터 5개의 칸을 검사..

			5번을 반복하면서 i%5번째칸의 모든 줄에서 0의 값을 카운트
			==> (i%5)번째 칸부터 +5씩 건너띄면서 5개의 칸을 검사 
			
			==> 빙고면(카운트가 5이면) return 1
			===> 아니면 return -1
	없으면 --> 다음 칸을 체크..
끝까지 갔는데도 없으면 이미 마크라서 return 0
*/

void printBingo(int b[25]){ //빙고출력  
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
