/*1101코딩T_01)_22100579
1. 두 개의 시간 값이 주어졌을 때, 그 간격이 몇분인지 산출하는 프로그램을 작성하시오. 
(단 입력에서 두개의 시간 중 반드시 큰 값이 뒤에 입력됨을 가정)*/

#include <stdio.h>

int main(void){
  int h1, h2, m1, m2;//시간과 분을 입력받을 어쩌구 
  int sum = 0; //분의 차이값을 누적할 공간 
  int i; //반복문용 

  scanf("%d %d", &h1, &m1);
  scanf("%d %d", &h2, &m2); //얘가 더 큰 값 

  if(h2 > h1){
    sum += (h2 - h1)*60; 
  }

  if(m2 > m1){
    sum += (m2 - m1);
  }

  printf("%d", sum);

  

  return 0;
}
