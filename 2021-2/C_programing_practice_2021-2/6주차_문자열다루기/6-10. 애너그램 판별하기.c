#include <stdio.h>
#include <string.h>

/*문자열 s1, s2 2개를 입력받아 이 두 문자열이 anagram인지 판별하라.

anagram이란 두개의 문자열 속 의 알파벳이 동일한 개수만큼 포함된 것을 말한다.

이때, 알파벳은 소문자만 입력된다고 가정하며, 알파벳 외의 문자들은 무시한다.*/

int main(void){
  char str1[100], str2[100]; //입력받을 문자열 
  int alphacount1[26]={0}, alphacount2[26]={0}; //문자열 속 알파벳 포함 갯수... 
  int i, j, same = 1;

  
  printf("String 1 > ");
  fgets(str1, 100, stdin);
  printf("String 2 > ");
  fgets(str2, 100, stdin);

  for(i = 0; i < strlen(str1); i++){ //문자열 속 알파벳 수 세기1 
    for(j = 97; j < 123; j++){
      if( str1[i] ==j){
        alphacount1[j-97] ++;
        break;
      }  
    }
  }

  for(i = 0; i < strlen(str2); i++){ //문자열 속 알파벳 수 세기1 
    for(j = 97; j < 123; j++){
      if( str2[i] ==j){
        alphacount2[j-97] ++;
        break;
      }  
    }
  }


  for(i = 0; i < 26; i++){ //포함갯수가 하나라도 다르면 same = 0
    if(alphacount1[i] != alphacount2[i]){
      same = 0;
    }
  }

  if(same){
    printf("Anagram!");
  }else{
    printf("Not anagram!");
  }


}
