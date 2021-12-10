#include <stdio.h>
#include <math.h>
/*다음 구조체를 이용하여 2개의 좌표 데이터를 입력받아 이를 출력하고, 두 좌표 사이의 거리를 출력하라. 
단, 두 좌표 사이의 거리 계산은 별도의 함수를 만들어 사용하되,
계산 방법은 (x값의 차이)^2+(y값의 차이)^2의 제곱근이다.
계산할 때에 sqrt()와 pow()함수를 사용하라.*/

struct point{ 
  float x; // x좌표 값 
  float y; // y좌표 값 
}; 

float calcDistance(struct point* p1, struct point* p2);

int main(void) {
  struct point p1, p2;

  printf("첫 번째 좌표의 x값? ");
  scanf("%f", &p1.x);
  printf("첫 번째 좌표의 y값? ");
  scanf("%f", &p1.y);
  printf("두 번째 좌표의 x값? ");
  scanf("%f", &p2.x);
  printf("두 번째 좌표의 y값? ");
  scanf("%f", &p2.y);

  printf("\n두 좌표 사이의 거리는 %.1f", calcDistance(&p1, &p2));

  return 0;
}

float calcDistance(struct point* p1, struct point* p2){
  float dis;

  dis = sqrt(pow((p1->x) - (p2->x),2)+pow((p1->y) - (p2->y),2));

  return dis;
}
 // 두 점의 거리 구하는 함수
