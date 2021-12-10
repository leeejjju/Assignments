#include <stdio.h>
 
int main(void) {
  int rows, columns;  // 행의 개수, 열의 개수
  int number;         // 각 칸에 출력하는 값
  int i, j;           // 반복문 사용을 위한 변수

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

