#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	
  int bingo[5][5]={0}; // 5*5 매트릭스
  int i, j, k = 0;
  int num;
  int yeokdae[100] = {100}; //중복검사용 
  int count = 0, joongbok = 0; //몇번째 입력받고있는지, 중복이 등장했는지  

  while(1){

    printf("Enter a number(1~25) > ");
    scanf("%d", &num);

    if(num > 25){
      printf("EXIT!");
      break;
    }

    yeokdae[k] = num;
    k++;
    count ++;

    for(i = 1; i < count-1; i++){ //중복검사 
      if(num == yeokdae[i]){
        joongbok = 1;
      }
    } 
    
    
    if(joongbok == 1){
      printf("중복!\n");
    }else{
      for(i = 1; i <= 5; i++){ //입력받은 위치에 1 넣는 반복문 
        if(num <= 5){//첫줄 
          bingo[i-1][num-1] = 1; //1을 쇽 넣어주기
          break; 
        }else if(num >= i*5){ //해당 줄에 진입   
           num -= (i-1)*5; //해당줄 속 칸 찾아가기 
          bingo[i-1][num-1] = 1; //1을 쇽 넣어주기 
        }
      }
    }

    joongbok = 0;

  }


  printf("\n매트릭스의 내용은 다음과 같습니다.\n");
  for( i = 0; i < 5 ; i++){
    printf("---------------------\n|");
    for(j = 0; j < 5; j++){
      printf(" %d |", bingo[i][j]);

    }
    printf("\n");

  }
  printf("---------------------");

	return 0;
}
