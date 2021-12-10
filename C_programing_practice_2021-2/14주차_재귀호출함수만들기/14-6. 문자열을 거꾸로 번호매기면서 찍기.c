#include <stdio.h>
#include <string.h>
/*다음과 같이 문자열을 한 줄 입력받은 후에 해당 문자열을 거꾸로 번호 매겨 찍는 프로그램을 완성하라.

단, rPrint() 함수는 반드시 재귀함수로 구현해야 한다.
void rPrint(char* str, int n);
파라미터 : 문자열 str, 순서값(문자열의 갯수와 같은 의미) n
문자열의 임의의 문자를 가리키는 포인터와 순서값을 파라미터로 받는다.
rPrint()를 이용해 해당 문자 이후의 문자열에 대한 작업 수행 후에, 해당 문자를 번호와 함께 출력한다.*/


void rPrint(char* str, int n);

int main(void) {
	char str[80];
	printf("Enter a string >> ");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	rPrint(str, strlen(str));
	return 0;
}

void rPrint(char* str, int n){
  static int count = 1;
  if(n == 0){
    printf("%2d. %c", count, str[n-1]);
    return;
  }else{
    printf("%2d. %c\n", count, str[n-1]);
    count += 1;
    rPrint(str, n-1);
    //////////////카운트가 왜 안 증가할까??
  }
}
//파라미터 : 문자열 str, 순서값(문자열의 갯수와 같은 의미) n
//문자열의 임의의 문자를 가리키는 포인터와 순서값을 파라미터로 받는다.
//rPrint()를 이용해 해당 문자 이후의 문자열에 대한 작업 수행 후에, 해당 문자를 번호와 함께 출력한다.
