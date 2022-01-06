#include <stdio.h>
#include <stdlib.h>

/*어떤 식당의 메뉴판의 구조가 다음과 같이 구성되어 있을 때, 1개의 메뉴 정보를 구조체 포인터로 선언하고, 함수를 통해 정보를 입력받아 출력하라.*/

struct st_menu{ 
 int no; 				// 메뉴번호
 char name[20]; 			// 메뉴명 
 char madein[20]; 			// 원산지 
 int price; 				// 가격 
};

struct st_menu* getMenu();


int main(void) {
  struct st_menu *menu; 	// 메뉴 구조체 포인터

  menu = getMenu();

  printf("메뉴번호 메뉴이름 원산지 1인분가격\n");
  printf("   %d    %s %s   %d", menu->no, menu->name, menu->madein, menu->price);

  return 0;
}

struct st_menu* getMenu(){
  struct st_menu* p = malloc(sizeof(struct st_menu));

  printf("메뉴번호, 메뉴명, 원산지, 가격을 입력하라. > ");
  scanf("%d %s %s %d", &p->no, p->name, p->madein, &p->price);

  return p;
}
// 수행내용 : 메뉴정보 구조체를 동적 메모리 할당 후, 이곳에 메뉴 정보를 입력받아 저장한 후, 주소값 리턴함
