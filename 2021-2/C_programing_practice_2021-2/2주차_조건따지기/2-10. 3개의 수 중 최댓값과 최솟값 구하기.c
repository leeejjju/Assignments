#include <stdio.h>

int main(void) {
  int num1, num2, num3;   // ù ��° ����, �� ��° ����, �� ��° ���� 
  int max_num, min_num;   // ���� ū ����, ���� ���� ����
  int i;

  printf("ù��° ����? ");
  scanf("%d", &num1);
  printf("�ι�° ����? ");
  scanf("%d", &num2);
  printf("����° ����? ");
  scanf("%d", &num3);


  int array[3] = {num1, num2, num3};

  for(i = 0; i < 3; i++){
    if(array[i] > max_num){
      max_num = array[i];
    }
  }


  for(i = 0; i < 3; i++){
    if(array[i] < min_num){
      min_num = array[i];
    }
  }



  //printf("%d, %d, %d\n", array[0], array[1], array[2]);

  printf("���� ū ���� %d�̰�, ���� ���� ���� %d�Դϴ�.", max_num, min_num);



  return 0;
}
