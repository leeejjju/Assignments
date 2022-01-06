#include <stdio.h>
#include <string.h>
/*name.txt 파일에 대학의 학부이름이 영문으로 쓰여있다. 이 파일을 읽어서 학부 전체 개수와 가장 이름이 긴 이름과 가장 짧은 이름이 무엇인지 출력하라.

1. 파일 열기
2. 파일이 끝날때까지 한줄씩...
  2-1 파일의 한 줄을 line에 담기
  2-2 line의 길이(sizeof)로 max판별... max문자열 저장
  2-3 lnie의 길이로 min판별... min문자열 저장
3. 가장 긴 문자열과 짧은 문자열 출력 

*/

int main(void) {
  char line[200] = {0};
  char maxLine[200] = {0}, minLine[200] = {0};
  int max = 0, min = 999999, count = 0;

  //1. 파일 열기
  FILE* file;
  file = fopen("name.txt", "r");

  //2. 파일이 끝날때까지 한줄씩...

  while(!feof(file)){
    //2-1 파일의 한 줄을 line에 담기
    fgets(line, 200, file);
    line[strlen(line)-1] = '\0';
    //printf("line %d is %s, size of line is %d\n", count+1, line, (unsigned)strlen(line));

    //2-2 line의 길이(sizeof)로 max판별... max문자열 저장
    if(max < strlen(line)){
      max = strlen(line);
      strcpy(maxLine, line);
      //printf(" $$$now maxLine is %s$$$ \n\n", maxLine);
    }
    //2-3 lnie의 길이로 min판별... min문자열 저장
    if(min > strlen(line)){
      min = strlen(line);
      strcpy(minLine, line);
      //printf(" $$$now minLine is %s$$$ \n\n", minLine);
    }
    count ++;
  }

  //3. 가장 긴 문자열과 짧은 문자열 출력 
  printf("Count : %d\n", count);
  printf("Longest name : %s\n", maxLine);
  printf("Shortest name : %s", minLine);


  return 0;
}
