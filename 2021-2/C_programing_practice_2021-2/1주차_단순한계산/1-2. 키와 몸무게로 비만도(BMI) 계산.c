#include <stdio.h>



int main(void) {

  int height, weight; // ����(cm), ü��(kg) 
  float bmi; // �񸸵� ��ġ 
  
  printf("height? ");
  scanf("%d", &height);
  printf("weight? ");
  scanf("%d", &weight);

  bmi = weight / ((height * 0.01) * (height * 0.01) );

  printf("Your bmi is %.1f", bmi);
  //�񸸵� ��ġ = ü��(kg) / (����(m)�� ����)

  return 0;
}
