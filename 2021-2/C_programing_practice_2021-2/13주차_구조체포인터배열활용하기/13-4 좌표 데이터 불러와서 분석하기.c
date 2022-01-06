#include <stdio.h>
#include <stdlib.h>
/*13-3 문제에서 저장한 point.txt 파일로부터 여러 개의 좌표를 읽어와서 위치를 분석하라.

위치 검사 방법
1사분면은 x값, y값이 모두 양수, 2사분면은 x값은 음수, y값은 양수, 3사분면은 x값, y값이 모두 음 수, 4사분면은 x값은 양수, y값은 음수인 경우이다.

제공된 코드 main() 수정 불가*/

struct st_point{ 
    float x; 	// x좌표 값 
    float y; 	// y좌표 값 
}; 
int loadPoints(struct st_point* list[], char* filename); 
int getPosition(struct st_point* p);

int main()
{
    struct st_point* mypoint[50]; // 최대 50개의 좌표 저장용 
    int size; // 좌표 총 개수
    int count[5]={0}; // 좌표위치별 개수 (0:축 좌표 개수, 1~4:1~4분면 좌표 개수)
    size = loadPoints(mypoint, "point.txt");
    for(int i=0;i<size;i++){
        int pos = getPosition(mypoint[i]);
        count[pos]++;
    }
    printf("축의 좌표는 모두 %d개\n", count[0]);
    for(int i=1;i<=4;i++)
        printf("%d사분면의 좌표는 모두 %d개\n", i, count[i]);
    return 0;
}

int loadPoints(struct st_point* list[], char* filename){
  int count = 0;

  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    list[count] = malloc(sizeof(struct st_point));
    int r = fscanf(file, "%f %f", &list[count]->x, &list[count]->y);
    if(r < 2){
      break;
    }else{
      count ++;
    }
  }

  printf("%s에서 %d개의 좌표정보를 읽었습니다.\n", filename, count);

  return count;
}
//파라미터 : 저장해야 하는 좌표 목록(구조체 포인터 배열), 읽어들일 파일이름
//리턴값 : 읽어들인 좌표의 개수 
//수행내용 : 파일로부터 좌표데이터를 읽어들이되 동적 메모리 할당을 해주어야 하며, 읽어들인 좌표의 개수를 리턴함


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

