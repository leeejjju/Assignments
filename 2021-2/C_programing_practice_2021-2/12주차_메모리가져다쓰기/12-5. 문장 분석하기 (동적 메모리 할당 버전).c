#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*데이터파일(data.txt)로부터 텍스트 파일로부터 길이가 다른 여러 개의 문장을 읽어와서 이 중 가장 긴 문장과 짧은 문장의 번호와 내용을 출력하라.

단, 문장을 저장하는 문자열은 포인터로 선언하여 메모리를 동적으로 할당받도록 하라. (ch12_03.c 예제소스를 참고하라.)*/

int main(void) {
  char* pstr[20]; // 실제로 저장될 최대 20개의 문장을 위한 포인터 배열 
  char* longest;  // 가장 긴 문장을 가리키는 포인터
  char* shoetest;	// 가장 짧은 문장을 가리키는 포인터
  int max = 0, min = 99999999;
  int maxIndex, minIndex;
  int count = 0;

  FILE* file;
  file = fopen("data.txt", "r");

  while(!feof(file)){
    pstr[count] = malloc(sizeof(char)*200); //count번째 포인터에 200자까지 들어가는 문자열 주소 저장함 
    fgets(pstr[count], 200, file); //글고 거기다가 한줄 읽어서 저장
    if(pstr[count][strlen(pstr[count])-1] == '\n'){
      pstr[count][strlen(pstr[count])-1] = '\0';//마지막에 엔터 지우기
    }

    //max판별... max문자열, 인덱스 저장
    if(max < strlen(pstr[count])){
      max = strlen(pstr[count]);
      longest = pstr[count];
      maxIndex = count+1;
    }
    //min판별... min문자열, 인덱스 저장
    if(min > strlen(pstr[count])){
      min = strlen(pstr[count]);
      shoetest = pstr[count];
      minIndex = count+1;
    }
  
    count++;
  }
  fclose(file);

  printf("%d lines read.\n", count);
  printf("Longest #%d - %s\n", maxIndex, longest);
  printf("Shortest #%d - %s\n", minIndex, shoetest);



  return 0;
}
