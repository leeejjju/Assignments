#include <stdio.h>

int main(void) {
  int birth_year;   // �¾ �⵵ 
  int age;          // ���� 

  printf("Birth year? ");
  scanf("%d", &birth_year);

  age = 2019 - birth_year + 1;

  if(age >= 60){
    printf("����Դϴ�.");
  }else if(age >= 30){
    printf("�߳��Դϴ�.");
  }else if(age >= 20){
    printf("û���Դϴ�.");
  }else if(age >= 13){
    printf("û�ҳ��Դϴ�. ");
  }else if(age >= 7){
    printf("����Դϴ�.");
  }else{
    printf("�����Դϴ�.");
  }
  return 0;
}
