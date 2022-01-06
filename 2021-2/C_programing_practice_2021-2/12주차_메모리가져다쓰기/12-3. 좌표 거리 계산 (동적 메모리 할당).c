#include <stdio.h>
#include<math.h>
#include <stdlib.h>
/*구조체를 이용하여 2개의 좌표 데이터를 입력받아 이를 출력하고, 두 좌표 사이의 거리를 출력하라

좌표 입력은 다음 함수를 제작하여 사용하되, 반드시 함수 내에서 동적 메모리 할당을 수행하여야 한다.

두 좌표 사이의 거리 계산은 다음 함수를 만들어 사용하되, 계산 방법은 ((x값의 차이의 제곱)+(y값의 차이의 제곱))의 제곱근이다. 계산할 때에 sqrt()와 pow()함수를 사용하라.*/

struct st_point{ 
 float x; // x좌표 값 
 float y; // y좌표 값 
}; 

struct st_point* getPoint();  // 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함

float calcDistance(struct st_point* p1, struct st_point* p2); // 두 점의 거리 구하는 함수

int main(void) {
  struct st_point* point1; 	// 첫번째 좌표를 위한 포인터
  struct st_point* point2; 	// 두번째 좌표를 위한 포인터 

  printf("첫번째 좌표\n");
  point1 = getPoint();
  printf("두번째 좌표\n");
  point2 = getPoint();

  printf("\n두 좌표 사이의 거리는 %.1f", calcDistance(point1, point2));


  return 0;
}

struct st_point* getPoint(){

  struct st_point* p;
  p = malloc(sizeof(struct st_point));

  printf("x값? ");
  scanf("%f", &p->x);
  printf("y값? ");
  scanf("%f", &p->y);

  return p;
}  
// 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함

float calcDistance(struct st_point* p1, struct st_point* p2){
  float dis;
  dis = sqrt(pow((p1->x) - (p2->x),2)+pow((p1->y) - (p2->y),2));
  return dis;
}
// 두 점의 거리 구하는 함수

