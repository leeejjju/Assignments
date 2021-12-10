#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*구조체를 이용하여 3명의 데이터를 입력받아 이를 한꺼번에 출력하라.
단, 3명의 데이터를 입력받기 위해 다음과 같이 구조체 포인터 3개짜리 배열을 사용하라.
또 인적사항을 입력받는 다음 함수를 제작하여 사용하라.*/


struct st_person{
 char name[20];
 char address[80];
 int age;
}; 

struct st_person* getPerson();

int main(void) {
  struct st_person* p[3];

  //제공된 코드 ? main() 일부
  for(int i=0; i<3; i++){
    printf("#%d 인적사항을 입력하시오.\n",i+1);
    p[i] = getPerson();
  }

  for(int i=0; i<3; i++){
    printf("#%d : %s/ %s/ %d\n",i+1, p[i]->name, p[i]->address, p[i]->age);
  }

  return 0;
}

struct st_person* getPerson(){
  struct st_person* p = malloc(sizeof(struct st_person));

  printf("이름은? ");
  scanf("%s", p->name);
  printf("주소는? ");
  getchar();
  fgets(p->address, 80, stdin); //띄어쓰기 포함 입력받아야하니..
  p->address[strlen(p->address)-1] = '\0'; //마지막 엔터 지워주고 
  printf("나이는? ");
  scanf("%d", &p->age);

  return p;
}
// 메모리를 동적 할당하여 인적사항을 입력받아 저장한 후 포인터 리턴
