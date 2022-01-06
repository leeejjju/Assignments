#include <stdio.h>

int main(void) {
  int width, height;  // 가로크기, 세로크기 
  int area;           // 사각형의 넓이

  printf("width? ");
  scanf("%d", &width);
  printf("height? ");
  scanf("%d", &height);

  area = width * height;

  if( width == height){
    printf("넓이는 %d이고 정사각형입니다.", area);
  }else{
    printf("넓이는 %d이고 정사각형이 아닙니다.", area);
  }
return 0;
}
