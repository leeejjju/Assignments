#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*데이터파일(data.txt)로부터 이름, C, Java, Python 성적점수를 읽어들여 각 사람의 점수와 총점, 평균 및 각 교과목별 평균과 가장 높은 점수를 받은 사람의 이름, 점수를 출력하라.

* 주의사항 *

파일에서 읽어올 때에 미리 횟수를 정하지 말 것. (최대 20개로 가정)
파일을 읽는 fscanf()가 제대로 데이터를 읽었는지 확인해서 빈줄은 무시할 수 있도록 처리할 것.
필요한 함수가 있으면 직접 만들어 사용할 것!
*/

/*
1. 파일에서 정보 읽어와서 배열에 저장하고+총점누적
  1-1 파일 열기
  1-2 파일이 끝나기까지...
    1-2-1 문자열, 정수, 정수, 정수로 읽어내기, 임시저장
    1-2-2 4개가 잘 읽어들여졌으면 찐배열에 임시저장 저장 
    1-2-3 인간별 총점 누적
    1-2-4 과목별 총점 누적
2. 저장된 배열 출력
3. 과목별 최종정리 출력 
*/

int findBestOne(int score[3][20], int subNum, int count);

int main(void) {
  char subName[3][20] = {"C", "Java", "Python"}; //과목명
  char name[20][20] = {0,}; //학생이름(최대20명)
  int score[3][20]; //학생점수(최대20명)
  int stuSum[20] = {0,}; //학생별총점(최대20명)
  int subSum[3] = {0,}; //과목총점
  int count = 0; //유효한 학생수 (20이내여야함...)


//printf("아임얼라이브\n");

//1. 파일에서 정보 읽어와서 배열에 저장하고+총점누적
  //1-1 파일 열기
  FILE* file;
  file = fopen("data.txt", "r");
  
  //1-2 파일이 끝나기까지...
  while(!feof(file)){
    char n[20]; //임시저장용 학생이름
    int s[3];//임시저장용 학생점수
    int r; //제대로 값 들어왔나 확인용 
    //1-2-1 문자열, 정수, 정수, 정수로 읽어내기, 임시저장
    r = fscanf(file, "%s %d %d %d", n, &s[0], &s[1], &s[2]);
    //1-2-2 4개가 잘 읽어들여졌으면 찐배열에 임시저장 저장, 인간별 총점 누적, 과목별 총점 누적
    if(r == 4){ //유의미한 값이 모두 들어왔으면 
      strcpy(name[count], n); //임시저장된 정보 찐에다가 카피 
      for(int i = 0; i < 3; i++){
        score[i][count] = s[i];
        subSum[i] += s[i];
      }
      stuSum[count] = s[0] + s[1] + s[2];
      count++;
    }
  }
  //1-3 파일 닫기 
  fclose(file);


printf("%d records read.\n", count);

//2. 저장된 배열 출력
for(int i = 0; i < count; i++){
  printf("%-6s  %d  %d  %d  %d  %.1f\n", name[i], score[0][i], score[1][i], score[2][i], stuSum[i], stuSum[i]/3.0);
}

//3. 과목별 최종정리 출력 
for(int i = 0; i < 3; i++){
  printf("%s - average : %.1f, Top : %s (%d)\n", subName[i], (float)subSum[i]/count, name[findBestOne(score, i, count)], score[i][findBestOne(score, i, count)]);
}
  return 0;
}

int findBestOne(int score[3][20], int subNum, int count){
  int max = 0;
  int maxIndex = 0;

  for(int i = 0; i < count; i++){
    if(max < score[subNum][i]){
      max = score[subNum][i];
      maxIndex = i;
    }
  }

  return maxIndex;
}
///과목별 최득점자의 인덱스 리턴
//받는거... 점수배열 score, 어느과목인지 번호 subNum, 몇명인지 count 
