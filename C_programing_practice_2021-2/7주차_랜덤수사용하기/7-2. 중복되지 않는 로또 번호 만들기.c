#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 1부터 45사이의 임의의 숫자를 6개 만들어 로또 번호를 완성하라. 단, 6개의 번호 중에 중복되는 번호가 없도록 해야 한다. 출력한 후에 사용자에게 "더 만드시겠습니까?"를 물어보고 No(2)를 입력할 때까지 계속해서 반복하라. */


int main(void) {
  int lotto[6];  // 컴퓨터가 만들어 낸 로또 번호
  int count = 0;     // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
  int onemore = 1;   // 반복여부 입력 (1:Yes, 2:No)
  int i;         // 반복문을 위한 변수  
  int joong; //중복검사를 위한 변수 

  while(onemore == 1){

    srand(time(0)); //랜덤시드 변경=현재시간기준

      //이전까지의 배열과 하나하나 비교해 중복 발견시 새 랜덤값을 받고 그걸로 다시 검사..?
      //모든 케이스 통과하면 비로소 카운트 증가, 카운트가 6넘으면 종료

    while(count < 6){//로또번호 생성하기. 그러나 중복없음을 곁들인...  
      lotto[count] = rand()%45+1;
      joong = 0;

      if(count != 0){
        for(i = 0; i < count; i++){//역대(?) 번호들과 중복검사 
         if(lotto[count] == lotto[i]){
           joong = 1;
         }
        }
      }
    
      if(!joong){
        count ++;
      }

    }

    count = 0;
    printf("생성된 로또 번호는 ");
    for(i = 0; i < 6; i++){ //로또번호 출력하기 
      printf("%d ", lotto[i]);
    }
    printf("입니다.");

    printf("더 만드시겠습니까? (1:Yes, 2:No)");
    scanf("%d", &onemore);
  }

  



  return 0;
}
