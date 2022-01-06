#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*10-10 문제에서 업그레이드를 진행하라. main()함수 코드는 수정하지 말 것!

주요내용 : bingo 완성여부를 검사할 때에 대각선으로 채워진 빙고의 경우도 검사할 수 있도록 한다. */

int markBingo(int num, int b[25]);
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 
//       마크 안되어 마크하였는데 빙고 완성됨 1,  
//       마크 안되어 마크하였는데 빙고는 미완성 -1,  
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는
//         칸 검사한 후 마크함
void shuffleBingo(int b[25]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음
//수행내용 : 현재의 빙고매트릭스의 원소들을 무작위로 섞는다.
//섞는 방법은 임의로 두개의 칸을 골라서, 두 칸의 값을 맞바꾸는 작업을 50번 정도 수행하면 된다.

void printBingo(int b[25]);
// 완성 코드 제시됨

int main(void) {
	int bingo[25]; // 빙고용 매트릭스
	int count=0; // 시도 횟수 
	int number; // 입력받는 번호 
	int check; // 빙고검사결과값 
	int i;

	srand(time(0)); // 랜덤 초기화 

	// 빙고매트릭스 초기화(1부터 25까지 순서대로 넣음)
	for(i=0;i<25;i++) bingo[i]= i+1;

	shuffleBingo(bingo);  // 빙고 매트릭스 섞기 
	printBingo(bingo); // 빙고 매트릭스 출력 
	while(1){
		printf("Enter a number(1~25) > ");
		scanf("%d", &number);
		if((number<1||number>25)){  
      printf("EXIT");
      break;
    }
		else {
			check = markBingo(number, bingo);
			if(check!=0) count++;
			if(check==1) break;
		}
	}
	printBingo(bingo); // 빙고 매트릭스 출력 
	printf("%d번 시도됨!\n", count);
	return 0;

}

int markBingo(int num, int b[25]){ //입력한 수로 마크하고 빙고체크 
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
}
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 
//       마크 안되어 마크하였는데 빙고 완성됨 1,  
//       마크 안되어 마크하였는데 빙고는 미완성 -1,  
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는
//          칸 검사한 후 마크함
//이 함수에서 출력할 내용
//- 빙고! ?번째 줄 // 특정 행이 모두 채워짐!   
//- 빙고! ?번째 칸 // 특정 열이 모두 채워짐!
//- 빙고! 대각선   // 대각선이 모두 채워짐!
//- 중복!        // 이미 0으로 마크된 칸임  


void shuffleBingo(int b[25]){ //빙고판 쓰까묵기 
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
//수행내용 : 현재의 빙고매트릭스의 원소들을 무작위로 섞는다.
//섞는 방법은 임의로 두개의 칸을 골라서, 두 칸의 값을 맞바꾸는 작업을 50번 정도 수행하면 된다.


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
