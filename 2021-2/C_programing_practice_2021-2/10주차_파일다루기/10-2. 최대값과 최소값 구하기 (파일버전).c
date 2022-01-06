#include <stdio.h>
/*데이터 파일로부터 숫자를 10개 입력받은 후, 이 숫자 중에서 가장 큰 수, 가장 작은 수를 출력하라.

단, 다음과 같은 MaxMinOfTen() 함수를 사용하여 최댓값과 최솟값을 저장하도록 함수를 만들어라.*/

void maxMinOfTen(int number[10], int* max, int* min);

int main(void) { 
  int num[10];    // 10개의 숫자를 받을 배열
  int max_num;    // 가장 큰 숫자를 리턴 받을 변수,
  int min_num;    // 가장 작은 숫자를 리턴 받을 변수
  char file[20];  // 파일 이름
  FILE* data;
  // 이 곳에 코드를 작성하라.

  printf("파일 이름을 입력하세요. ");
  scanf("%s", file); //원하는 파일명 받기 

  data = fopen(file, "r"); //해당 파일 열기 
  for(int i = 0; i < 10; i++){ //파일속 상수들을 배열에 저장하기 
    fscanf(data, "%d", &num[i]);
  }

  maxMinOfTen(num, &max_num, &min_num); //최대최소 찾아 저장하는 함수 실행 

  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num); 
  fclose(data);//파일 닫기 

  return 0; 
}

void maxMinOfTen(int number[10], int* max, int* min){
  *max = *min = number[0]; //초기화 
  
  for(int i = 0; i < 10; i++){
    if( *max < number[i]){
      *max = number[i];
    }
    if( *min > number[i]){
      *min = number[i];
    }
  }
}

//파라미터 : 입력받은 숫자 배열(number), 최댓값의 포인터(max), 최솟값의 포인터 (min)
//리턴값 : 없음
//수행내용 : 받은 배열에서 가장 큰 수와 가장 작은 수를 찾아서 max, min 포인터 변수에 저장함
