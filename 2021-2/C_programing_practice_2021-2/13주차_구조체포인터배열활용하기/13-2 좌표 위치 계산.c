#include <stdio.h>
#include <stdlib.h>
/*다음 구조체를 이용하여 10개의 좌표 데이터를 입력받은 후, 각각의 좌표가 1,2,3,4분면 중에 어디에 위치 하고 있는지를 출력하고, 각 사분면 별로 좌표의 갯수를 출력하라. 단, 10개의 좌표는 구조체포인터 배열을 선언하여 사용하고 필요시 메모리를 할당받도록 하라.
좌표 입력은 함수를 제작하여 사용하되, 반드시 함수 내에서 동적 메모리 할당을 수행하여야 한다.
좌표의 사분면 위치를 알아내기 위하여 함수를 제작하여 사용하라.
위치 검사 방법

1사분면은 x값, y값이 모두 양수, 2사분면은 x값은 음수, y값은 양수, 3사분면은 x값, y값이 모두 음 수, 4사분면은 x값은 양수, y값은 음수인 경우이다.
*/

struct st_point{ 
 float x; // x좌표 값 
 float y; // y좌표 값 
};

int getPosition(struct st_point* p);
struct st_point* getPoint(); 


int main(void) {
  struct st_point* mypoint[10];
  int countList[5] ={0,};
  

  for(int i = 0; i < 10; i++){
    printf("%d번째 좌표\n", i+1);
    mypoint[i] = getPoint();
  }

  for(int i = 0; i < 10; i++){
    if(getPosition(mypoint[i])==0){
      printf("%d번째 좌표 축에 위치\n", i+1);
    }else{
      printf("%d번째 좌표 %d사분면에 위치\n", i+1, getPosition(mypoint[i]));
    }
    countList[getPosition(mypoint[i])]++;
  }

  printf("축의 좌표는 모두 %d개\n", countList[0]);
  for(int i = 0; i < 4; i++){
    printf("%d사분면의 좌표는 모두 %d개\n", i+1, countList[i+1]);
  }



  return 0;
}

struct st_point* getPoint(){
  struct st_point* p; //포인터 하나 만들고 
  p = malloc(sizeof(struct st_point)); //공간 할당받고

  printf("x, y값? "); //값 채운다음에
  scanf("%f %f", &p->x, &p->y);
  
  return p; //고 주소값 리턴 
}
// 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함


int getPosition(struct st_point* p){

  if(p->x == 0 || p->y == 0){ //축 거르고 
    return 0;
  }else if(p->x > 0){
    if(p->y > 0){
      return 1;
    }else{
      return 4;
    }
  }else{
    if(p->y > 0){
      return 2;
    }else{
      return 3;
    }
  }



}
// 리턴값 : 좌표의 사분면 위치 (0:축, 1:1사분면, 2:2사분면, 3:3사분면, 4:4사분면)
// 수행내용 : 전달받은 좌표의 위치를 파악하여 위치번호(0~4)를 리턴함
