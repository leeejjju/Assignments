#include <stdio.h>

int main(void) {
  int income;     // ���� (�� ����) 
  int tax;        // �ҵ漼 (�� ����)

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
