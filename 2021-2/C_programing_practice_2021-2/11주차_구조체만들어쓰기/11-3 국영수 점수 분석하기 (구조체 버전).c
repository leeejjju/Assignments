#include <stdio.h>
/*구조체 배열을 사용하여, 데이타 파일로부터 학생 5명의 국어, 영어, 수학 점수를 입력받아 다음 항목들을 계산하여 출력하라.
1) 각 과목별 총점과 평균 점수
2) 각 학생별 총점과 평균점수, 평균에 따른 등급 등급은 다음과 같은 기준으로 결정하라.
평균 90이상 : A
평균 80이상 ~ 90미만 : B
평균 70이상 ~ 80미만 : C
평균 60이상 ~ 70미만 : D
평균 60미만 : F*/

/*
1. 파일로부터 데이터 입력받아 구조체에 저장, 총점누적 
  1-1 파일 열기
  1-2 이하 5회 루프
    1-2-1 파일에서 정보 읽어내 구조체에 저장
    1-2-2 함수 호출하여 총점과 평균, 등급 구조체에 저장
2. 함수 호출하여 과목별 정보 변수에 저장
3. 과목별 결과, 학생별 결과 출력하기 

*/

struct st_jumsu{
  int kor, eng, mat;
  int sum;
  float avg;
  char grade;
};

void sumClass(struct st_jumsu p[], int* sum, float* avg, int i);
void evalStudent(struct st_jumsu* p);

int main(void) {
  struct st_jumsu p[5];

  FILE* data;
  data = fopen("data.txt", "r");

  for(int i=0; i<5; i++){
    fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].mat);
    evalStudent(p+i);
  }

  //이곳에 코드 작성 

  for(int i = 0; i < 5; i++){
    printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n", i+1, p[i].kor, p[i].eng, p[i].mat);
  }

  int sum;
  float avg;
  char subject[3][10] = {"국어", "영어","수학"};

  printf("1) 각 과목별 총점과 평균점수\n");
  for(int i=0; i<3; i++){
    sumClass(p, &sum, &avg, i);
    printf("%s 점수의 총점은 %d 평균은 %.1f\n", subject[i], sum, avg);
  }

  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for(int i = 0; i < 5; i++){
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, p[i].sum, p[i].avg, p[i].grade);
  }
  
  return 0;
}


void sumClass(struct st_jumsu p[], int* sum, float* avg, int i){
  int n = 0;

  for(int j = 0; j < 5; j++){
    if(i == 0){
      n += p[j].kor;
    }else if(i == 1){
      n += p[j].eng;
    }else if(i == 2){
      n += p[j].mat;
    }
  }
  *sum = n;

  float a = (float)n/5.00;
  *avg = a;

}
// 파라미터 : p : 구조체 배열, sum : 총점 변수 포인터, avg : 평균 변수 포인터, i : 0,1,2 (과목의 종류) 
// 리턴값 : 없음
// 수행내용 : 구조체 배열 내의 해당 과목(i)의 모든 점수의 총점과 평균을 계산하여 포인터 변수를 통해 값을 저장

void evalStudent(struct st_jumsu* p){
  float n = 0;

  n += p->kor;
  n += p->eng;
  n += p->mat;
  p->sum = n;

  n = (float)n / 3.0;
  p->avg = n;

  if(n < 60){
    p->grade = 'F';
  }else if(n < 70){
    p->grade = 'D';
  }else if(n < 80){
    p->grade = 'C';
  }else if(n < 90){
    p->grade = 'B';
  }else{
    p->grade = 'A';
  }

}
// 파라미터 : 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 학생의 점수 구조체 포인터를 받아 총점과 평균, 등급 계산하여 저장
