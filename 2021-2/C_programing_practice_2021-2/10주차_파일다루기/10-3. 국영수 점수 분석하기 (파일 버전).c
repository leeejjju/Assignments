#include <stdio.h>
/*9-3번 문제를 수정하라.

데이터 파일로부터 학생 5명의 국어, 영어, 수학 점수를 입력받아 다음 항목들을 계산하여 출력하라.

1) 각 과목별 총점과 평균 점수, 2) 각 학생별 총점과 평균점수, 평균에 따른 등급

등급은 다음과 같은 기준으로 결정하라.

평균 90이상 : A
평균 80이상 ~ 90미만 : B
평균 70이상 ~ 80미만 : C
평균 60이상 ~ 70미만 : D
평균 60미만 : F

1. 파일에서 학생들의 국영수 점수 입력받아 배열에 저장하기
  1-1 파일 읽기모드로 열기
  1-2 파일 한줄씩 읽어내려가며 배열에 저장
  1-3 파일 닫기
2. 함수 사용하여 과목별 총점과 평균점수 저장
  2-1 함수 만들기
    2-1-1 입력받은 배열로부터 과목을 기준으로 sum에 더하기, sum을 총점에 포인터로 저장 
    2-1-2 과목수로 나누어 평균 구한 후 포인터로 저장
  2-2 main에서 함수 사용하기 
  
3. 함수 사용하여 학생별 총점과 평균점수, 등급 저장
  3-1 함수 만들기
    3-1-1 입력받은 배열로부터 학생을 기준으로 sum에 더하기, sum을 총점에 포인터로 저장 
    3-1-2 과목수로 나누어 평균 구한 후 포인터로 저장
    3-1-3 평균으로 조건에 알맞은 등급을 판별하여 저장 
  3-2 main에서 함수 사용하기 
4. 출력하기 


*/

void evalClass(int j[5][3], int i, int* s, float* a);
void evalStudent(int j[5][3], int i, int* s, float* a, char* g);

int main(void) {
  int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  int sum = 0;//총점저장용
  float avg;// 평균저장용
  char grade;// 등급저장용
  int i, j;// 반복문을 위한 변수
  FILE* data;

  // 이곳에 코드를 작성하라. 

  data = fopen("data.txt", "r");
  for(i = 0; i < 5; i++){
    for(j = 0; j < 3; j++){
      fscanf(data, "%d", &jumsu[i][j]); //파일에서 받아와서 배열에 저장 
    }
  }
  fclose(data);

  for(i=0;i<5;i++){ //학생별 점수 출력 
    printf("%d번 학생 : ",i+1); 
    for(j=0;j<3;j++){
      printf("%s %d", classname[j], jumsu[i][j]); 
      if(j<2) printf(", ");
      else printf("\n");
    }
  }

  printf("1) 각 과목별 총점과 평균점수\n"); //결과 출력 
  for(i=0;i<3;i++){
    evalClass(jumsu, i, &sum, &avg);
    printf("%s 점수의 총점은 %d 평균은 %.1f\n",classname[i],sum,avg); 
  }
  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n"); 
  for(i=0;i<5;i++){
    evalStudent(jumsu, i, &sum, &avg, &grade);
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n",i+1,sum,avg,grade); 
  }
  fclose(data);
  return 0; 
}

void evalClass(int j[5][3], int i, int* s, float* a){
  int k;
  *s = 0;
  for(k = 0; k < 5; k++){
     *s += j[k][i];
  }
  *a = *s / 5;
}
//파라미터 : 점수배열(j)과 과목번호(i=0,1,2), 총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a)
//수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균을 계산해 포인터 변수를 사용하여 저장함

void evalStudent(int j[5][3], int i, int* s, float* a, char* g){
  int k;
  *s = 0;
  for(k = 0; k < 3; k++){
     *s += j[i][k];
  }
  *a = *s / 3.0;

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

