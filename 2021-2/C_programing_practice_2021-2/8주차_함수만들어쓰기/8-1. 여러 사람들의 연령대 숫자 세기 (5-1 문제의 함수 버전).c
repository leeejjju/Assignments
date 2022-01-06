#include <stdio.h>
/*최대 100명까지 사람들의 태어난 년도를 입력받아 그 값을 배열로 저장하되, 2020보다 큰 년도가 입력되기 전까지 태어난 년도를 반복하여 입력받도록 하라. 이 때, 생년을 받아서 연령대 번호를 리턴하는 함수를 만들어 사용하라.

int ageToGroup(int b);

파라미터 : 태어난 년도 (b)
리턴값:연령대에따른번호-유아0,어린이1,청소년2,청년3,중년4, 노년5
수행내용 : 태어난 년도를 통해 연령대를 계산하고, 연령대에 따른 번호 리턴

반복이 끝나면 지금까지 입력된 사람들의 각자 나이를 계산하여 출력하고, 나이에 따라 유아, 어린이, 청소년, 청년, 중년, 노년 여부를 판정하여 이 중 에 유아, 어린이, 청소년, 청년, 중년, 노년이 각각 몇 명인지 출력하라.

단, 나이 = 올해년도 ? 태어난 년도 + 1 로 계산하고 연령대 구분은 다음과 같이 판정한다.

7세 미만 : 유아
7세 이상 ~ 13세미만 : 어린이
13세 이상 ~ 20세 미만 : 청소년
20세 이상 ~ 30세 미만 : 청년
30세 이상 ~ 60세 미만 : 중년
60세 이상 : 노년*/

int ageToGroup(age){
  int ageNum; //연령대에 따른 번호-유아0,어린이1,청소년2,청년3,중년4, 노년5

  if(age < 7){
    ageNum = 0;
  }else if(age < 13){
    ageNum = 1;
  }else if(age < 20){
    ageNum = 2;
  }else if(age < 30){
    ageNum = 3;
  }else if(age < 60){
    ageNum = 4;
  }else{
    ageNum = 5;
  }

  return ageNum;
}
 
int main(void) {

  int birth_year;     // 입력받은 태어난 년도
  int year[100];      // 각 사람들의 생년 (최대 100명)  
  int count_person = 0;   // 입력된 인원 수
  int count[6] = {0};       // 6가지 연령대별 숫자
  int i; //반복문 사용을 위한 변수 
  int age; //나이를 계산할 변수 

  while(birth_year <2021){
    printf("%d번째 사람의 태어난 년도를 입력하시오. ", count_person+1);
    scanf("%d", &birth_year);
    year[count_person] = birth_year;
    count_person++;
  }

  for(i = 0; i < count_person-1; i++ ){
    age = 2021 - year[i] + 1;
    printf("%d번째 사람의 나이는 %d입니다.\n", i+1, age);
    count[ageToGroup(age)] ++;
  }

  printf("유아는 %d명입니다.\n", count[0]);
  printf("어린이는 %d명 입니다.\n", count[1]);
  printf("청소년은 %d명 입니다.\n", count[2]);
  printf("청년은 %d명 입니다.\n", count[3]);
  printf("중년은 %d명 입니다.\n", count[4]);
  printf("노년은 %d명 입니다.\n", count[5]);
 
 return 0;
}

