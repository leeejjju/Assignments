#include <stdio.h>
#include <string.h>
/*문장을 하나 입력받은 후에, 이 문장 속에서 white space가 아닌 문자의 갯수를 세라.
단, 주어진 함수를 반드시 재귀함수로 구현한 후, 사용할 것. 
main() 수정금지!*/

int rStrlen(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("length : %d\n", rStrlen(line));
	return 0;
}

//------------------이후로만 수정 가능


int rStrlen(char* str){

  if(strlen(str) == 1){
    /*if(str[0] != ' '){
      printf("1\n");
      return 1;
    }else{
      printf("2\n");
      return 0;
    }*/
    return 0;

  }else{
    if(str[0] != ' '){
      //printf("3\n");
      return 1 + rStrlen(&str[1]);
    }else{
      //printf("4\n");
      return rStrlen(&str[1]);
    }
  }

}
//파라미터 : 개수를 세어야 하는 문자열의 시작 포인터
//리턴값 : 이 포인터로부터 문자열의 끝까지 들어있는 공백제외 문자 갯수
//힌트: 문자열의 문자 갯수는 현재 글자 바로 뒤부터 시작하는 문자열의 문자 갯수를 센 후, 1을 더한다.
