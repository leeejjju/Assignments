#include <stdio.h>

int main(void) {
  int height, weight;     // ����(cm), ü��(kg) 
  float bmi;              // �񸸵� ��ġ
  int people; 
  int i;            // ���� ����� �� 

  for(i = 0; i < 5; i++){
    printf("%d��° ����� ����(cm)�� ü��(kg)�� �Է��Ͻÿ�. ", i+1);
    scanf("%d %d", &height, &weight);

    bmi = weight / (height * height * 0.0001);
    if(bmi >= 25){
      people ++;
    }
  }

  printf("���� ����� �� %d���Դϴ�.", people);
  
  return 0;
}
