#include <stdio.h>
#include <string.h>
#include <math.h>
/*10명의 신장(cm단위)과 체중(kg단위)를 입력받으면서 askBiman() 함수를 통해 이들이 비만도를 출력하고 다음 기준에 따라 비만여부를 판정하여 출력하라.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
이 때, 신장은 미터 단위로 환산해야 함을 유의 하라.

비만도 수치에 따른 비만도 판정

18.5 미만 : 저체중
18.5 ~ 23 미만 : 정상체중
23~25미만 : 과체중
25~30미만 : 경도비만
30이상 : 고도비만

int askBiman(int height, int weight);
파라미터) height : 신장(cm), weight : 체중(kg)
수행내용) 비만도 계산 후 판정결과 리턴
리턴값) 저체중 0, 정상체중 1, 과체중 2, 경도비만 3, 고도비만 4*/

int askBiman(height, weight){
  float bmi = weight / pow(height * 0.01, 2); //비만도 측정 위한 bmi 
  int bimando; //비만도 구간 

  if(bmi < 18.5){ //저체중
    bimando = 0;
  }else if(bmi < 23){ //정상체중
    bimando = 1;
  }else if(bmi < 25){ //과체중
    bimando = 2;
  }else if(bmi < 30){ //경도비만
    bimando = 3;
  }else{ //고도비만 
    bimando = 4;
  }

  return bimando;

}

int main(void) {
  int height, weight; // 신장(cm), 체중(kg)
  int i; //반복문을 위한 변수 
  char bimando [5][100] = {"저체중", "정상", "과체중", "경도비만", "고도비만"};

  for(i = 0; i < 10; i++){
    printf("%d번째 사람 신장과 체중? ", i+1);
    scanf("%d %d", &height, &weight);
    if(height < 0 || weight < 0){
      printf("잘못 입력하셨습니다.\n");
    }else{
      printf("%s\n", bimando[askBiman(height, weight)]);
    }

  }


  
  return 0;
}
