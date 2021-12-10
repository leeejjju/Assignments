#include <stdio.h>
#include <string.h>
/*한 문장을 입력받은 후에 이 문장 속 가장 긴 단어와 그 길이를 구하라.

이를 위해 문장을 나타내는 변수(char* 타입)를 전달하여 이 문장을 이루고 있는 단어들 중 가장 긴 단어를 찾아, 이 단어의 첫글자부터 시작되는 문자열을 리턴하는 함수를 만들어 사용하라.*/


char* findLongestWord(char* str);

int main(void) {

  char line[100];     // 입력받을 문장 
  printf("문장 입력 > ");
  fgets(line, 100, stdin); 
  line[strlen(line)-1]='\0'; //엔터 제거

  // 이곳에 코드를 작성하라
  //넵,.... 

  printf("결과 > %s 중에 가장 긴 단어는 ", line);

  int count = 0; //가장 긴 단어 글자수 셀 변수 
  while(findLongestWord(line)[count] != ' ' && findLongestWord(line)[count] != '\0'){ //가장 긴 단어 출력 
    printf("%c",findLongestWord(line)[count] );
    count ++;
  }

  printf(", 길이 %d입니다.",  count);


  

  return 0;
}

char* findLongestWord(char* str){
  int count = 0; //각 단어의 글자수를 셉니다...
  int maxLen = 0, maxINdex = 0; //가장 긴 길이와... 그놈 단어의 시작위치를 저장합니다... 
  int i; //반복문... 
  //char max[100] = {'\0'}; //가장 긴 길이로 시작하는 문자열... 

  for(i = 0; i < strlen(str); i++){
    if(str[i] != ' '){ //띄어쓰기가 아니라면, 즉 단어 중간일때는 
      count++; //열심히 글자수세기 
    }else{ //띄어쓰기를 만나면 
      if(maxLen < count){ //지금껏 센 글자수가 최대인지 판별 
        maxLen = count; //최대면.. 새로운 거시기 값에 임명되고 
        maxINdex = (i - count); //그놈의 위치도 갱신 
      }
      count = 0;  //글고 다음단어 세기 위해서 카운트 초기화 
    }
  }

  return &str[maxINdex];
}
//파라미터 : 전체 문장 (str)
//리턴값 : 가장 긴단어로 시작되는 문장
//수행내용 : 문장 중에서 가장 긴 단어가 시작되는 위치의 문자열

