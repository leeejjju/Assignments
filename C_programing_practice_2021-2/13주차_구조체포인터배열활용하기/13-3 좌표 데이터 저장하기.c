#include <stdio.h>
#include <stdlib.h>
/*13-2 문제를 활용하여 좌표의 개수를 물어본 후, 그만큼의 좌표 값을 입력받아 좌표 데이터를 point.txt 파일에 저장하라.
좌표 입력은 함수를 사용하되, 반드시 함수 내에서 동적 메모리 할당을 수행하여야 한다.

제공된 코드 main() 수정 불가
*/

struct st_point{ 
    float x; 		// x좌표 값 
    float y; 		// y좌표 값 
}; 

struct st_point* getPoint();
void savePoints(struct st_point* list[], char* filename, int size); 

int main()
{
    struct st_point* mypoint[50]; // 최대 50개의 좌표 저장용 
    int size;
    printf("좌표의 개수는? > ");
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        printf("%d번째 좌표\n", i+1);
        mypoint[i] = getPoint();
    }
    savePoints(mypoint, "point.txt", size);
    return 0;
}

void savePoints(struct st_point* list[], char* filename, int size){

  FILE* file;
  file = fopen(filename, "w");

  for(int i = 0; i < size; i++){
    fprintf(file, "%.1f %.1f\n", list[i]->x, list[i]->y);
  }

  fclose(file);

  printf("\n%d개의 좌표를 저장하였습니다.\n", size);
}
//파라미터 : 좌표 목록 (구조체포인터 배열), 저장할 파일이름, 레코드 갯수
//리턴값 : 없음

struct st_point* getPoint(){
  struct st_point* p;
  p = malloc(sizeof(struct st_point));

  printf("x, y값? ");
  scanf("%f %f", &p->x, &p->y);

  return p;
} 
// 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함
