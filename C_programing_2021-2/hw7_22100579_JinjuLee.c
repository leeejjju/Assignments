/*과제7)1 ~ n (n>1) 범위의 정수 중에서 완전수( perfect number)를 모두 찾으시오.


- 완전수 : 어떤 수(n)가, n을 제외한 모든 약수의 합과 같은 경우
Ex)  6 = 1 + 2 + 3*/


#include <stdio.h>

int main(void){
	
	int num, sum = 0, i, j;
	printf("완전수를 찾을 범위를 입력하세요: ");
	scanf("%d", &num);
	
	for(i = 1; i <= num ; i++){ //1부터 num까지 완전수 판별 스캔 
		
		for(j = 1; j <= i; j++ ){ //완전수 판별에 사용될 약수의 합(자기자신 제외) 구하기  
			if(i%j == 0){
				sum += j;
			}
		}
		
		if(sum == i){ //완전수 판별하여 출력하기  
			printf("%d ", i);
		} 
		
		sum = 0; //sum 초기화  
	}
	
	return 0;
}
