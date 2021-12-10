#include<stdio.h>
#include<stdlib.h>
#include <time.h>
/*학생 5명의 국어, 영어, 수학 점수를 50~100 사이의 점수를 임의로 만들어 저장한 후에, 다음 항목들을 계산하여 출력하라.

1) 각 과목별 총점과 평균 점수

2) 각 학생별 총점과 평균점수, 평균에 따른 등급

등급은 다음과 같은 기준으로 결정하라.

평균 90이상 : A

평균 80이상 ~ 90미만 : B

평균 70이상 ~ 80미만 : C

평균 60이상 ~ 70미만 : D

평균 60미만 : F*/

int main(void){
  int jumsu[5][3];            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  int sum_student[5] = {0};         // 학생별 총점
  float average_student[5];   // 학생별 평균
  char grade[5];              // 학생별 등급 
  int sum_class[3] = {0};           // 과목별 총점
  float average_class[3];     // 과목별 평균
  int i, j; //빈복문 실행을 위한 변수 

  srand(time(0)); //시드 초기화 

  //결과 출력 

  printf("5명의 학생 점수가 생성되었습니다.\n");
  for(i = 0; i <5; i++){
    printf("%d번 학생 : ", i+1);

    for(j = 0; j < 3; j++){//각 학생의 점수 생성 및 배열에 저장(국어-영어-수학 순 )
      jumsu[i][j] = 50+ rand()%50+1;
      sum_class[j] += jumsu[i][j];
      sum_student[i] += jumsu[i][j];
    }

    printf("국어 %d, 영어 %d, 수학 %d\n", jumsu[i][0], jumsu[i][1], jumsu[i][2]);
  }

  printf("1) 각 과목별 총점과 평균점수\n");
  for(i = 0; i < 3; i++){
    average_class[i] = sum_class[i] / 5;
    printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum_class[i], average_class[i]);
  }


  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for(i = 0; i < 5; i++){

    average_student[i] = sum_student[i] / 3;

    if(average_student[i] >= 90){
      grade[i] = 'A';
    }else if(average_student[i] >= 80){
      grade[i] = 'B';
    }else if(average_student[i] >= 70){
      grade[i] = 'C';
    }else if(average_student[i] >= 60){
      grade[i] = 'D';
    }else{
      grade[i] = 'F';
    }

    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, sum_student[i], average_student[i], grade[i]);
  }


  return 0;
}
