#include <stdio.h>

int main(void) {
  
  int num[10];                // 10���� ����
  int first = 0, first_max_index; // ù ��°�� ū ��
  int second = 0;                 // �� ��°�� ū ��
  int second_max_index;       // �� ��°�� ū ���� �ε��� 
  int i;                      // �ݺ����� ���� ����

  for(i = 0; i < 10; i++){ //�Է¹޾� �����ϱ�, ���� ū �� ã�Ƶα� 
    printf("%d��° ���� �Է��Ͻÿ�. ", i+1);
    scanf("%d", &num[i]);

    if(first < num[i]){
      first = num[i];
      first_max_index = i;
    }

  } 

  for(i = 0; i < 10; i++){ //�Ʊ��� �ִ밪 �����ϰ� ���� ū �� ã�� 
    if(i != first_max_index){
      if(second < num[i]){
      second = num[i];
      second_max_index = i+1;
      }
    }
  }

  printf("�ι�°�� ū ���� %d��° �� %d�Դϴ�.", second_max_index, second);

  return 0;
}
