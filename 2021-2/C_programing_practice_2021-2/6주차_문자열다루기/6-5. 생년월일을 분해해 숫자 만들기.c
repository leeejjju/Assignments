#include <stdio.h>
#include <string.h>
/*YYYYMMDD 순서로 되어 있는 8자리 포맷의 생년월일을 분해하여 숫자로 만들어보려고 한다. 4자리의 연도에 해당 되는 각각의 숫자 4개를 더한 후에, 이 값에 월, 일에 해당하는 숫자를 모두 더한 값을 찾아내도록 하라.

예를 들어 "19990311" 인 경우에 년도의 1+9+9+9를 더한 28과, 월에 해당하는 3, 일에 해당하는 11을 모두 더해서 28+3+11=42를 출력하면 된다.

8자리의 문자열 1개를 입력받는다. (단, 문자열은 숫자로만 구성되어 있다.)

이 중 년도에 해당하는 숫자 4개를 알아내어 모두 더한다. 월과 일에 해당하는 숫자를 알아낸다. 3개의 숫자를 모두 더한 값을 출력한다.*/

int main(void) {

  char input[8]; //생년월일은 입력받을 공간 
  int sum = 0; //벌스데이넘버..? 
  int i, j; //반복문 사용을 위한 변수 
  int num; //계산을 보조할 변수 
  //48(0)~57(9)


  printf("Enter your birthdate >> ");
  scanf("%s", input);

    
  for(i = 0; i < 4; i++){
    sum += input[i] - 48;
  }
 
  num = (input[4]-48)*10 + (input[5]-48);
  sum += num;

  num = (input[6]-48)*10 + (input[7]-48);
  sum += num;



  printf("Your birthdate number is %d.", sum);

  return 0;
}

