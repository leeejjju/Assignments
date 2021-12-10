#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
1부터 100 사이의 임의의 숫자를 만든 후에 사용자로 하여금 이 숫자를 맞추도록 하라. 사용자가 제시한 숫자보다 큰 수인지 작은 수인지를 알려주면서 몇 번 만에 맞추었는지 출력하라.
*/

int main(void){
  int answer;       // 컴퓨터가 만들어 낸 1부터 100사이의 임의의 숫자
  int number_try;   // 사용자가 제시한 숫자
  int count = 0;        // 사용자가 맞추려고 시도한 횟수 

  srand(time(0));
  answer = rand()%100+1; //1~100 사이 임의의 숫자로 정답 설정 

  while(1){
    printf("1부터 100까지의 숫자 하나를 맞춰보세요 "); //답안 입력받기
    scanf("%d", &number_try);


    if(answer < number_try){
      printf("좀 더 작은 수입니다.\n");
      count++;
    }else if(answer > number_try){
      printf("좀 더 큰 수입니다.\n");
      count++;
    }else{
      break;
    }
  }

  printf("%d 번만에 숫자를 맞추셨습니다.", count);

  return 0;
}
