#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*학생 5명의 국어, 영어, 수학 점수를 50~100 사이의 점수를 임의로 만들어 저장한 후에, 다음 항목들을 계산하여 출력하라.

단, 제공된 main() 함수 코드를 수정없이 함수 내용만 작성하라.*/


void evalClass(int j[5][3], int i, int* s, float* a);
void evalStudent(int j[5][3], int i, int* s, float* a, char* g);

int main(void) {
  int jumsu[5][3];        // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  int sum = 0;                //총점저장용
  float avg;              // 평균저장용
  char grade;             // 등급저장용
  int i, j;               // 반복문을 위한 변수

  srand(time(0)); 
  for(i=0;i<5;i++)
    for(j=0;j<3;j++)
      jumsu[i][j] = rand()%50+51;

  printf("5명의 학생 점수가 생성되었습니다.\n"); 
  for(i=0;i<5;i++){
    printf("%d번 학생 : ",i+1); 
    for(j=0;j<3;j++){
      printf("%s %d", classname[j], jumsu[i][j]); 
      if(j<2) printf(", ");
      else printf("\n");
    } 
  }

  printf("1) 각 과목별 총점과 평균점수\n"); 
  for(i=0;i<3;i++){
    evalClass(jumsu, i, &sum, &avg);
    printf("%s 점수의 총점은 %d 평균은 %.1f\n",classname[i],sum,avg);
    sum = 0;
  }

  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n"); 
  for(i=0;i<5;i++){
    evalStudent(jumsu, i, &sum, &avg, &grade);
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n",i+1,sum,avg,grade); 
    sum = 0;
  }
  
  return 0; 
}


void evalClass(int j[5][3], int i, int* s, float* a){
  int k;
  for(k = 0; k < 5; k++){
     *s += j[k][i];
  }
  *a = *s / 5;
}
//파라미터 : 점수배열(j)과 과목번호(i=0,1,2), 총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a)
//수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균을 계산해 포인터 변수를 사용하여 저장함



void evalStudent(int j[5][3], int i, int* s, float* a, char* g){
  int k;
  for(k = 0; k < 3; k++){
     *s += j[i][k];
  }
  *a = *s / 3;

  if(*a >= 90){
    *g = 'A';
  }else if(*a >= 80){
    *g = 'B';
  }else if(*a >= 70){
    *g = 'C';
  }else if(*a >= 60){
    *g = 'D';
  }else{
    *g = 'F';
  }

}

//파라미터 : 점수배열(j)과 학생번호(i=0,1,2,3,4),총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a), 등급을 저장할 포인터변수(g)
//수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균, 등급을 계산해 포인터 변수를 사용하여 저장함

