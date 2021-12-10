#include <stdio.h>
#include <stdlib.h>
/*구조체를 사용하여, 5명의 국어, 영어, 수학 점수를 입력받아 과목별 총점, 평균 및 학생별 총점과 평균 점수, 등급을 계산하여 출력하라.
점수를 입력하는 과정은 함수를 통해 동적으로 메모리를 할당받아 진행하도록 하라.
단 학생별 총점과 평균, 등급 계산은 함수를 제작하여 수행하도록 하라.

등급은 다음과 같은 기준으로 결정하라.
평균 90이상 : A
평균 80이상 ~ 90미만 : B
평균 70이상 ~ 80미만 : C
평균 60이상 ~ 70미만 : D
평균 60미만 : F

제공된 코드 main() 수정금지*/

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

struct st_jumsu* getJumsu();
void evalScore(struct st_jumsu* p);

int main()
{
    struct st_jumsu* jumsu[5]; // 5명의 점수 저장용 포인터 배열 
    for(int i=0;i<5;i++){
        printf("%d번 학생\n", i+1);
        jumsu[i] = getJumsu();
		    evalScore(jumsu[i]);
    }

    for(int i = 0; i < 5; i++){
      printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    }
    return 0;
}

struct st_jumsu* getJumsu(){
  struct st_jumsu* p;
  p = malloc(sizeof(struct st_jumsu));

  printf("국어, 영어, 수학 점수를 입력하시오. > ");
  scanf("%d %d %d", &p->kor, &p->eng, &p->mat);

  return p;
}
// 수행내용 : 동적으로 메모리를 할당받은 구조체 내에 국어, 영어, 수학 점수를 입력받아 저장하고 이 구조체의 포인터를 리턴함

void evalScore(struct st_jumsu* p){

  p->sum = p->kor + p->eng + p->mat;
  p->avg = p->sum / 3.0;

  if(p->avg < 60){
    p->grade = 'F';
  }else if(p->avg < 70){
    p->grade = 'D';
  }else if(p->avg < 80){
    p->grade = 'C';
  }else if(p->avg < 90){
    p->grade = 'B';
  }else{
    p->grade = 'A';
  }

}
// 파라미터 : 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 구조체 포인터를 받아 학생별 총점과 평균, 등급 계산하여 저장
