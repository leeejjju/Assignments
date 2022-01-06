#include <stdio.h>
#include <stdlib.h>
/*���� ����ü�� �̿��Ͽ� 10���� ��ǥ �����͸� �Է¹��� ��, ������ ��ǥ�� 1,2,3,4�и� �߿� ��� ��ġ �ϰ� �ִ����� ����ϰ�, �� ��и� ���� ��ǥ�� ������ ����϶�. ��, 10���� ��ǥ�� ����ü������ �迭�� �����Ͽ� ����ϰ� �ʿ�� �޸𸮸� �Ҵ�޵��� �϶�.
��ǥ �Է��� �Լ��� �����Ͽ� ����ϵ�, �ݵ�� �Լ� ������ ���� �޸� �Ҵ��� �����Ͽ��� �Ѵ�.
��ǥ�� ��и� ��ġ�� �˾Ƴ��� ���Ͽ� �Լ��� �����Ͽ� ����϶�.
��ġ �˻� ���

1��и��� x��, y���� ��� ���, 2��и��� x���� ����, y���� ���, 3��и��� x��, y���� ��� �� ��, 4��и��� x���� ���, y���� ������ ����̴�.
*/

struct st_point{ 
 float x; // x��ǥ �� 
 float y; // y��ǥ �� 
};

int getPosition(struct st_point* p);
struct st_point* getPoint(); 


int main(void) {
  struct st_point* mypoint[10];
  int countList[5] ={0,};
  

  for(int i = 0; i < 10; i++){
    printf("%d��° ��ǥ\n", i+1);
    mypoint[i] = getPoint();
  }

  for(int i = 0; i < 10; i++){
    if(getPosition(mypoint[i])==0){
      printf("%d��° ��ǥ �࿡ ��ġ\n", i+1);
    }else{
      printf("%d��° ��ǥ %d��и鿡 ��ġ\n", i+1, getPosition(mypoint[i]));
    }
    countList[getPosition(mypoint[i])]++;
  }

  printf("���� ��ǥ�� ��� %d��\n", countList[0]);
  for(int i = 0; i < 4; i++){
    printf("%d��и��� ��ǥ�� ��� %d��\n", i+1, countList[i+1]);
  }



  return 0;
}

struct st_point* getPoint(){
  struct st_point* p; //������ �ϳ� ����� 
  p = malloc(sizeof(struct st_point)); //���� �Ҵ�ް�

  printf("x, y��? "); //�� ä�������
  scanf("%f %f", &p->x, &p->y);
  
  return p; //�� �ּҰ� ���� 
}
// �޸� �Ҵ�޾� ��ǥ ����ü�� x,y ���� �Է¹޾� �� �ּҰ��� ������


int getPosition(struct st_point* p){

  if(p->x == 0 || p->y == 0){ //�� �Ÿ��� 
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
// ���ϰ� : ��ǥ�� ��и� ��ġ (0:��, 1:1��и�, 2:2��и�, 3:3��и�, 4:4��и�)
// ���೻�� : ���޹��� ��ǥ�� ��ġ�� �ľ��Ͽ� ��ġ��ȣ(0~4)�� ������
