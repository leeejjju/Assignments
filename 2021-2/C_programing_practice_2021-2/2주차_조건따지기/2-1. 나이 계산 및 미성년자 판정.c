#include <stdio.h>

int main(void) {
  int birth_year;  // �¾ �⵵
  int age;         // ���� 

printf("Birth year? ");
scanf("%d", &birth_year);
age = 2021 - birth_year + 1;

if(age < 20){
  printf("�̼������Դϴ�.");
}else{
  printf("�̼����ڰ� �ƴմϴ�.");
}

  return 0;
}

