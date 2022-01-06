/*실습 과제6: 주어진 두 개의 정수(n1, n2)에 대한 최대 공약수를 구하는 프로그램을 작성하시오.*/


#include <stdio.h>

int main(void){
	
	int num1, num2, k;
	
	scanf("%d %d", &num1, &num2); //두 수를 입력받기  
	
	k = (num1 > num2)? num2 : num1; //둘중 작은 값을 k 초기값 설정  
	
	while(k > 0){ //k를 하나씩 줄여가며 k가 두 수의 공약수인지 검토  
		if(num1%k == 0 && num2%k == 0){ //k가 둘의 공약수이면 출력후 종료  
			printf("최대공약수는 %d", k);
			break; 
		}
		k--; //아니면 k를 1 감소시키며 반복  
	}
	
	
	return 0;
}
