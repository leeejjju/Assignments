/*과제10) 요일 출력 프로그램

임의의 날짜(년,월,일)에 대하여 요일을 알아내는 프로그램을 작성하시오.
(1900년 1월 1일 이후만 고려)
예)  입력 : 2021 9  30    
     출력 :  Thursday

필요한 논리(예)
  - y년 m월 d일이면, 
           1900년 ~ ( y ? 1) 년까지 날짜 수 +
           y년  1월 ~ (m-1) 월까지 날짜수 +
           (d-1) 의 합에   7로 나눈 나머지 값을 조정. 

  - 평년은 365일이고,    365 % 7 = 1 이므로 1년이 지나면 요일이 1 증가
  - 윤년은 366일이므로    366 % 7 = 2 이므로 1년이 지나면 요일이 2증가
  */
  
  //1900년 1월 1일은 월요일이었따! 
  //월~일 = 0~6 
  
#include <stdio.h>

int main(void){
	
	int year, month, day, yoil = 0;
	int i, sum = 0; //여기다 모든걸 더해보고자 합니다...  
	
	printf("날짜를 입력하세요(Y M D) : ");
	scanf("%d %d %d", &year, &month, &day);
	
	i = year - 1900;
	
	while(1){ //년도에 해당하는 일수를 더하는 반복문 
		
		if(i == 0){ //루프 탈출 조건  
			break;
		}
		
		if((i%4 == 0 && i%100 != 100)|| i%400 == 0){ //윤년판독, 윤년일 때  
			sum += 366;
		}else{ //평년일 떄  
			sum += 365;
		}		
		
		i --;	
	}
	
	if(month != 1){
		for(i = 1; i < month; i++){ //월에 해당하는 일수를 더하는 반복문  
			if(i == 2){ //또 윤년판독...  
				if((i%4 == 0 && i%100 != 100)|| i%400 == 0){ //윤년판독, 윤년일 때  
					sum += 29;
				}else{ //평년일 떄  
					sum += 28;
				}
			}else if((i == 4 || i == 6) || (i == 9 || i == 11)){ //30일짜리 월들  
				sum += 30;
			}else{
				sum += 31;
			}
		}	
	}

	
	sum += day;
	yoil = sum % 7 - 1;
	
	
	if(yoil == 0){ //출력..ㅋㅋ... 
		printf("Monday"); 
	}else if(yoil == 1){
		printf("Tuesday"); 
	}else if(yoil == 2){
		printf("Wednesday"); 
	}else if(yoil == 3){
		printf("Thursday"); 
	}else if(yoil == 4){
		printf("Friday"); 
	}else if(yoil == 5){
		printf("Saturday"); 
	}else{
		printf("Sunday"); 
	}
	
	
	
	return 0;
}
   
