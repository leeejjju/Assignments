#include <stdio.h>
/*숫자를 10개 입력받은 후, 이 숫자 중에서 가장 큰 수, 가장 작은 수를 출력하라.

함수를 사용하여 최댓값을 반환하는 함수와 최솟값을 반환하는 함수를 각각 만들어라.

함수 원형은 다음과 같다.

int maxOfTen(int number[10]);
파라미터 : 입력받은 숫자 배열(number)
리턴값 : 가장 큰 값
수행내용 : 받은 배열에서 가장 큰 수를 찾아서 메인에게 리턴

int minOfTen(int number[10]);
파라미터 : 입력받은 숫자 배열(number)
리턴값 : 가장 작은 값
수행내용 : 받은 배열에서 가장 작은 수를 찾아서 메인에게 리턴*/

int maxOfTen(int number[10]){
  int i;
  int max_num;
  for(i = 0; i < 10; i++){
    if(number[i] > max_num){
      max_num = number[i];
    }
  }
  return max_num;
}

int minOfTen(int number[10]){
  int i;
  int min_num;
  for(i = 0; i < 10; i++){
    if(number[i] < min_num){
      min_num = number[i];
    }
  }
  return min_num;
}



int main(void) {
  int number[10]={0};
  //int max=-10000,min=100000;

  for(int i=0;i<10;i++){
    printf("%d번째 숫자를 입력하시오. ",i+1);
    scanf("%d",&number[i]);
  }
  /*
  for(int i=0;i<10;i++){
    if(number[i]>max) max=number[i];
    if(min>number[i]) min = number[i];
  }
  */
  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.",maxOfTen(number) ,minOfTen(number));


  return 0;
}



