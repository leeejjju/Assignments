#include <stdio.h>
#include <string.h>
/*데이터 파일(data.txt)로부터 문장을 읽어 전체 텍스트 파일에 포함된 소문자, 대문자의 수, 빈칸의 수를 구하라.

1. 파일 열기
2. 파일로부터 한줄씩 읽어내리며...
  2-1 라인에 해당 줄을 담기
  2-2 해당 라인의 문자열을 한자씩 검사하며...
    2-2-1 대문자면 대문자카운트 증가
    2-2-2 소문자면 소문자카운트 증가
    2-2-3 빈칸이면 빈칸카운트 증가
3. 분석 결과 출력 
*/


int main(void) {
  int countUp = 0; //대문자 수 
  int countLow = 0; //소문자 수
  int countSpace = 0; //빈칸 수
  char line[100];

  //1. 파일 열기
  FILE* file;
  file = fopen("data.txt", "r");

  //2. 파일로부터 한줄씩 읽어내리며...
  while(!feof(file)){
    //2-1 라인에 해당 줄을 담기
    fgets(line, 100,file);

    //2-2 해당 라인의 문자열을 한자씩 검사하며...
    for(int i = 0; i < strlen(line); i++){

      //2-2-1 대문자면 대문자카운트 증가
      if(line[i] >= 'A' && line[i] <= 'Z'){
        countUp ++;
      }else if(line[i] >= 'a' && line[i] <= 'z'){ //2-2-2 소문자면 소문자카운트 증가
        countLow ++;
      }else if(line[i] == ' '){//2-2-3 빈칸이면 빈칸카운트 증가
        countSpace ++;
      }
    }
  }
  //3. 분석 결과 출력 
  printf(">> 대문자 : %d개, 소문자 : %d개, 공백 : %d개", countUp, countLow, countSpace);
  
  return 0;
}
