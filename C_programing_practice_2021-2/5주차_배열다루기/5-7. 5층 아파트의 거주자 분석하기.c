#include <stdio.h>

int main(void) {
  
  int number[5][3];       // 각 집의 거주자 수
  int floor_total[5] = {0,};     // 층별 거주자 합계 (1층, 2층, 3층, 4층, 5층)
  int line_total[3] = {0,};      // 호수별 거주자 합계 (1호라인, 2호라인, 3호라인)
  int total = 0;              // 아파트의 총 거주자 수
  int ho =101;                 // 아파트 호를 나타내는 변수
  int i, j;               // 반복문 사용을 위한 변수 

  for(i = 0; i < 5; i++){ //층별 루프 

    for(j = 0; j < 3; j++){ //호수별 사람수 입력받기 
      printf("%d0%d호에 살고 있는 사람의 수? ", i+1, j+1 );
      scanf("%d", &number[i][j]);

      floor_total[i] += number[i][j]; //층별 거주자 합계

      if(j == 0){ // 라인별 거주자 합계 
        line_total[0] += number[i][j];
      }else if(j == 1){
        line_total[1] += number[i][j];
      }else{
        line_total[2] += number[i][j];
      }

      total += number[i][j];

    }

  }

  for(i = 0; i < 5; i++){ //층별 사람수 출력 
    printf("%d층에 살고 있는 사람의 수 %d명\n", i+1, floor_total[i]);
  }

  for(i = 0; i < 3; i++){ //라인별 사람수 출력 
    printf("\n%d호라인에 살고 있는 사람의 수 %d명", i+1, line_total[i]);

  }


  printf("\n\n이 아파트에 사는 사람 모두 %d명", total);

  return 0;
}

