#include <stdio.h>
 
int main(void) {
  int rows, columns;  // ���� ����, ���� ����
  int number;         // �� ĭ�� ����ϴ� ��
  int i, j;           // �ݺ��� ����� ���� ����

  printf("rows? ");
  scanf("%d", &rows);
  printf("columns? ");
  scanf("%d", &columns);

  for(i = 1; i <= rows; i++){
    for(j = 1; j <= columns; j++){
        printf("%-3d", i*j);
    }
      printf("\n");
  }


  return 0;
}

