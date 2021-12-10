//제공된 코드 main() 수정 금지
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*11-10 문제에서 업그레이드를 진행하라.

main()함수 코드는 수정하지 말 것!

주요내용 : bingo 배열의 값을 1부터 50까지의 숫자 중 임의로 선택된 25개로 채우되 임의의 순서를 사용하여 만든다. 즉 1부터 50까지의 숫자 중 같은 숫자가 2번 이상 들어가면 안된다. 이렇게 선택된 25개의 숫자만으로 빙고게임이 진행되도록 구현하라.
*/


int used[50]={0}; // 숫자 사용 여부 (0:미사용, 1:사용), 9번이 빙고에 사용되었으면 used[8]=1이 됨!
int markBingo(int num, int b[25]);
void shuffleBingo(int b[25]);
void printBingo(int b[25]);

int main(void) {
int bingo[25]; 		// 빙고용 매트릭스
	int count=0; 		// 시도 횟수 
	int number; 		// 입력받는 번호 
	int check; 			// 빙고검사결과값 
	srand(time(0)); 		// 랜덤 초기화 
	shuffleBingo(bingo);  	// 빙고 매트릭스 섞기

	while(1){
		printf("Enter a number(1~50) > ");
		scanf("%d", &number);
		if((number<1||number>50)) {
      printf("EXIT!"); 
      break;
    }
		else {
			check = markBingo(number, bingo);
			if(check==1 || check==-1) count++;
			if(check==1) break;
		}
	}
	printBingo(bingo); 	// 빙고 매트릭스 출력 
	printf("%d번 시도됨!\n", count);
	return 0;
}

int markBingo(int num, int b[25]){

  if(used[num] == 0){
    printf("없는 값!\n");
    return -2;
  }

    int hoBing = 1;
  int veBing = 1;
  int diagBing1 = 0, diagBing2 = 0;

  for(int i = 0; i < 25; i++){
    if( b[i] == num){
      b[i] = 0; //마크하기 
      //빙고검사 *i번째 배열은 i/5번째 줄 i%5번째 칸. 
      for(int j = 0; j < 25; j++){
        if(j/5 == i/5){ //행, 가로줄 검사 
          if(b[j] != 0){
            hoBing = 0;
          }
        }
        if(j%5 == i%5){ //열, 세로줄 검사 
          if(b[j] != 0){
            veBing = 0;
          }
        }
      }

      //여기에 대각선검사 두개 넣어야할듯
      if(i%6 == 0){ // \대각선의 가능성이 보이면 
        diagBing1 = 1; //초기값 1로 세팅(희망가지구시작)
        for(int j = 0; j < 25; j+=6){
          if(b[j] != 0){
            diagBing1 = 0; //하나라도 0이 아니면 0됨
          }
        }
      }else if(i%4 == 0){ // /대각선의 가능성이 보이면 
        diagBing2 = 1; //초기값 1로 세팅(희망가지구시작)
        for(int j = 4; j < 24; j+=4){
          if(b[j] != 0){
            diagBing2 = 0; //하나라도 0이 아니면 0됨
          }
        }
      }

      if (hoBing){
        printf("빙고! %d번째 줄\n", i/5+1);        
        return 1;

      }else if(veBing){
        printf("빙고! %d번째 칸\n", i%5+1);
        return 1;
        
      }else if(diagBing1 || diagBing2){
        printf("빙고! 대각선\n");
        return 1;
        
      }else{
        return -1;
      }
    }
  }
  printf("중복! \n");
	return 0;



return 0;
}
//1부터 50사이의 숫자 25개가 들어있다는 것을 염두에 두고 다음과 같이 동작하도록 구현하라.
//이 함수에서는 선택된 칸의 번호에 대해서 검사하고 마크(0으로 바꿈)하는 작업을 수행한 후, 빙고가 완성되었는지 확인하여 그 결과를 리턴 하는 작업을 수행한다.
//이때, 빙고가 완성되었다는 것은 5개 중 1개의 줄 또는 1개의 열에 해당되는 5개의 칸 또는 대각선이 모두 0으로 마크된 경우를 말한다.
//이 때, 선택된 25개 숫자를 확인하기 위해서 전역변수로 선언된 used[] 배열을 사용하라.

void shuffleBingo(int b[25]){
  int c = 0; //유효한 숫자가 몇개 들어갔는지 
  int i; //걍 시드변경용 

  while(c<25){ //50개중 임의의 25개 안겹치게 넣어주기... 
    srand(time(0)+i); //시드...바꿔주기...
    i++;
    b[c] = rand()%50+1;
    if(used[b[c]] == 0){ //안쓰여진거여야만 유효... 
      used[b[c]] = 1;
      c++;
    }
  }

  //근데 이래놓으면 섞을 필요가 있나? 일단 하라니까 함...  
  int x,y, temp;
	for(int i=0;i<50;i++){
		x = rand()%25;
		y = rand()%25;
		temp = b[x];
		b[x] = b[y];
		b[y] = temp;
	}

}
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음
//수행내용 : 현재의 빙고매트릭스 내에 1~50사이의 숫자 중 임의로 선택한 25개의 숫자들이 무작위로 들어가도록 만든다. 
//섞는 방법은 임의로 두개의 칸을 골라서, 두 칸의 값을 맞바꾸는 작업을 50번 정도 수행하면 된다. 
//이 때, 선택된 25개 숫자를 등록하기 위해서 전역변수로 선언된 used[] 배열을 사용하라.



void printBingo(int b[25]){
	int i;
	printf("BINGO MATRIX\n");
	for(i=0;i<25;i++){
		if(i%5==0) 
			printf("--------------------------\n|");
		printf(" %2d |",b[i]);
		if(i%5==4) printf("\n");
	}
	printf("--------------------------\n");
}
