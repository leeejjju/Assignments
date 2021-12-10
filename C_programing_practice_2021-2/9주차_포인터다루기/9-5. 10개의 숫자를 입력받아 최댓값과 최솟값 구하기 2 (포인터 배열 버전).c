#include <stdio.h>
/*9-2번 문제를 업데이트하라. 숫자를 10개 입력받은 후, 이 숫자 중에서 가장 큰 수, 가장 작은 수를 출력하라. 단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라. 아래의 maxMinOfTen() 함수를 제작하여 최댓값과 최솟값을 가져오도록 하라.*/

void maxMinOfTen(int number[10], int* maxmin[]);

int main(void) {

  int num[10];      // 10개의 숫자를 받을 배열
  int* max_min[2];  // 최댓값과 최솟값을 가리킬 포인터 배열 

  for(int i=0;i<10;i++){ //숫자 열개 입력받아 배열에 저장 
    printf("%d번째 숫자를 입력하시오. ", i+1);
    scanf("%d", &num[i]); 
  }

  maxMinOfTen(num, max_min); //최소최대값 찾아 배열에 저장 

  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", *(max_min[0]), *(max_min[1])); 

  return 0;
}

void maxMinOfTen(int number[10], int* maxmin[]){
  int i; 
  //*maxmin[0] = 0;
  //*maxmin[1] = 9999;
  int max = 0, min = 99999;

  for(i = 0; i < 10; i++){ //최대값 
    if(number[i] > max){
      max = number[i];
      maxmin[0] = &number[i]; //maxmin은 포인터변수기 때문에 max값 자체가 아닌 max값이 위치한 주소값을 담아야함. 그러므로 =max가 아닌 =&number[i]. 
    }
  }

  for(i = 0; i < 10; i++){ //최소값 
    if(number[i] < min){
      min = number[i];
      maxmin[1] = &number[i];
    }
  }
}
//파라미터 : 입력받은 숫자 배열(number), 최댓값과 최솟값의 포인터가 저장된 배열(mixmin)
//수행내용 : 받은 배열에서 가장 큰 수와 가장 작은 수를 찾아서 maxmin 포인터배열의 0,1번 포인터 변수에 주소를 저장함. maxmin[0] -> 최댓값의 포인터, maxmin[1] -> 최솟값의 포인터

