#include <stdio.h>
/*

(10+a회 반복){
  입력안내문
  입력받기

  방금 입력받은게 지금까지 입력됐던것들 중 중복되지 않는지 검사,
  중복되는게 있을시 중복변수를 1로 설정

  중복변수가 1일시 해당 인덱스를 다시 입력받기, 중복변수 0으로 바꾸기 

}

*/

int main(void) {
  
  int number[10] = {0,};     // 사용자가 입력한 숫자 10개
  int count = 0;          // 현재까지 입력된 숫자의 갯수(0~10)
  int i, j, joongbok = 0;              // 반복문을 위한 변수

  printf("1부터 100사이의 숫자를 입력하시오.\n");

  for(i = 0; i < 10; i++){
    printf("%d번째 숫자를 입력하시오. ", i+1);
    scanf("%d", &number[i]);
    count ++;
    joongbok = 0;

    if(i != 0){
      for(j = 0; j < i; j++){ //입력값이 중복인지 검사 
        if(number[i] == number[j]){ //i는 방금 입력한 인덱스, j는 이전까지의 인덱스들 
          joongbok = 1;
        }
      }
    }


    if( joongbok == 1){ //방금 입력한놈이 중복이라면 
      printf("잘못 입력하였습니다. 다시 입력하세요.\n");
      i --; //뒤로가기..? 입력 다시받기 
    }

  }

  for(i = 0; i < 10; i++){
    printf("%d번째 숫자는 %d입니다.\n", i+1, number[i]);
  }

  return 0;
}

