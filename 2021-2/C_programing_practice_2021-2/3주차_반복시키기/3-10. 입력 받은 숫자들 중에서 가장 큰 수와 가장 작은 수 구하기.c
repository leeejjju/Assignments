#include <stdio.h>

int main(void) {
  int number;             // �Է¹��� �� 
  int max_num = 0, min_num = 100;   // ���� ū ����, ���� ���� ���� 

 
  while(1){

  printf("0���� 100 ������ ���ڸ� �Է� ");
  scanf("%d", &number);

    if(number > 100 || number < 0){
      break;
    }

  if(max_num < number){
    max_num = number;
  }

  if(min_num > number){
    min_num = number;
  }

  }

  printf("�Էµ� ���ڵ� �� ���� ū���� %d�̰�,\n���� ���� ���� %d�Դϴ�.", max_num, min_num);
  return 0;
}
