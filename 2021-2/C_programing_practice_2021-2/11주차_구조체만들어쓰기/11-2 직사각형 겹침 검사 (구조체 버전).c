#include <stdio.h>
/*구조체를 이용하여 직사각형 2개의 좌상점의 좌표값(x, y)와 우하점의 좌표값(x, y)을 입력받은 후에 2개의 직사각형이 평면좌표 상에서 겹치는 부분이 있는지의 여부를 출력하라.
단, 2개의 직사각형이 겹치는 지를 검사하는 다음 함수를 별도로 만들어 사용하라.*/

struct rectangle{ 
  int x1, y1; // 좌상점 좌표값 (왼쪽 위 모서리) 
  int x2, y2; // 우하점 좌표값 (오른 아래 모서리) 
}; 

int check_overlap(struct rectangle r1, struct rectangle r2); 

int main(void) {
  struct rectangle r1, r2;

  printf("첫 번째 직사각형 좌상점 좌표값(x, y)? ");
  scanf("%d %d", &r1.x1, &r1.y1);
  printf("첫 번째 직사각형 우하점 좌표값(x, y)? ");
  scanf("%d %d", &r1.x2, &r1.y2);
  printf("두 번째 직사각형 좌상점 좌표값(x, y)? ");
  scanf("%d %d", &r2.x1, &r2.y1);
  printf("두 번째 직사각형 우하점 좌표값(x, y)? ");
  scanf("%d %d", &r2.x2, &r2.y2);

  if(check_overlap(r1, r2) == 0){
    printf("두 직사각형은 겹치지 않습니다.");
  }else{
    printf("두 직사각형은 겹칩니다.");
  }

  return 0;
}

int check_overlap(struct rectangle r1, struct rectangle r2){


  if((r2.y2 >= r1.y1)||(r2.y1 <= r1.y2)){
    return 0;
  }else if((r2.x1 >= r1.x2)||(r2.x2 <= r1.x1)){
    return 0;
  }else{
    return 1;
  }


}
 // 겹치면 1리턴, 아니면 0리턴
