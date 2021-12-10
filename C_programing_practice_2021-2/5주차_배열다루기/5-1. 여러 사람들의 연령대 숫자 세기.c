#include <stdio.h>

  int main(void) {

  int birth_year;       // 입력받은 태어난 년도
  int year[100];        // 각 사람들의 생년 (최대 100명) 
  int count_person = 0;     // 입력된 인원 수
  int count_baby = 0;       // 유아 수
  int count_child = 0;      // 어린이 수
  int count_youth = 0;      // 청소년 수
  int count_young = 0;      // 청년 수
  int count_adult = 0;      // 중년 수
  int count_old = 0;        // 노년 수
  int i = 1;                // 반복문, 인덱스를 위한 변수 

  while(1){ 
  
  printf("%d번째 사람의 태어난 년도를 입력하시오. ", i);
  scanf("%d", &birth_year);

  if(birth_year > 2021){
    break;
  }

  year[i] = 2021 - birth_year + 1; //각 사람의 나이 저장 

  if(year[i] >= 60){ //나이에 따라 연령대 카운트 누적 
    count_old ++;
  }else if(year[i] >= 30){
    count_adult ++;
  }else if(year[i] >= 20){
    count_young ++;
  }else if(year[i] >= 13){
    count_youth ++;
  }else if(year[i] >= 7){
    count_child ++;
  }else{
    count_baby ++;
  }

  i++; //인덱스 증가 
  count_person ++; //총인구수 누적 

  
  }


  for( i = 1; i < count_person+1; i++ ){ //저장된 정보 출력 
    printf("%d번째 사람의 나이는 %d입니다.\n", i, year[i] );
  }

  printf("유아는 %d명입니다.\n", count_baby);
  printf("어린이는 %d명입니다.\n", count_child);
  printf("청소년은 %d명입니다.\n", count_youth);
  printf("청년은 %d명입니다.\n", count_young);
  printf("중년은 %d명입니다.\n", count_adult);
  printf("노년은 %d명입니다.", count_old);



  return 0;
}
