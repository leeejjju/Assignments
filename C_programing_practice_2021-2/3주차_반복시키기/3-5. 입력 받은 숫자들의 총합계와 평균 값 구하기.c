#include <stdio.h>

int main(void) {
 int number;     // �Է¹��� ��
 int count = 0;      // �Է¹��� ������ ����
 int totalsum = 0;   // �հ�
 float average = 0.00;  // ��� ��


  do{
    printf("0�ʰ��� ���ڸ� �Է��ϼ��� ");
    scanf("%d", &number);
    count ++;
    if(!(number < 0)){
      totalsum += number;
    }

  }while(number > 0);

  if(count-1 == 0){
    average = 0;
  }else{
    average = totalsum*1.000 / (count-1)*1.000;
  }

  

  printf("�Է��� %d���� ���ڵ��� ���հ�� %d�̰�, ��� ���� %.1f �Դϴ�.", count - 1, totalsum, average);

  return 0;
}
