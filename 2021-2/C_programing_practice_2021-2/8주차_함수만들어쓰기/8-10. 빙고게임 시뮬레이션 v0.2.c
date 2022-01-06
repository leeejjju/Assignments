#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*5*5 크기의 빙고게임을 진행하는 모습을 간단하게 시뮬레이션 하려고 한다.

입력받은 번호에 해당하는 칸에 대해서 검사하고 마크하는 작업을 markBingo()라는 함수를 제작하여 사용하라.

사용자로부터 칸 번호를 입력받아 해당 번호의 매트릭스 칸의 값을 0에서 1로 바꾸는 작업을 반복해서 수행한다. 예를 들어 12번을 입력받으면, 3번째 줄 2번째 칸에 해당되므로 다음과 같이 값을 바꾸면 된다.

만일 이미 1로 바뀐 칸을 다시 입력하면 "중복!"이라고 표시한다.

1~25가 아닌 숫자가 입력되면 반복을 종료한다.

그리고 지금까지 1로 표시된 칸들이 보이도록 매트릭스를 출력하라. 

+빙고가 완성되었는지 확인하여 그 결과를 리턴하는 작업을 수행한다. 
이때, 빙고가 완 성되었다는 것은 5개 중 1개의 줄 또는 1개의 열에 해당되는 5개의 칸이 모두 1로 마크된 경우를 말한다.

*/

int markBingo(int num, int b[5][5]); //선택된 칸에 빙고 마크하기 
int checkBingo(int b[5][5]); //빙고가 완성되었는지 확인하기
void printBingo(int b[5][5]); //빙고 출력하기 
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

    if( checkBingo(bingo)== 1){
      printf("빙고!");
      break;
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


int checkBingo(int b[5][5]){
  int bing = 1;

  for(i = 0; i < 5; i++){ //j열 검사 
    bing = 1; //희망을 가지고 시작 
    for(j = 0; j < 5; j++){
      if(b[i][j] == 0){ //하나라도 채워져있지 않다면 
        bing = 0; //해당 행 나가리 
        break;
      }
    }
    if(bing == 1){ //한 행동안 1이 유지되었으면 빙고 
      return 1;
    }
  }

  for(j = 0; j < 5; j++){ //i열 검사 
    bing = 1; //희망을 가지고 시작 
    for(i = 0; i < 5; i++){
      if(b[i][j] == 0){
        bing = 0;
        break;
      }
    }
    if(bing == 1){ //한 열동안 1이 유지되었으면 빙고 
      return 1;
    }
  }

  bing = 1; //희망을 가지고 시작 
  for(i = 0; i < 5; i++){ // '\'대각선 검사 
    if(b[i][i] == 0){
      bing = 0;
      break;
    }
  }
  if(bing == 1){ //검사동안 1이 유지되었으면 빙고 
      return 1;
  }

  bing = 1; //희망을 가지고 시작 
  for(i = 0; i < 5; i++){ // '/'대각선 검사 
    if(b[i][5-i] == 0){
      bing = 0;
      break;
    }
  }
  if(bing == 1){ //검사동안 1이 유지되었으면 빙고 
      return 1;
  }
  
  return 0; //전부 어림도없었으면 0 리턴 
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


