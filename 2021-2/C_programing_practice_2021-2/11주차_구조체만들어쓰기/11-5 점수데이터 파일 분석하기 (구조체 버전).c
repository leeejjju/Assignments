#include <stdio.h>
#include <string.h>
/*구조체를 사용해서 데이터파일(data.txt)로부터 이름, C, Java, Python 성적점수를 읽어들여 각 사람의 점수와 총점, 평균 및 각 교과목별 평균과 가장 높은 점수를 받은 사람의 이름, 점수를 출력하라.

주의사항- 파일에서 읽어올 때에 미리 횟수를 정하지 말 것. (최대 20개로 가정)- 파일을 읽는 fscanf()가 제대로 데이터를 읽었는지 확인해서 빈줄은 무시할 수 있도록 처리할 것.*/

/*
1. 파일에서 정보 읽어서 구조체 배열에 저장 
  1-1 파일 열기
  1-2 파일끝까지... 
    1-2-1 정보 읽어 인스턴트 변수에 저장
    1-2-2 읽어낸 변수갯수가 알맞으면 구조체에 저장, 카운트 증가
2. 읽어낸 정보 출력, 과목별 총점누적 
  2-1 카운트만큼 이하반복...
    2-1-1 출력
    2-1-2 과목별 총점누적 세번
3. 과목별 평균, 최고점학생과 점수 출력 (함수:최고점학생의 인덱스 리턴하는놈으로 )
  3-1 출력출력, 파라미터는 함수콜해서. 
*/

struct st_score{
  char name[10]; // 이름 
  int jumsu[3];  // 점수 (C, Java, Python)
  int sum;  // 총점
  float avg;  //  평균 
};

int findBestOne(struct st_score s[20], int sub, int count);


int main(void) {

  struct st_score s[20]; //학생정보 저장할 구조체 
  int count = 0; //유효한 학생수이자 구조체 인덱스
  int sumSub[3] = {0, 0, 0}; //과목별 총점. 차례로 c java py  

//1. 파일에서 정보 읽어서 구조체 배열에 저장 
  //1-1 파일 열기
  FILE *file;
  file = fopen("data.txt", "r");
  //1-2 파일끝까지... 
  while(!feof(file)){
    //  1-2-1 정보 읽어 인스턴트 변수에 저장
    char n[10];
    int j0, j1, j2;

    int r = fscanf(file, "%s %d %d %d", n, &j0, &j1, &j2);
      //1-2-2 읽어낸 변수갯수가 알맞으면 구조체에 저장, 카운트 증가
    if(r == 4){
      strcpy(s[count].name,n);
      s[count].jumsu[0] = j0;
      s[count].jumsu[1] = j1;
      s[count].jumsu[2] = j2;

      s[count].sum = 0;
      s[count].sum += j0;
      s[count].sum += j1;
      s[count].sum += j2;

      s[count].avg = (float)s[count].sum/3.0;

      count++;
    }
  }
//2. 읽어낸 정보 출력, 과목별 총점누적 
  //2-1 카운트만큼 이하반복...
  printf("%d records read.\n", count);
  for(int i = 0; i < count; i++){
    //2-1-1 출력
    printf("%-7s %d  %d  %d  %d  %.1f\n", s[i].name,s[i].jumsu[0],s[i].jumsu[1],s[i].jumsu[2],s[i].sum,s[i].avg);
    //2-1-2 과목별 총점누적 세번
    
    sumSub[0] += s[i].jumsu[0];
    sumSub[1] += s[i].jumsu[1];
    sumSub[2] += s[i].jumsu[2];
  
  }
//3. 과목별 평균, 최고점학생과 점수 출력. (함수:최고점학생의 인덱스 리턴하는놈으로 )
  //3-1 출력출력, 파라미터는 함수콜해서. 



  printf("C - average : %.1f, Top : %s (%d)\n", (float)sumSub[0]/count, s[findBestOne(s, 0, count)].name, s[findBestOne(s, 0, count)].jumsu[0]);
  printf("Java - average : %.1f, Top : %s (%d)\n", (float)sumSub[1]/count, s[findBestOne(s, 1, count)].name, s[findBestOne(s, 1, count)].jumsu[1]);
  printf("Python - average : %.1f, Top : %s (%d)\n", (float)sumSub[2]/count, s[findBestOne(s, 2, count)].name, s[findBestOne(s, 2, count)].jumsu[2]);

  return 0;
}

int findBestOne(struct st_score s[20], int sub, int count){
  int max = 0, maxIndex = 0;

  for(int i = 0; i < count; i++){
    if(s[i].jumsu[sub] > max){
      max = s[i].jumsu[sub];
      maxIndex = i;
    }
  }

  return maxIndex;
}
//구조체 배열과 과목번호, 학생수를 받아서 최고점수를 가진 학생의 인덱스 리턴 
