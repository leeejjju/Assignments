#include <stdio.h>

int main(void) {
  int dan;    // 출력하려는 구구단의 단 수 
  int i;      // 반복문을 위한 변수 
  int test = 0; //올바르 단이 입력되었는지 판단 



  while(test == 0){
    printf("출력하고 싶은 구구단의 단 수?(2~9) ");
    scanf("%d", &dan);

   if(dan < 2 || dan > 9){
     printf("잘못 입력하였습니다.\n");
   }else{
      test = 1;
      for(i = 1; i <= 9; i++){
        printf("%d x %d = %d\n", dan, i, dan*i);
       }
      }
  }

  

  return 0;
}
