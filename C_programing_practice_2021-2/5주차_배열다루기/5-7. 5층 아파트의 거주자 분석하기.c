#include <stdio.h>

int main(void) {
  
  int number[5][3];       // �� ���� ������ ��
  int floor_total[5] = {0,};     // ���� ������ �հ� (1��, 2��, 3��, 4��, 5��)
  int line_total[3] = {0,};      // ȣ���� ������ �հ� (1ȣ����, 2ȣ����, 3ȣ����)
  int total = 0;              // ����Ʈ�� �� ������ ��
  int ho =101;                 // ����Ʈ ȣ�� ��Ÿ���� ����
  int i, j;               // �ݺ��� ����� ���� ���� 

  for(i = 0; i < 5; i++){ //���� ���� 

    for(j = 0; j < 3; j++){ //ȣ���� ����� �Է¹ޱ� 
      printf("%d0%dȣ�� ��� �ִ� ����� ��? ", i+1, j+1 );
      scanf("%d", &number[i][j]);

      floor_total[i] += number[i][j]; //���� ������ �հ�

      if(j == 0){ // ���κ� ������ �հ� 
        line_total[0] += number[i][j];
      }else if(j == 1){
        line_total[1] += number[i][j];
      }else{
        line_total[2] += number[i][j];
      }

      total += number[i][j];

    }

  }

  for(i = 0; i < 5; i++){ //���� ����� ��� 
    printf("%d���� ��� �ִ� ����� �� %d��\n", i+1, floor_total[i]);
  }

  for(i = 0; i < 3; i++){ //���κ� ����� ��� 
    printf("\n%dȣ���ο� ��� �ִ� ����� �� %d��", i+1, line_total[i]);

  }


  printf("\n\n�� ����Ʈ�� ��� ��� ��� %d��", total);

  return 0;
}

