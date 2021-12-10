#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*다음과 같이 입력받은 크기만큼의 '@' 문자를 10*10 정방형 공간 내의 임의의 위치에 출력하는 프로그램을 작성하라.

예를 들어 크기 5인 경우, 5개의 @를 100개의 공간(10줄, 10칸) 중 임의의 위치에 나타나도록 하는 것이다.

변수는 임의로 선언하여 사용하라.*/

//문자형배열은어케일괄초기화하나요?????

int main(void) {
  char block[10][10] = {}; //패턴이 들어갈 배열 
  int size; //@를 출력할 크기 
  int ran[size]; //@가 출력될 랜덤 위치(0~99)
  int i, j; //반복을 위한 변수 


  for(i = 0; i < 10; i++){ //배열 초기화 
    for(j = 0; j < 10; j++){
      block[i][j] = '+';
    }
  }


  srand(time(0)); //시드 리셋

  printf("Enter size >> ");
  scanf("%d", &size); 

  for(i = 0; i < size ; i++){
    ran[i] = rand()%98+1; //랜덤 위치 입력받기 
    block[ran[i]/10][ran[i]%10] = '@'; //해당 위치의 +를 @로 변경
  }

  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      printf("%c", block[i][j]);
    }
    printf("\n");
  }



	return 0;
}
