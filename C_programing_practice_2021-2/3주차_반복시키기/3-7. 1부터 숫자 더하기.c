#include <stdio.h>

int main(void) {
  int number;       // �Է¹��� �� 
  int totalsum = 0;     // 1���� ���� ��� ��� �� 
  int i;            // �ݺ��� ����� ���� ���� 

  printf("���ڸ� �Է��ϼ���. ");
  scanf("%d", &number);

  if(number > 1){

    for(i = 1; i <= number; i++){
      totalsum += i;
    }

    printf("1���� �Է��� ���ڱ����� ��� ������ ���� ���� %d �Դϴ�.", totalsum );

  }else{
    printf("�߸� �Է��Ͽ����ϴ�.");
  }


  return 0;
}

