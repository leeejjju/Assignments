#include <stdio.h>

int main(void) {
  
  int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};;        // 1~12월의 날 수 
  int month, day;           // 입력받은 월, 일
  int day_count = 0;            // 1년 중 날 수
  int i;                    // 반복문을 위한 변수 

  printf("Month? ");
  scanf("%d", &month);
  printf("Day? ");
  scanf("%d", &day);

  if(month <= 12 && day <= monthdays[month-1]){
    for(i = 0; i < month -1; i++){ //입력한 이전 월까지의 수를 모두 더하기
    day_count += monthdays[i];
    }
  day_count += day; //날 수 더해주기 
  printf("이 날짜는 1년 중 %d번째 날에 해당", day_count);
  }else{
    printf("잘못 입력하셨습니다.");
  }
  

  return 0;
}
