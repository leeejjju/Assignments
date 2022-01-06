#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*다음과 같이 사용자와 컴퓨터가 가위바위보를 하는 프로그램을 만들어라.

1) 랜덤으로 가위(1), 바위(2), 보(3) 셋 중에 하나를 만든다.
2) 사용자에게 가위(1), 바위(2), 보(3) 중에 하나를 숫자로 입력받는다.
3) 사용자가 입력한 것과 컴퓨터가 만들어 낸 것을 비교하여

컴퓨터가 이기면, "컴퓨터 승!"
사용자가 이기면, "사용자 승!"
비기면, "비김~" 으로 출력한다.

4) 사용자가 0을 입력할 때까지 위 1)부터 3)을 계속 반복하다가, 끝나면 그동안 컴퓨터와 사용자가 이긴 횟수와 진 횟수, 비긴 횟수를 출력하라.*/


int main(void) {
  
  int com_finger;   // 컴퓨터가 낸 가위(1), 바위(2), 보(3)
  int my_finger;    // 사용자가 낸 가위(1), 바위(2), 보(3)
  int score[2][3] = {0};  // 결과 횟수 (1행 : 컴퓨터의 승, 무, 패, 2행 : 사용자의 승, 무, 패)
  int i, j;         // 반복문을 위한 변수


  while(1){

    srand(time(0));
    com_finger = rand()%3+1;

    printf("가위(1), 바위(2), 보(3)를 입력하세요.");
    scanf("%d", &my_finger);

    if(my_finger == 0){
      break;
    }

    if(my_finger > 3 || my_finger < 1){
      printf("올바른 숫자를 입력하세요\n");
    }else{

      if(com_finger == 1){
        printf("컴퓨터: 가위 ");
        if(my_finger == 1){
            printf("비김~\n");
            score[0][1] ++;
            score[1][1] ++;
        }else if(my_finger == 2){
            printf("-> 사용자 승!\n");
            score[0][2] ++;
            score[1][0] ++;
        }else{
            printf("-> 컴퓨터 승!\n");
            score[0][0] ++;
            score[1][2] ++;
        }  
      }else if(com_finger == 2){
        printf("컴퓨터: 바위 ");
        if(my_finger == 2){
            printf("비김~\n");
            score[0][1] ++;
            score[1][1] ++;
        }else if(my_finger == 3){
            printf("-> 사용자 승!\n");
            score[0][2] ++;
            score[1][0] ++;
        }else{
            printf("-> 컴퓨터 승!\n");
            score[0][0] ++;
            score[1][2] ++;
        }
      }else{
        printf("컴퓨터: 보 ");
        if(my_finger == 3){
            printf("비김~\n");
            score[0][1] ++;
            score[1][1] ++;
        }else if(my_finger == 1){
            printf("-> 사용자 승!\n");
            score[0][2] ++;
            score[1][0] ++;
        }else{
            printf("-> 컴퓨터 승!\n");
            score[0][0] ++;
            score[1][2] ++;
        }
      }
    }
  }

   printf("컴퓨터: 이긴 횟수 %d회, 진 횟수 %d회, 비긴 횟수 %d회\n", score[0][0], score[0][2], score[0][1]);
   printf("사용자: 이긴 횟수 %d회, 진 횟수 %d회, 비긴 횟수 %d회", score[1][0], score[1][2], score[1][1]);


  return 0;
}
