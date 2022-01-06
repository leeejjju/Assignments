#include <stdio.h>
void markArea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value);
void printMatrix(int p[5][5]); // 5*5 매트릭스의 내용을 출력하는 함수 

/*
5*5 크기의 매트릭스로 표현가능한 패턴이 주어졌을 때에, 이 패턴안에 서로 다른 영역으로 구분할 수 있는 영역이 모두 몇개인지 찾아내어 표현하라.

단, 패턴값이 0인 경우는 배경으로 무시하며, 상/하/좌/우에 인접한 칸에 같은 값이 들어있는 경우에만 같은 영역으로 인정한다.

즉, 패턴값이 같더라도 인접한 칸이 아닌 경우 다른 영역으로 인식하여야 한다.

주어진 메인함수 및 printMatrix()함수는 수정 없이 그대로 사용하고, markArea()함수를 구현하되, 반드시 재귀함수로 구현하라.

1. picture.txt 파일을 읽어 5*5 매트릭스인 picture를 채우고 출력한다.
2. 동일한 크기의 zone 매트릭스를 준비한다.(초기값 0)
3. picture 매트릭스의 첫번째 칸부터 시작하여 markArea를 통해 인접한 영역을 찾으면서 zone 매트릭스에 영역번호를 채운다.
4. picture 매트릭스의 끝까지 확인했다면 마친 후
5. 영역의 갯수와 zone 매트릭스의 내용을 출력한다.*/

int main(void) {
  int picture[5][5]={0}; // 원본 패턴 
  int zone[5][5] = {0};  // 영역표시용 패턴
	int row = 5, col = 5;      // 가로, 세로 크기
	int area = 0;            // 영역번호

  //파일로부터 읽어내서 picture 배열 채우기 
  FILE *fp = fopen("picture.txt", "rt"); 
  for(int i= 0; i < row; i++){
    for(int j= 0; j < col; j++)
      fscanf(fp, "%d", &picture[i][j]);
  }
  fclose(fp);

  //picture 배열에 채워진 초안 출력 
	printMatrix(picture);

  //zone배열에 picture기반, 적절한 조치 취한 내용으로 채우기 
  for(int i=0; i < row; i++){
    for(int j=0; j < col; j++){
    	if(picture[i][j] != 0 && zone[i][j]==0){ 
      // 원본 패턴값이 0이 아니고, 아직 영역체크가 안된 경우
      	area++; // 새로운 영역 시작
				int value = picture[i][j]; // 패턴값
        //printf("패턴값 %d을(를) area %d로 채우겠슴니당\n", value, area);
      	markArea(picture, zone, i, j, area, value); 
        //이 칸으로부터 같은 패턴값의 모든 영역을 찾아 마크하라.
      }
    }
  }
  
  //zone배열에 채워진 결과 출력 
	printf("\n%d areas found.\n\n", area);
	printMatrix(zone);
}  

//---------------------------------------------------------------

void printMatrix(int p[5][5]){
  for(int i=0; i < 5; i++){
    for(int j=0; j < 5; j++){
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }	
}

//---------------------------------------------------------------

void markArea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value){

  if(xpos < 0 || xpos > 4) return;
  if(ypos < 0 || ypos > 4) return;
  if(z[xpos][ypos] != 0) return;
  if(p[xpos][ypos] != value) return;
  if(p[xpos][ypos] == 0) return;

  //printf("방금 [%d][%d]에다가 area %d집어넣음 뚜쉬뚜쉬\n", xpos, ypos, area);

  //이 모든 조건을..요리조리 피했다면 
  z[xpos][ypos] = area; //zone에 마크해주고
  //상하좌우 실행
  markArea(p, z, xpos-1, ypos, area, value);
  markArea(p, z, xpos+1, ypos, area, value);
  markArea(p, z, xpos, ypos-1, area, value);
  markArea(p, z, xpos, ypos+1, area, value);

}
//수행내용 : 원본매트릭스(p)의 xpos, ypos 칸으로부터 출발하여 사방을 뒤지면서, value값과 일치하는 칸에 대해 영역매트릭스(z)의 같은 위치 칸에 영역번호(area)를 넣는다.

//return조건 
  //1. 새로운 x혹은 y가 영역을 벗어남
  //2. z존의 해당 칸이 이미 마크됨
  //3. 새로운 p존의 값이 value와 다름 
  //4. 새로운 p존의 값이 0임(바다임)
  //5. 위의 네 경우가 아니라면 새로운 위치를 기준 사방에 함수 실행 



