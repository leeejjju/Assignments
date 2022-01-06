#include <stdio.h> 
/*
다음과 같이 5명의 학생들에게 10문제의 답을 입력받아, 이를 채점하여 등급을 매기는 작업을 하는 프로그램을 작성하라. 학생별로 10개씩의 답안을 입력받은 후에, 각 등급별 학생 이름과 인원수를 출력하라.

단, 10문제의 정답은 미리 코드에 제시된 그대로 사용하라.

등급은 다음과 같이 결정한다.

1st : 9~10문제 맞춘 경우

2nd : 7~8문제 맞춘 경우

Fail : 6문제 이하로 맞춘 경우
*/

int main(void) {
  int i,j; // 반복문을 위한 변수
  int jumsu = 0; // 점수 계산용 점수
  int count = 0; // 인원수 계산용 변수
  char names[5][20]={"James", "David", "Simon", "Peter", "Jason"}; // 학생 이름 
  int sheet[5][10]; // 학생별 답안내용
  int answer[10]={1,2,3,4,1,2,3,4,3,2}; // 정답순서
  int grade[5] = {3}; // 학생별 등급 

  for(i=0;i<5;i++){
    printf("Enter %s's sheet >> ", names[i]); 
    for(j=0;j<10;j++)
      scanf("%d", &sheet[i][j]); //i번째학생의답안10개입력
  }

  // 이 부분에 코드를 작성할 것!


 for(i=0;i<5;i++){ 
    
    for(j=0;j<10;j++){ //채점하기 
      if(answer[j] == sheet[i][j]){
        jumsu ++;// 맞을때마다 점수 증가 
      }
    }

    if(jumsu > 8){ //등급판별, 배열에 해당 학생의 인덱스 저장 
      grade[i] = 0;//1등급

    }else if(jumsu > 6){
      grade[i] = 1;//2등급

    }else{
      grade[i] = 2;//저런...
    }

    jumsu = 0;//점수 초기화 

  }


  printf("\nGrade result\n");//결과출력 

  for(i = 0; i < 3; i++){ 

    if(i == 0){
      printf("1st : ");
    }else if(i == 1){
      printf("2nd : ");
    }else{
      printf("Fail : ");
    }

    for(j = 0; j < 5; j++){
      if(grade[j] == i){
        printf("%s ", names[j]);
        count++;
      }
    }

    printf("(%d)\n", count);
    count = 0;

  }

  

  return 0; 
}


