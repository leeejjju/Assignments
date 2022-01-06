#include <stdio.h>
/*어떤 식당의 메뉴판의 구조가 다음과 같이 구성되어 있을 때, 이 메뉴판의 메뉴 정보를 구조체로 선언하고, 5개의 메뉴 정보를 입력받아 이를 5개의 구조체 배열에 저장한 후,

메뉴내용을 화면에 출력하고, 이 내용을 menu.txt 에 저장하라.*/
/*
1. 입력받아 구조체에 저장, 파일에 출력
2. 구조체 출력 
*/

struct menu{ 
  int no; // 메뉴번호
  char name[20];  // 메뉴명 
  int price; // 가격 
};

int main(void) {
  struct menu mymenu[5]; 

  FILE* file;
  file = fopen("menu.txt", "w");

  for(int i = 0; i < 5; i++){
    printf("%d번째 메뉴의 번호, 메뉴명, 가격을 입력. ", i+1);
    scanf("%d %s %d", &mymenu[i].no, mymenu[i].name, &mymenu[i].price);
    fprintf(file, "%d %s %d\n", mymenu[i].no, mymenu[i].name, mymenu[i].price);
  }

  fclose(file);

  printf("메뉴번호 메뉴이름 1인분가격\n");
  for(int i = 0; i < 5; i++){
    printf("%4d %12s %8d\n", mymenu[i].no, mymenu[i].name, mymenu[i].price);
  }

  //printf("안녕하세용 ");

  return 0;
}
