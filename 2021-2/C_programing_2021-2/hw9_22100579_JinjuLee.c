/*과제9) 달력 출력 프로그램  
어떤 월(month)의 1일의 요일(0 ? 6)과 날짜수를 입력으로 받아, 
달력을 출력하는 프로그램을 작성하시오.

예)  입력
     1일의 요일 : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) :  3
     Number of days :  31
<출력>
    Sun    Mon    Tue    Wed    Thu   Fri    Sat
                           1      2      3      4
      5      6       7        8      9     10     11
     12     13     14       15     16     17     18
     19     20     21       22     23     24     25
     26     27     28       29     30     31
      
     */
     
#include <stdio.h>

int main(void){
	
	int yoil, numOfDays;
	int i, count;
	
	printf("1일의 요일 : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) :  ");
	scanf("%d", &yoil);
	
	printf("Number of days :  ");
	scanf("%d", &numOfDays);
	
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
