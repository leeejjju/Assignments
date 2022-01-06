#include <stdio.h>
/*5���� ����(cm����)�� ü��(kg����)�� �Է¹޾� �� �߿��� ���� ����� ���ڸ� �ľ��Ͽ� ����϶�.

��, ������ main() �Լ� �ڵ带 �������� �Լ� ���븸 �ۼ��϶�. ����� ü���� �Է��� askHW() �Լ��� ���� ���� �϶�.*/

void askHW(float* h, float* w);

int main(void) {

  float height, weight, bmi; 
  int count=0;

  for(int i=0;i<5;i++){
    askHW(&height, &weight);
    bmi = weight / (height*height); 
    if (bmi > 25){
      count++;
    }
  }
  printf("���� ����� %d���Դϴ�.\n", count); 
  return 0;
}

void askHW(float* h, float* w){ // Ű(cm)�� ������(kg)�� ȭ�鿡�� �Է¹޾� h�����Ϳ� ����(float)�� ȯ���� Ű, w�����Ϳ� ������ (float)�� �� ����
  static int count = 0; //���° �Է����� 
  float cmh;
  printf("%d��° ����� ����(cm)�� ü��(kg)�� �Է��Ͻÿ�. ", count+1);
  scanf("%f %f", &cmh, w);
  *h = cmh * 0.01;

  count ++;
  return;
}
