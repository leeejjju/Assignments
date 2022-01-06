#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*상품권에 사용할 랜덤 코드 10개를 만들려고 한다. 코드 형식은 다음과 같다.

@@@-###### -> 3자리의 알파벳 대문자 - 6자리의 숫자

단, 6자리의 숫자의 처음 자리에 0이 들어가면 안된다.

이런 형식의 코드 10개를 만들어 다음과 같이 화면에 출력하라.*/

int main(void) {
	srand(time(0));
	char code[10][20];//코드를 저장할 배열 
  int i, j; //반복문 실행을 위한 변수 

  for(i = 0; i < 10; i++){ //랜덤한 코드 생성
    for(j = 0; j < 3; j++){
      code[i][j] = 65+ rand()%26 ; //알파벳 대문자 
    }
    code[i][3] = '-';
    for(j = 4; j < 10 ; j++){
      code[i][j] = 48 + rand()%10; //숫자코드 
    }
    while(j < 20){
      code[i][j] = '\0'; //나머지를 null로 채우기 
      j++;
    }
  }

  printf("10개의 코드가 생성되었습니다.\n");

  for(i = 0; i < 10; i++){ //생성된 코드 출력 
    printf("Code #%d : ", i+1);
    printf("%s\n", code[i]);
  }
	return 0;
}


