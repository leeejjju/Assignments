#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*12-5 문제의 답안 소스를 기반으로 데이터파일(data.txt)로부터 텍스트 파일로부터 길이가 다른 여러 개의 문장을 읽어와서 각 문장에 대해서 모음의 개수를 계산하여 문장의 번호와 개수를 출력하라.

단, 문장을 저장하는 문자열은 포인터로 선언하여 메모리를 동적으로 할당받도록 하라. (ch12_03.c 예제소스를 참고하라.)

단, 문장 내 모음의 개수를 세는 작업은 다음과 같은 함수를 제작하여 사용하라.*/

int countVowels(char* str);


int main(void){
  char* pstr[20]; // 실제로 저장될 최대 20개의 문장을 위한 포인터 배열 
  int count = 0;

  FILE* file;
  file = fopen("data.txt", "r");

  while(!feof(file)){
    pstr[count] = malloc(sizeof(char)*200); //count번째 포인터에 200자까지 들어가는 문자열 주소 저장함 
    fgets(pstr[count], 200, file); //글고 거기다가 한줄 읽어서 저장
    if(pstr[count][strlen(pstr[count])-1] == '\n'){
      pstr[count][strlen(pstr[count])-1] = '\0';//마지막에 엔터 지우기
    }
    if(strlen(pstr[count]) != 0){
      count++;
    }
  }
  fclose(file);

  printf("%d lines read.\n", count);
  for(int i = 0; i < count; i++){ //출력 
    printf("#%d - %s [%d]\n", i+1, pstr[i], countVowels(pstr[i]));
  }

  return 0;
}

int countVowels(char* str){
  int countVowels = 0;
  char Vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};

  for(int i = 0; i < strlen(str); i++){
    for(int j = 0; j < 10; j++){
      if(str[i] == Vowels [j]){
        countVowels++;
      }
    }
  }

  return countVowels;
}
// 리턴값 : str 문자열 내에 들어있는 모음의 개수 (모음 종류 : a,e,i,o,u,A,E,I,O,U)
