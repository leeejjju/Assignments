#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*학생 5명의 국어, 영어, 수학 점수를 50~100 사이의 점수를 임의로 만들어 저장한 후에, 다음 항목들을 계산하여 출력하라.

1) 각 과목별 총점과 평균 점수

2) 각 학생별 총점과 평균점수, 평균에 따른 등급

등급은 다음과 같은 기준으로 결정하라. 평균 90이상 : A

평균 80이상 ~ 90미만 : B

평균 70이상 ~ 80미만 : C

평균 60이상 ~ 70미만 : D 평균 60미만 : F

다음과 같은 함수를 만들어 사용하라  ...*/

int classsum(int s[5][3], int classnum){ //과목별 총점

  int i, j;
  int sum = 0;
  for(i = 0; i < 5; i++){
     sum += s[i][classnum];
  }
  return sum;
}
// 파라미터 : 점수배열(s)과 과목번호(0,1,2) 
// 리턴값 : 해당 과목의 총점

int studentsum(int s[5][3], int stunum){ //학생별 총점

  int i, j;
  int sum = 0;
  for(i = 0; i < 3; i++){
     sum += s[stunum][i];
  }
  return sum;
}
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 총점

char studentgrade(int s[5][3], int stunum){//학생별 등급
  char grade;
  int ave;
  ave = studentsum(s, stunum) / 3;

  if(ave >= 90){
    grade = 'A';
  }else if(ave >= 80){
    grade = 'B';
  }else if(ave >= 70){
    grade = 'C';
  }else if(ave >= 60){
    grade = 'D';
  }else{
    grade = 'F';
  }

  return grade;
} 
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 등급 ('A','B','C','D','F')


int main(void){
  int jumsu[5][3];            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  float ave;     //평균용으로 사용될 변수 
  int i, j;

  
  srand(time(0)); //시드 초기화 

  //랜덤 점수 생성 
  printf("5명의 학생 점수가 생성되었습니다.\n");
  for(i = 0; i <5; i++){
    printf("%d번 학생 : ", i+1);
    
    for(j = 0; j < 3; j++){//각 학생의 점수 생성 및 배열에 저장(국어-영어-수학 순 )
      jumsu[i][j] = 50+ rand()%50+1;
    }
    
    printf("국어 %d, 영어 %d, 수학 %d\n", jumsu[i][0], jumsu[i][1], jumsu[i][2]);
  }


  //결과 출력 
  printf("1) 각 과목별 총점과 평균점수\n");
  for(i = 0; i < 3; i++){
    ave = classsum(jumsu, i) / 5;
    printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], classsum(jumsu, i), ave);
  }

  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for(i = 0; i < 5; i++){
    ave = studentsum(jumsu, i)/3;
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, studentsum(jumsu, i), ave, studentgrade(jumsu, i));
  }


  return 0;
}
