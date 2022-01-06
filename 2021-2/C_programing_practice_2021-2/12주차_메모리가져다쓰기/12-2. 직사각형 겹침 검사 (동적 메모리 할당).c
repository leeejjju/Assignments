#include <stdio.h>
#include <stdlib.h>
/*구조체를 이용하여 직사각형 2개의 좌상점의 좌표값(x, y)와 우하점의 좌표값(x, y)을 입력받은 후에 2개의 직사각형이 평면좌표 상에서 겹치는 부분이 있는지의 여부를 출력하라.

단, 각 직사각형의 좌상점과 우하점의 좌표를 입력받는 함수를 제작하여 사용하라. 이 함수에서 실제 메모리를 할당하는 작업이 진행되어야 한다.

또한 2개의 직사각형이 겹치는지 검사하는 다음 함수를 별도로 만들어 사용하라.*/

struct rectangle{ 
 int x1, y1; 		// 좌상점 좌표값 (왼쪽 위 모서리) 
 int x2, y2; 		// 우하점 좌표값 (오른 아래 모서리) 
}; 

struct rectangle* getPoints();	// 구조체 메모리를 할당받아 좌표를 입력받은 후 주소값 리턴

int checkOverlap(struct rectangle* r1, struct rectangle* r2); // 겹치면 1리턴, 아니면 0리턴

//main() 함수의 코드는 다음과 같다. (수정 금지!)
int main(){
	struct rectangle* rect1;  	// 첫 번째 직사각형을 위한 구조체 포인터
	struct rectangle* rect2;  	// 첫 번째 직사각형을 위한 구조체 포인터
	printf("직사각형 #1\n");
	rect1 = getPoints();
	printf("직사각형 #2\n");
	rect2 = getPoints();
	if (checkOverlap(rect1, rect2)) 
		printf("두 직사각형은 겹칩니다.\n");
	else
		printf("두 직사각형은 겹치지 않습니다.\n");
	return 0;
}

struct rectangle* getPoints(){
  struct rectangle* p;
  p = malloc(sizeof(struct rectangle));
  printf("좌상점 좌표값(x, y)? ");
  scanf("%d %d", &p->x1, &p->y1);
  printf("우하점 좌표값(x, y)? ");
  scanf("%d %d", &p->x2, &p->y2);
  return p;
}
// 구조체 메모리를 할당받아 좌표를 입력받은 후 주소값 리턴

int checkOverlap(struct rectangle* r1, struct rectangle* r2){
  if((r2->y2 >= r1->y1)||(r2->y1 <= r1->y2)){
    return 0;
  }else if((r2->x1 >= r1->x2)||(r2->x2 <= r1->x1)){
    return 0;
  }else{
    return 1;
  }
}
// 겹치면 1리턴, 아니면 0리턴


