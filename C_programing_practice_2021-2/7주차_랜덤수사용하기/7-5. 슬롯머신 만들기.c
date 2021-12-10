#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*간단한 슬롯 머신을 만들어라. 사용자에게 코인의 개수를 숫자로 입력받은 다음에, 1부터 9까지의 숫자 3개 를 랜덤으로 만들어 3개의 숫자가 같으면 상금으로 코인 4개, 2개의 숫자가 같으면 코인 2개를 더해준다. 한 번 할 때마다 코인을 1개 씩 소모하게 되고, 사용자의 코인이 모두 소모될 때까지 게임을 반복시켜라.*/


int main(void) {
  int coins;      // 사용자의 코인 수. (최초에 입력받음)
  int number[3];  // 랜덤하게 만들어진 슬롯머신의 숫자 3개 
  int dummy;      // 게임스타트를 위한 의미 없는 입력 숫자 
  int i, j;          //반복문을 위한 변수 
  int stage = 0; //게임 실행 회차 
  int count = 0; //슬롯머신과의 일치 횟수

    printf("사용하실 코인의 개수를 입력하세요.");
    scanf("%d", &coins);

  while(coins > 0){//소지 코인 소진시까지 반복

    stage ++;
    count = 0;

    printf("\n게임 %d회 Start!!! (아무 숫자나 입력하세요)", stage);
    coins --;//게임 시작, 코인 소모 
    scanf("%d", &dummy);


    printf("게임 결과 : ");
    srand(time(0));
    for(i = 0; i < 3; i++){ //이번 회차의 슬롯머신 넘버 생성, 출력  
      number[i] = rand()%9+1;
      printf("%d ", number[i]);
    }


  for(i = 0; i < 3; i++){
    for(j = 0; j < i; j++){
      if(number[i] == number[j]){
        count += 2;
      }
    }
  }


    if(count == 4){ //카운트에 따라 결과 출력, 정산 
      printf("----> 숫자 3개 일치... 코인 4개 증정\n");
      coins += 4;
    }else if(count == 2){
      printf("----> 숫자 2개 일치... 코인 2개 증정\n");
      coins += 2;
    }else{
      printf("----> 꽝입니다... 아쉽군요\n");
    }

    printf("남아있는 코인은 %d개입니다.\n", coins);
  }






  return 0;
}
