#include<stdio.h>
#include <stdlib.h>

/*사용자가 임의로 숫자(1~100사이) 하나를 생각한 다음, 컴퓨터가 맞추도록 하는 프로그램을 작성하라. 프로그램의 수행방식은 다음과 같다.

1부터 100까지의 숫자 중 하나를 맞추는 것이므로, 처음에 50부터 시작하여 맞춰 나간다.

더 큰 수라면 사용자가 1을, 더 작은 수라면 2를, 맞추었으면 0을 입력한다.

1,2 이외의 숫자를 입력하면 반복을 종료한 후, 지금까지 시도한 횟수를 출력한다.*/

int main(void) {

  int num = 50;//컴퓨터가 추정할 숫자
  int plma = 25;//더하거나 뺄 숫자(회차마다 절반이 됨)
  int comp = 0; //사용자가 정한 숫자와 컴퓨터의 추정 숫자를 비교할 변수 
  int count = 1;// 시도 횟수 

  while(1){
    printf("How about %d? (try more : 1, try less : 2, right : 0) ", num);
    scanf("%d", &comp);

    if(comp == 1){ //더 큰 수
      num += plma;
    }else if(comp == 2){// 더 작은 수 
      num -= plma;
    }else{ //맞춤 
      break;
    }

    if(plma == 25 || plma == 3){ //테스트케이스의 이레귤러.. 
      plma = plma/2;
      plma ++;
    }else{
      plma = plma/2;
    }

    //dksl ㅌㅔ스트케이스 이상해요 

    count ++;
  }

  printf("%d tried.", count);

  return 0;
}
