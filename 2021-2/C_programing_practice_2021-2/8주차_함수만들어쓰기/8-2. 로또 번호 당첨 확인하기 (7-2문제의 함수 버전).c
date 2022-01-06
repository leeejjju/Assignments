#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*사용자에게 1부터 45사이의 임의의 숫자를 6개 입력받은 후에, 프로그램에서 만든 임의의 로또 번호와 대조하여 몇 개의 숫자가 일치하는 지 출력하라. 단, 사용자가 입력한 6개의 번호 중에 중복되는 번호가 없도록 입력받아야 하며, 프로그램에서 만든 임의의 로또 번호에서도 중복되는 번호가 없도록 해야 한다.

이 때, 로또번호 2개를 받아서 번호 몇 개가 일치하는지 리턴하는 함수를 제작하여 확인하라.

int matchLotto(int lotto1[6], int lotto2[6]);

파라미터 : 입력한 로또 배열과 프로그램의 로또 배열

리턴값 : 일치하는 로또번호 개수

수행내용 : 로또번호 배열을 파라미터로 받아 번호 몇개가 일치하는지 리턴*/
int matchLotto(int lotto_user[6], int lotto_com[6]){
  int count = 0;
  int i, j;

  for(i = 0; i < 6; i++){ //입력된 번호와 로또번호 중복검사 
    for(j = 0; j < i; j++){
      if(lotto_user[j] == lotto_com[i]){//중복이 있을 경우 매치카운트 증가  
        count++;
      }
    }
  }

  return count;
}

int main(void){
  int lotto_com[6];   // 컴퓨터가 만들어 낸 로또 번호
  int lotto_user[6];  // 사용자가 입력한 로또 번호
  int i, j;              // 반복문을 위한 변수
  int count = 0;          // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
  int match_count = 0;    // 일치하는 로또 번호의 갯수 (0~6)  
  int joong; //중복검사를 위한 변수 


    srand(time(0)); //랜덤시드 변경=현재시간기준


    while(count < 6){//로또번호 생성하기. 그러나 중복없음을 곁들인...  
      lotto_com[count] = rand()%45+1;
      joong = 0;

      if(count != 0){
        for(i = 0; i < count; i++){//역대(?) 번호들과 중복검사 
         if(lotto_com[count] == lotto_com[i]){
           joong = 1;
         }
        }
      }    
      if(!joong){ //방금 받은 수가 중복 없는 녀석이면 카운트 증가(인덱스 넘기기)
        count ++;
      }
    }


  for(i = 0; i < 6; i++){ //사용자에게 로또 번호 입력받기 
    printf("원하는 %d번째 로또 숫자를 입력 ", i+1);
    scanf("%d", &lotto_user[i]);

    if(i != 0){
      for(j = 0; j < i; j++){
        if((lotto_user[j] == lotto_user[i]) || (lotto_user[i] > 45 ||lotto_user[i] < 1)){ //중복이 있거나 범위숫자 외인 경우 에러메세지 출력 후 해당 인덱스로 재입력받기 
          printf("-> 잘못 입력\n");
          i --;
          break;
        }
      }
    }
  }

  printf("이번 주의 로또 당첨 번호는");
  for(i = 0; i < 6; i++){
    printf(" %d", lotto_com[i]);
  }

  match_count = matchLotto(lotto_user, lotto_com);

  printf("\n일치하는 로또 번호는 %d개입니다.", match_count);


  return 0;
}
