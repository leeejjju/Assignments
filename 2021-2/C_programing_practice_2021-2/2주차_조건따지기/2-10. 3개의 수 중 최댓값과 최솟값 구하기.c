#include <stdio.h>

int main(void) {
  int num1, num2, num3;   // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자 
  int max_num, min_num;   // 가장 큰 숫자, 가장 작은 숫자
  int i;

  printf("첫번째 숫자? ");
  scanf("%d", &num1);
  printf("두번째 숫자? ");
  scanf("%d", &num2);
  printf("세번째 숫자? ");
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

  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.", max_num, min_num);



  return 0;
}
