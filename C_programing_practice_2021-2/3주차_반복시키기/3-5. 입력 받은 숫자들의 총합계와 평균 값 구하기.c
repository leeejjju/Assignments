#include <stdio.h>

int main(void) {
 int number;     // 입력받은 수
 int count = 0;      // 입력받은 숫자의 개수
 int totalsum = 0;   // 합계
 float average = 0.00;  // 평균 값


  do{
    printf("0초과의 숫자를 입력하세요 ");
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

  

  printf("입력한 %d개의 숫자들의 총합계는 %d이고, 평균 값은 %.1f 입니다.", count - 1, totalsum, average);

  return 0;
}
