/*문제4) 한 개의 정수 값(년도)를 입력으로 받아,
윤년인지 여부를 판단하는 프로그램을 작성하시오.
-(참고) 윤년(leap year) 여부 판단
?    4의 배수이면 윤년
?    100의 배수이면 윤년이 아님
?    400의 배수이면 윤년*/

#include <stdio.h>

int main(void){
	
	int year, isIt;
	
	printf("year? : ");
	scanf("%d", &year);
	
	if(year%4 == 0 && year%100 != 0){ //4의배수면서 100의 배수는 아닌 것 = 윤년  
		isIt = 1;
	}else if(year%400 == 0){ //400의 배수 = 윤년  
		isIt = 1;
	}else{ 
		isIt = 0;
	}
	
	printf("%d", isIt); //결과 출력  
	
	
	return 0;
}
