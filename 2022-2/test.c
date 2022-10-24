#include <stdio.h>
#include <stdlib.h>

int matchLotto(int lotto1[6], int lotto2[6]){
  int count = 0;
  for(int i = 0; i<6 ;i++){
    if(lotto1[i]==lotto2[i]){
      count++;
    }
  }
  return count;
}

int main(void) {
  int lotto_com[6];   // 컴퓨터가 만들어 낸 로또 번호
  int lotto_user[6];  // 사용자가 입력한 로또 번호
  int i;              // 반복문을 위한 변수
  int count;          // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
  int match_count;    // 일치하는 로또 번호의 갯수 (0~6) 

  
  for(i = 0; i<6; i++){
    lotto_com[i] = (int)rand() % 10;
    for(int j = 0; j<6; j++){
      if(lotto_com[i]==lotto_com[j]){
        i--;
      }
    }
  }


  printf("hello world\n");


  for(i = 0; i<6; i++){
    printf("원하는 %d번째 로또 숫자를 입력 ", i+1);
    scanf("%d", &lotto_user[i]);
    for(int j = 0; j<i; j++){
      if(lotto_user[i]==lotto_user[j]){
        printf("->잘못 입력");
        i--;
      }
    }
  }

  printf("이번주의 로또 당첨 번호는 ");
  for(i = 0; i<6; i++){
    printf("%d ", lotto_com[i]);
  }
  printf("\n");
  printf("일치하는 로또 번호는 %d", matchLotto(lotto_com, lotto_user));
  return 0;
}