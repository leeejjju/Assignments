#include <stdio.h>
/*5���� ����(cm����)�� ü��(kg����)�� �Է¹޾� �� �߿��� ���� ����� ���ڸ� �ľ��Ͽ� ����϶�.

��, ������ main() �Լ� �ڵ带 �������� �Լ� ���븸 �ۼ��϶�.

����� ü���� �Է��� bmiFromHW() �Լ��� ���� �����϶�.*/


float bmiFromHW(float* h, float* w);

int main(void) {
	float height, weight, bmi;
	int count=0;
	for(int i=0;i<5;i++){
		bmi = bmiFromHW(&height, &weight);
		if (bmi > 25) {
			printf("���Դϴ�. Ű:%.2f���� ������:%.1fkg\n",height, weight);
			count++;
		}
	}
	printf("���� ����� %d���Դϴ�.\n", count);
	return 0;
}

float bmiFromHW(float* h, float* w){
	float bmi, cmh;
  printf("����(cm)�� ü��(kg)�� �Է��Ͻÿ�. ");
  scanf("%f %f", &cmh, w);
  *h = cmh * 0.01;
	bmi = *w / (*h * *h); 
	return bmi;
}

//�Ķ���� : Ű(h)�� ������(w) ���� ������ ������ ������
//���ϰ� : ���� bmi ����
//���೻�� : 
//1. Ű(cm)�� ������(kg)�� ȭ�鿡�� �Է¹޾� h�����Ϳ� ����(float)�� ȯ���� Ű, w�����Ϳ� ������ (float)���� ����
//2. bmi ������ ����ؼ� ������
