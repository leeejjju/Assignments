#include <stdio.h>

int main(void) {
  
  int jumsu[5][3] = {0, };            // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  int sum_student[5] = {0, };         // 학생별 총점
  float average_student[5];   // 학생별 평균
  char grade[5];              // 학생별 등급 
  int sum_class[3] = {0, };           // 과목별 총점
  float average_class[3];     // 과목별 평균
  int i, j;                   // 반복문을 위한 변수 

  for(i = 0; i < 5; i++){ //학생별 점수 입력받고 정보 저장, 평균등급 저장 
    printf("%d번 학생 국어, 영어, 수학 점수? ", i+1 );
    scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);

    sum_student[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2]; //학생별 총점 
    sum_class[0] += jumsu[i][0]; //국어 총점 
    sum_class[1] += jumsu[i][1]; //영어 총점 
    sum_class[2] += jumsu[i][2]; //수학 총점 

    for(j = 0; j < 3; j++){ //평균에 따르 등급 
      if( sum_student[i]/3 >= 90){
       grade[i] = 'A';
     }else if(sum_student[i]/3 >= 80){
        grade[i] = 'B';
      }else if(sum_student[i]/3 >= 70){
        grade[i] = 'C';
      }else if(sum_student[i]/3 >= 60){
        grade[i] = 'D';
      }else{
        grade[i] = 'F';
      }
    }
  }
  
  printf("1) 각 과목별 총점과 평균점수\n");
  printf("국어 점수의 총점은 %d 평균은 %.1f\n", sum_class[0], sum_class[0]/5.0 );
  printf("영어 점수의 총점은 %d 평균은 %.1f\n", sum_class[1], sum_class[1]/5.0);
  printf("수학 점수의 총점은 %d 평균은 %.1f\n", sum_class[2], sum_class[2]/5.0);


  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");

  for(i = 0; i < 5; i++){
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, sum_student[i], sum_student[i]/3.0, grade[i]);
  }
  


  return 0;
}
