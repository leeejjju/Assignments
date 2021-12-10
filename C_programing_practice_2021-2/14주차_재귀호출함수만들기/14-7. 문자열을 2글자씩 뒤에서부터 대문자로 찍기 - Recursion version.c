#include <stdio.h>
#include <string.h>
/*다음과 같이 문자열을 한 줄 입력받은 후에 해당 문자열을 2글자씩 뒤에서부터 대문자로 찍는 프로그램을 완성하라.

즉, 짝수개의 문자열인 경우에는 맨 마지막 2개 글자를 가장 먼저 찍게 되고, 홀수개의 문자열인 경우에는 맨 마지막의 1개 글자를 가장 먼저 찍게 될 것이다. 단, 알파벳 문자는 반드시 대문자로 바꿔서 찍어야 한다.

단, main()은 수정불가하며, rPrint() 함수는 반드시 재귀함수로 구현해야 한다.*/

void rPrint(char* str);
void changeUpper(char* str);

int main(void) {
	char str[80];
	printf("Enter a string >>");

	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
  
  changeUpper(str);
	rPrint(str);

	return 0;
}

//--------------------------------------------------------
void changeUpper(char* str){
  for(int i = 0 ; i < strlen(str); i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] -= 32;
    }
  }
}
//대문자인지 판별하고 대문자로 바꿔주기 




void rPrint(char* str){

  if(strlen(str) <= 2){
    printf("%s", str);
    return; 
  }else{
    rPrint(&str[2]);
    printf("%c%c", str[0], str[1]);
  }
}
//파라미터 : 문자열 (문자열의 첫문자 주소)
//수행내용 : 만일 입력받은 문자열의 길이가 2 이하인 경우 바로 출력한다. 그 외의 경우에는 3번째 글자부터 시작하는 문자열을 파라미터로 rPrint()를 호출한 후, 처음 2글자를 출력한다.
