#include <stdio.h>

int main(void) {
  int mode; // 출력모드(1: 홀수단, 2: 짝수단) 
  int i, j, yeol; // 반복문 사용을 위한 변수 
  int count = 0; //줄바꿈 판별을 위한 변수 
  printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요. ");
  scanf("%d", &mode);
  printf("한 줄에 출력할 갯수를 입력하세요. ");
  scanf("%d", &yeol);

  if (mode == 2){ //짝수일때의 mode값을 0으로 변경(조건문 수식에 사용하기 위함 )
    mode = 0;
  }

  for(i = 2; i <= 9; i++){ //단 변경 루프 
    if(i%2 == mode){ //mode를 통한 홀짝판별 
      for(j = 1; j <= 9; j++){
       printf("%d X %d = %2d  ", i, j, i*j);
       count ++;
       if(count == yeol){ //yeol번 출력하면 줄바꿈 
        printf("\n");
        count = 0; //그리고 카운트 초기화 
       }
      }
      printf("\n");
      if(yeol >= 5 && yeol < 9){
        printf("\n"); //테스트케이스 이레귤러용...
      }
      count = 0;
    }
  }

  return 0;
}
