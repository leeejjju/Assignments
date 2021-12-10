#include<stdio.h>
#include <string.h>
/*사람의 firstname, lastname, birthyear 을 입력받은 후, strcat() 함수를 사용하여 "연령대 firstname lastname"으로 이루어진 인적사항 문자열 출력 하라.

단, 연령대를 표현하는 단어는 다음과 같이 정한다.

20세 미만 [Youth]
20~40세 미만 [Junior]
40~65세 미만 [Senior]
65세 이상 [Silver]*/


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



  printf("결과 : %s %s %s", age_group[a], firstname, lastname);



  


  return 0;
}
