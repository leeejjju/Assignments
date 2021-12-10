#include <stdio.h>
/*5명의 신장(cm단위)과 체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라.

단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라.

신장과 체중의 입력은 bmiFromHW() 함수를 통해 진행하라.*/


float bmiFromHW(float* h, float* w);

int main(void) {
	float height, weight, bmi;
	int count=0;
	for(int i=0;i<5;i++){
		bmi = bmiFromHW(&height, &weight);
		if (bmi > 25) {
			printf("비만입니다. 키:%.2f미터 몸무게:%.1fkg\n",height, weight);
			count++;
		}
	}
	printf("비만인 사람은 %d명입니다.\n", count);
	return 0;
}

float bmiFromHW(float* h, float* w){
	float bmi, cmh;
  printf("신장(cm)과 체중(kg)을 입력하시오. ");
  scanf("%f %f", &cmh, w);
  *h = cmh * 0.01;
	bmi = *w / (*h * *h); 
	return bmi;
}

//파라미터 : 키(h)과 몸무게(w) 값을 저장할 변수의 포인터
//리턴값 : 계산된 bmi 지수
//수행내용 : 
//1. 키(cm)과 몸무게(kg)을 화면에서 입력받아 h포인터에 미터(float)로 환산한 키, w포인터에 몸무게 (float)값을 저장
//2. bmi 지수를 계산해서 리턴함
