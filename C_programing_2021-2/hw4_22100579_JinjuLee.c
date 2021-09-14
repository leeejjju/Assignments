//C실습 과제4

//어떤 주어진 일자(y년 m월 d의 다음 날을 구하는 프로그램
// 입출력 예시  2020 9 15 >> 2020 9 16/ 2019 2 28 >> 2019 3 1 

#include <stdio.h>

int main(void){
	
	int year, month, day;
	int endDay; //각 월의 끝날을 저장할 공간  
	
	printf("년 월 일을 입력해주세요 : ");
	scanf("%d %d %d", &year, &month, &day);
	
	
	switch (month){ //각 월의 마지막날을 정해줌  
		
		case 2 :  if(year%4 == 0 && year%100 != 100){ //윤년판별 
					  endDay = 29;
				  }else{
					  if(year%400 == 0){
						  endDay = 29;
					  }
				  	  endDay = 28;
			  	  }
				  break;
			
		case 4 :
		case 6 :
		case 9 :
		case 11 : endDay = 30;
				  break;
		
		default : endDay = 31;
				  break;
	}
	
	
	if( month == 12 && day== 31 ){ //연말일경우 년도 증가  
		year += 1;
		month = 1;
		day = 1;
		
		printf("\n다음날 : ");
		printf("%d %d %d", year, month, day);
		
	}else{
		
		if( day == endDay){ //월말일 경우  
			month += 1;
			day = 1;
			printf("\n다음날 : ");
			printf("%d %d %d", year, month, day);
	
		}else{ 
			if(day > endDay || month > 12){ //바르지 않은 날짜를 입력시  
				printf("잘못 입력하셨습니다.");
			}else{ //올바른 날짜를 입력시 날짜를 +1  
				day += 1;
				printf("\n다음날 : ");
				printf("%d %d %d", year, month, day);
			}	
			
		}		
		
	}	
	return 0;
}
