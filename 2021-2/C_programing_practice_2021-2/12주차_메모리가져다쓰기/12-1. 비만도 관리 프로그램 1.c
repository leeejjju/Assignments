#include <stdio.h>
#include <stdlib.h>
/*비만 판정 함수버전에서 키와 몸무게 데이터를 입력받아 비만도 데이터를 완성하여 출력하라.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
이 때, 신장은 미터 단위로 환산해야 함을 유의 하라.

비만도 수치에 따른 비만도 판정
18.5 미만 : 저체중
18.5 ~ 23 미만 : 정상체중
23~25미만 : 과체중
25이상 : 비만

단, main에서는 다음과 같이 구조체 포인터만을 사용하고, addBmi()를 통해 메모리가 할당되도록 해야 한다.
main() 코드는 이미 제공되니 수정하지 말 것!
*/

struct st_bmi{
  int height, weight; // 키(cm), 몸무게(kg)
  float bmi; // 비만도
  int bmi_index; // 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

struct st_bmi* addBmi();
void evalBmi(struct st_bmi* p);

int main(void) {
  struct st_bmi* one;
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};

	one = addBmi();

	printf("키: %d ", one->height);
	printf("몸무게: %d ", one->weight);
	printf("비만도: %.1f ", one->bmi);    
    printf("판정결과 : %s\n", bmi_string[one->bmi_index-1]);
	return 0;
}

//-------------------------------------------------

struct st_bmi* addBmi(){
  struct st_bmi* p = (struct st_bmi*)malloc(sizeof(struct st_bmi));
  printf("키와 몸무게를 입력하시오 > ");
  scanf("%d %d", &(p->height), &(p->weight));
  evalBmi(p);
  return p;
}
// 파라미터 : 없음
// 리턴값 : 메모리 할당받아 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 포인터

void evalBmi(struct st_bmi* p){
  p->bmi = (p->weight)/((p->height)*(p->height)*0.01*0.01);
  if(p->bmi < 18.5){
    p->bmi_index = 1;
  }else if(p->bmi < 23){
    p->bmi_index = 2;
  }else if(p->bmi < 25){
    p->bmi_index = 3;
  }else{
    p->bmi_index = 4;
  }
	
}
// 파라미터 : 비만도 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장

