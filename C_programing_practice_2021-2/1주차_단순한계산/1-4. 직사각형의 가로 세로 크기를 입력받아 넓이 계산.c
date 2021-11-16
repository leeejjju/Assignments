#include <stdio.h>

int main(void) {

  int width, height;  // 가로크기, 세로크기 
  int area;           // 직사각형의 넓이 

  printf("width? ");
  scanf("%d", &width);
  printf("height? ");
  scanf("%d", &height);

  area = width * height;

  printf("area is %d.", area);


  return 0;
}
