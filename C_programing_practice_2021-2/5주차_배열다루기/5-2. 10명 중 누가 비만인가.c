#include <stdio.h>

int main(void) {
  
  int height[10], weight[10];   // 10���� ����(cm), ü��(kg)
  float bmi[10];                // 10���� �񸸵� ��ġ
  int count = 0;                    // ���� ����� ����
  int i;                        // �ݺ����� ���� ���� 

  for(i = 0; i < 10; i++){
    printf("%d��° ����� ����� ü��? ", i+1);
    scanf("%d %d", &height[i], &weight[i]);

    bmi[i] = weight[i]/(height[i]*height[i]*0.0001);
  }

  for(i = 0; i < 10; i++){
    if(bmi[i] >= 25){
      printf("%d��° ����� ��\n", i+1);
      count++;
    }
  }

  printf("\n�� %d���� ����� ��", count);

  return 0;
}
