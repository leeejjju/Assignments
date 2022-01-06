/* 과제8) 구구단 출력 program
입출력 예)
Select a column of multiplication table : 7
*끝자리맞추기?  

7 * 1 =  7
7 * 2 = 14
7 * 3 = 21
7 * 4 = 28
7 * 5 = 35
7 * 6 = 42
7 * 7 = 49
7 * 8 = 56
7 * 9 = 63 */

#include <stdio.h>

int main(void){
	
	int num;
	int i, j;
	
	printf("Select a column of multiplication table : ");
	scanf("%d", &num);
	printf("\n\n"); 
	
	for(i = 1; i <= 9; i++){
		
		printf("%d x %d = %.2d\n", num, i, (num*i));
		
	}
	
	
	return 0;
}


