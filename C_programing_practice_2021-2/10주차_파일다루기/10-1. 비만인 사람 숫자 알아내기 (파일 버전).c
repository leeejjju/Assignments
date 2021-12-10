#include <stdio.h>
/*데이터 파일로부터 5명의 신장(cm단위)과 체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라. 단, 비만여부는 다음 비만도 수치가 25 이상인 경우에 "비만"으로 판단한다.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

비만도 계산 기능을 수행하는 함수를 작성하여 사용할 것.*/
float evalBmi(int h, int w);

int main(void) {
  float height, weight, bmi;
  int count=0;
  // 이 곳에 코드를 작성하라.
  FILE* file; //파일핸들러 가져오기 
  file = fopen("data.txt", "r"); //읽기모드로 파일 열기

  for(int i = 0; i < 5; i++){
    fscanf(file, "%f", &height);
    fscanf(file, "%f", &weight);

    printf("%d번째 사람의 신장(cm)과 체중(kg): %.0f %.0f\n", i+1, height, weight);

    if(evalBmi(height, weight) >= 25){
      count ++;
    }
  }

  fclose(file); //파일 닫기


  printf("비만인 사람은 %d명입니다.\n", count); 
  return 0;
}

float evalBmi(int h, int w){
  float mh = h*0.01;
  float bmi = w /(mh* mh);
  
  return bmi;
}

//파라미터 : h : 신장(cm 단위), w : 체중(kg 단위)
//리턴값 : 비만도
//수행내용 : 파라미터로 받은 신장, 체중을 가지고 비만도를 계산하여 리턴함.
