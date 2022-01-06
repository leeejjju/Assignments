#include <stdio.h>
#include <stdlib.h>
/*데이터 파일로부터 학생들의 국어, 영어, 수학 점수를 입력받아 다음 항목들을 계산하여 출력하라.
1) 각 과목별 총점과 평균 점수
2) 각 학생별 총점과 평균점수, 평균에 따른 등급

파일로부터 점수를 읽어와서 목록을 만들어내는 과정은 함수를 통해 동적으로 메모리를 할당받아 진행하라.
학생별 총점과 평균, 등급 계산은함수를 제작하여 사용하라.
과목별 총점과 평균 계산은 함수를 제작하여 사용하라.

등급은 다음과 같은 기준으로 결정하라.
평균 90이상 : A
평균 80이상 ~ 90미만 : B
평균 70이상 ~ 80미만 : C
평균 60이상 ~ 70미만 : D
평균 60미만 : F

제공된 소스 main() 수정 금지*/

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

int loadJumsu(struct st_jumsu* p[], char* filename);
void evalScore(struct st_jumsu* p);
void evalClass(struct st_jumsu* p[], int sum[], float avg[],int count);

int main()
{
    struct st_jumsu* jumsu[10]; 	// 최대 10명의 점수 저장용 포인터 배열 
    int count; // 점수 개수
    int classsum[3]; 			// 과목별 총점
    float classavg[3]; 			// 과목별 평균
    char classname[3][20]={"국어","영어","수학"};
    count = loadJumsu(jumsu, "data.txt");
    for(int i=0;i<count;i++)
        evalScore(jumsu[i]);
    evalClass(jumsu, classsum, classavg, count);
    printf("1) 각 과목별 총점과 평균점수\n");
    for(int i=0;i<3;i++)
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i],classsum[i], classavg[i]);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for(int i=0;i<5;i++)
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    return 0;
}

int loadJumsu(struct st_jumsu* p[], char* filename){
  int count = 0;

  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    p[count] = malloc(sizeof(struct st_jumsu));
    int r = fscanf(file, "%d %d %d", &p[count]->kor,  &p[count]->eng,  &p[count]->mat);
    if(r < 3){
      break;
    }else{
      count++;
    }
  }

  fclose(file);
  printf("%d명의 점수를 읽었습니다.\n", count);
  return count;
}
// 파라미터 : 점수목록을 저장할 구조체 포인터 배열, 데이터파일 이름
// 리턴값 : 만들어낸 점수 배열
// 수행내용 : 파일을 읽으면서 점수 구조체를 동적 메모리 할당을 통해 만들고 국어, 영어, 수학 점수를 입력받아 저장한 후, 만들어낸 점수목록의 개수를 리턴함

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
// 파라미터 : 학생의 점수 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 구조체 포인터를 받아 학생별 총점과 평균, 등급 계산하여 저장

void evalClass(struct st_jumsu* p[], int sum[], float avg[], int count){

  sum[0] = sum[1] =sum[2] =0;

  for(int i = 0; i < count; i++){
    sum[0] += p[i]->kor;
    sum[1] += p[i]->eng;
    sum[2] += p[i]->mat;
  }
  
  for(int i = 0; i < 3; i++){
    avg[i] = sum[i]/count;
  }
  
}
// 파라미터 : 점수목록(구조체 포인터 배열), 과목별 총점 배열, 과목별 평균 배열, 학생수 
// 리턴값 : 없음
// 수행내용 : 점수목록을 받아 3개의 과목별 총점과 평균을 계산하여 저장한다.
