#include <stdio.h>
#include <stdlib.h>
/*어떤 식당의 메뉴판이 다음과 같이 구성되어 있을 때, 5개의 메뉴 정보를 입력받아 menu.txt 파일로 저장하라.

제공된 소스 main() 수정금지*/


struct st_menu{ 
    int no; 				// 메뉴번호
    char name[20]; 			// 메뉴명 
    char madein[20]; 		// 원산지 
    int price; 				// 가격 
};

struct st_menu* getMenu();
void saveMenu(struct st_menu* list[], char* filename, int size);

int main()
{
    struct st_menu* menu[10]; 	// 최대 10개의 메뉴 저장용 포인터 배열 
    for(int i=0;i<5;i++){
        printf("%d번째 메뉴\n",i+1);
        menu[i] = getMenu();
    }
    saveMenu(menu,"menu.txt",5);
    return 0;
}

struct st_menu* getMenu(){
  struct st_menu* p;
  p = malloc(sizeof(struct st_menu));

  printf("메뉴의 번호, 메뉴명, 원산지, 가격을 입력하라. > ");
  scanf("%d %s %s %d", &p->no, p->name, p->madein, &p->price);

  return p;
}
// 수행내용 : 메뉴정보 구조체를 동적 메모리 할당 후, 이곳에 메뉴 정보를 입력받아 저장한 후, 주소값 리턴함

void saveMenu(struct st_menu* list[], char* filename, int size){
  FILE* file;
  file = fopen(filename, "w");

  for(int i = 0; i < size; i++){
    fprintf(file, "%d %s %s %d\n", list[i]->no, list[i]->name, list[i]->madein, list[i]->price);
  }

  fclose(file);
  printf("menu.txt에 저장했습니다.\n");
}
// 파라미터 : 메뉴 목록, 저장할 파일명, 메뉴 갯수
// 리턴값 : 없음 
