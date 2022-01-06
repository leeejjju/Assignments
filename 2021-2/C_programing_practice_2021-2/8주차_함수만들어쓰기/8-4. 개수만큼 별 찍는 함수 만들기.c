#include <stdio.h>
/*파라미터로 숫자 하나를 넘겨주면 이 숫자만큼 별('*')을 화면에 출력하는 함수를 만들어라. 그리고 사용자로부터 10 개의 숫자를 입력받은 후, 이 함수를 사용해서 10줄에 걸쳐서 그 숫자만큼의 별을 화면에 출력시켜라.

함수 원형은 다음과 같다.

void PrintStar(int size);

파라미터:size : 출력할 별의 개수

리턴값 : 없음

수행내용 : size 개수만큼 '*' 문자 출력 후 개행*/

void PrintStar(size){
  int i;
  for( i = 0; i < size; i++){
    printf("*");
  }
  printf("\n");
}

int main(void) {
  int size[10];
  int i;

  printf("숫자 10개를 입력 ");

  for(i = 0; i < 10; i++){
    scanf("%d", &size[i]);
  }

  for(i = 0; i < 10; i++){
    PrintStar(size[i]);
  }


  return 0;
}
