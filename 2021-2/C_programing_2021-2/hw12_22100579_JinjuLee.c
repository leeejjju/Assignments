/*과제12) 입력받은 달의 달력 출력하기
임의의 년, 월 (년 월 값 입력)에 대한 달력을 출력하는 program을 작성하시오.
*/
 
#include <stdio.h>

int main(void){
	int year, month, yoil, numOfDays;
	int i, sum = 0, count = 0;
	
	printf("년도와 달을 입력하세요 (Y M) : ");
	scanf("%d %d", &year, &month);
	
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
					numOfDays = 29;
				}else{ //평년일 떄  
					sum += 28;
					numOfDays = 28;
				}
			}else if((i == 4 || i == 6 ) || ( i == 9 || i == 11)){ //30일짜리 월들  
				sum += 30;
				numOfDays = 30;
			}else{
				sum += 31;
				numOfDays = 31;
			}
		}	
	}
	
	sum += 1; //1일을 상정하므로  
	yoil = sum % 7;
	
	
	int days[numOfDays];
	for(i = 0; i<numOfDays; i++){ //배열에 날짜 값 저장하기  
		days[i] = i+1;
	}
	
	count = yoil + 1; //요일에 따른 카운트의 초기값 설정(1~7) 
	
	printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");
	
	for(i = 0; i < yoil; i++){
		printf("       ");
	}
	
	i = 0;
	
	while(1){ //달력의 한 줄 
	
		if(i > numOfDays - 1){ //탈출조건  
			break;
		} 
		
		printf("%2d     ", days[i]); 
			
		if(count%7 == 0){ //줄바꿈   
			printf("\n");	
		}	
		
		count ++;
		i ++;		
	} 

	
	return 0;
}
