//C실습 과제5

//어떤 주어진 일자(y년 m월 d의 다음 날을 구하는 프로그램
// 입출력 예시  2020 9 15 >> 2020 9 16/ 2019 2 28 >> 2019 3 1 

#include <stdio.h>

int main(void){
	
	int year, month, day;
	int endDay; //각 월의 끝날을 저장할 공간  
	
	printf("년 월 일을 입력해주세요 : ");
	scanf("%d %d %d", &year, &month, &day);
	
	
	if( month == 12 && day== 31 ){ //연말일경우 년도 증가  
		year += 1;
		month = 1;
		day = 1;
		
		printf("\n다음날 : ");
		printf("%d %d %d", year, month, day);
		
	}else{
		if( month == 2){ //2월의 경우  
			if(year%4 == 0 && year%100 != 100){ //윤년판별 
				endDay = 29;
			}else{
				if(year%400 == 0){
					endDay = 29;
				}
				endDay = 28;
			}
		}else if((month%2 == 0 && month < 7)||(month%2 != 0 && month >= 7)){ //30일까지인 경우  
			endDay = 30;
		}else{ //월이 홀수일때  
			endDay = 31;
		}
	
		if( day == endDay){ //월말인 경우  
			month += 1;
			day = 1;
			printf("\n다음날 : ");
			printf("%d %d %d", year, month, day);
			
		}else{
			if(day > endDay || month > 12){
				printf("잘못 입력하셨습니다.");
			}else{
				day += 1;
				printf("\n다음날 : ");
				printf("%d %d %d", year, month, day);
			}
	
		}
		
	}
	
	return 0;
}
