#include <stdio.h>
#include <stdlib.h>
/*구조체를 사용하여, 국어, 영어, 수학 점수를 입력받아 총점과 평균 점수, 등급을 계산하여 출력하라.

단, 구조체 변수를 선언하지 말고, 구조체 포인터를 선언하여 동적으로 메모리를 할당받도록 하라.

등급은 다음과 같은 기준으로 결정하라.
평균 90이상 : A
평균 80이상 ~ 90미만 : B
평균 70이상 ~ 80미만 : C
평균 60이상 ~ 70미만 : D
평균 60미만 : F*/

struct st_jumsu{
 int kor, eng, mat;
 int sum;
 float avg;
 char grade;
};

struct st_jumsu* getScore();
void evalScore(struct st_jumsu* p);


//제공된 코드, main() 수정 금지
int main(){
	struct st_jumsu* score = getScore();
	evalScore(score);
	printf("학생의 총점은 %d 평균은 %.1f (등급 %c)\n",score->sum, score->avg, score->grade);
	return 0;
}

struct st_jumsu* getScore(){

  struct st_jumsu* p;
  p = malloc(sizeof(struct st_jumsu));

  printf("국어 점수? > ");
  scanf("%d", &p->kor);
  printf("영어 점수? > ");
  scanf("%d", &p->eng);
  printf("수학 점수? > ");
  scanf("%d", &p->mat);

  return p;
}
// 수행내용 : 점수 구조체를 동적메모리할당받고 학생의 국어, 영어, 수학 점수를 입력받아 구조체 포인터를 리턴함

void evalScore(struct st_jumsu* p){
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
// 수행내용 : 구조체 포인터를 받아 학생별 총점과 평균, 등급 계산하여 저장
