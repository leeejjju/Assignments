#include <stdio.h>
/*구조체를 사용하여 데이터 파일로부터 5명의 신장(cm단위)과 체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라.

단, 비만여부는 다음 비만도 수치가 25이상인 경우에 "비만"으로 판단한다.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

비만도계산기능을 수행하는 함수를 작성하여 사용할 것.*/

struct st_bmi{
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_index; // 1,2,3,4
};

float evalbmi(int h, int w);

int main(void){
  struct st_bmi man;
  int r, i = 0, count = 0;

  FILE* file;
  file = fopen("data.txt", "r");

  while(!feof(file)){

    r = fscanf(file, "%d %d", &man.height, &man.weight);
    if(r == 2){
      printf("%d번째 사람의 신장(cm)과 체중(kg) : %d %d\n", i+1, man.height, man.weight);
      i++;
    }else{
      break;
    }
    man.bmi = evalbmi(man.height, man.weight);
    if(man.bmi >= 25){
      count ++;
    }

  }
  printf("비만인 사람은 %d명입니다.", count);

  return 0;
}

float evalbmi(int h, int w){
  float bmi;
  bmi = w/(h*h*0.01*0.01);
  return bmi;
}
//파라미터 : h : 신장(cm 단위), w : 체중(kg 단위)
//리턴값 : 비만도
//수행내용 : 파라미터로 받은 신장, 체중을 가지고 비만도를 계산하여 리턴

