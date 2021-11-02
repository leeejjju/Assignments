/*1101코딩T_04)_22100579
4. 어떤 주어진 임의의 날짜가 그해의 몇번째 날인지 산출하는 프로그램을 작성하시오.
(단 2월의 날짜수는 28일로 산정할 것 )
*/
#include <stdio.h>

int main(void){
	
	int month, day;
	int i, sum = 0; //여기다 모든걸 더해보고자 합니다...  
	
	printf("날짜를 입력하세요(M D) : ");
	scanf("%d %d", &month, &day);
	

	if(month != 1){
		for(i = 1; i < month; i++){ //월에 해당하는 일수를 더하는 반복문  
			if(i == 2){  
				sum += 28;
			}else if((i == 4 || i == 6) || (i == 9 || i == 11)){ //30일짜리 월들  
				sum += 30;
			}else{
				sum += 31;
			}
		}	
	}

	sum += day;	
	printf("%d", sum);	
	
	return 0;
}
   
