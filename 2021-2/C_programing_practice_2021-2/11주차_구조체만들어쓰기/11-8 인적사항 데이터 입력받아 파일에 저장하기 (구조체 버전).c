#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*구조체를 이용하여 3명의 데이터를 입력받아 이를 한꺼번에 출력하라.
단, 3명의 데이터를 입력받기 위해 구조체 변수 3개를 임의로 선언하여 사용하라.*/

struct st_person{
  char name[20];
  char address[80];
  int age;
}; 

int main(void) {
  struct st_person p[3]; //인적사항을 받아 저장할 구조체 배열
  char num[3][10] = {"첫", "두", "세"};

  for(int i = 0; i < 3; i++){
    printf("%s 번째 사람 인적사항을 입력하시오.", num[i]);
    printf("\n이름은? ");
    scanf("%s", p[i].name);
    printf("주소는? ");
    getchar(); //앞에서 친 엔터가 뒤에 입력되지 않도록 받아줌 
    //scanf("%s", p[i].address);
    fgets(p[i].address, 80, stdin);
    p[i].address[strlen(p[i].address)-1] = '\0'; //같이 입력된 마지막 엔터 제거 
    printf("나이는? ");
    scanf("%d", &p[i].age); 
  }

  for(int i = 0; i < 3; i++){
    printf("%s 번째 사람 : %s/ %s/ %d\n", num[i], p[i].name, p[i].address, p[i].age);

  }

  return 0;
}

