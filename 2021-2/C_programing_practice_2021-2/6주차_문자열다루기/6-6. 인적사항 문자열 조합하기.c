#include<stdio.h>
#include <string.h>
/*����� firstname, lastname, birthyear �� �Է¹��� ��, strcat() �Լ��� ����Ͽ� "���ɴ� firstname lastname"���� �̷���� �������� ���ڿ� ��� �϶�.

��, ���ɴ븦 ǥ���ϴ� �ܾ�� ������ ���� ���Ѵ�.

20�� �̸� [Youth]
20~40�� �̸� [Junior]
40~65�� �̸� [Senior]
65�� �̻� [Silver]*/


int main(void){

  char firstname[30];
  char lastname[30];
  char age_group[4][30] = {"[Youth]","[Junior]","[Senior]","[Silver]"}; 
  int birthyear;
  int age, a;

  printf("Firstname? ");
  scanf("%s", firstname);

  printf("Lastname? ");
  scanf("%s", lastname);

  printf("Birthyear? ");
  scanf("%d", &birthyear);

  age = 2021 - birthyear + 1;

  if(age < 20){
    a = 0;
  }else if(age < 40){
    a = 1;
  }else if(age < 65){
    a = 2;
  }else{
    a = 3;
  }



  printf("��� : %s %s %s", age_group[a], firstname, lastname);



  


  return 0;
}
