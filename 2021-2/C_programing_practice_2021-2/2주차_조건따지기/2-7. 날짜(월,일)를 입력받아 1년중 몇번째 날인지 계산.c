#include <stdio.h>

int main(void) {
  int month, day;   // 월, 일
  int day_count = 0;    // 1년 중 날 수 
  int i;

  printf("Month? ");
  scanf("%d", &month);
  printf("Day? ");
  scanf("%d", &day);
  
  //각 월에 맞는 적당한 날 수 더하기 
  for(i = 2; i <= month ; i++){
    if(i-1 == 2){
      day_count += 28;
    }else if((i-1) % 2 == 0){//짝수일때
      if(i-1 > 6){
        day_count += 30; 
      }else{
        day_count += 31;      
      }
    }else{ //홀수일때 
      if(i-1 > 6){
        day_count += 31;     
      }else{
        day_count += 30;  
      }
    }
  }

  day_count += day + 1;
  
  //잘못된 날 입력시 에러메세지 띄우기 
  if(month > 12 || day > 31){
    printf("잘못 입력하셨습니다.");
  }else{
    if( month == 2){
      if(day > 28){
        printf("잘못 입력하셨습니다.");
      }else{
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
      }
    }else if((month%2 == 0 && month > 7)||(month%2 != 0 && month < 7)){
      if(day > 30){
        printf("잘못 입력하셨습니다.");
      }else{
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
      }
    }else{
      printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
  }






 // printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
  return 0;
}
