#include <stdio.h>

int main(void) {
  int income;     // 연봉 (원 단위) 
  int tax;        // 소득세 (원 단위)

  printf("income? ");
  scanf("%d", &income);

  if(income >= 80000000){
    tax = income * 0.37;
  }else if(income >= 40000000){
    tax = income * 0.28;
  }else if(income >= 10000000){
    tax = income * 0.19;
  }else{
    tax = income * 0.095;
  }


  printf("tax is %d.", tax);

  return 0;
}
