#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*5*5 크기의 빙고게임을 진행하는 모습을 간단하게 시뮬레이션 하려고 한다.

입력받은 번호에 해당하는 칸에 대해서 검사하고 마크하는 작업을 markBingo()라는 함수를 제작하여 사용하라.

사용자로부터 칸 번호를 입력받아 해당 번호의 매트릭스 칸의 값을 0에서 1로 바꾸는 작업을 반복해서 수행한다. 예를 들어 12번을 입력받으면, 3번째 줄 2번째 칸에 해당되므로 다음과 같이 값을 바꾸면 된다.

만일 이미 1로 바뀐 칸을 다시 입력하면 "중복!"이라고 표시한다.

1~25가 아닌 숫자가 입력되면 반복을 종료한다.

그리고 지금까지 1로 표시된 칸들이 보이도록 매트릭스를 출력하라. 
*/

int markBingo(int num, int b[5][5]);
void printBingo(int b[5][5]);
int i, j; //반복문 사용을 위한 변수 

int main(void){
  int bingo[5][5]={0};    // 빙고용 매트릭스
  int num;
  

  while(1){ //1-25 밖의 숫자가 나올때까지 반복 

    printf("Enter a number(1~25) > ");
    scanf("%d", &num);
    if(num > 25 || num <= 0){
      printf("EXIT!");
      break;
    }

    if (markBingo(num, bingo) == 0){ //마크빙고함수 실행, 방금 입력한 num이 중복이라면 중복문구 출력 
      printf("중복!\n");
    }
  }


  printBingo(bingo);
  return 0;
}


int markBingo(int num, int b[5][5]){
  int mark = 1;
  if(num%5 == 0){ //5의 배수일 경우 
    if(b[num/5-1][4] == 0){ //비어있는 칸인가?
      b[num/5-1][4] = 1; //채우기
    }else{ //이미 차있는 칸인가? 
      mark = 0; //중복입력받았다는 뜻 
    }
  }else{
    if(b[num/5][num%5-1] == 0){ //비어있는 칸인가?
      b[num/5][num%5-1] = 1; //채우기
    }else{ //이미 차있는 칸인가? 
      mark = 0; //중복입력받았다는 뜻 
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


