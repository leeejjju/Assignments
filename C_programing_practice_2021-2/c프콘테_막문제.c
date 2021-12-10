/*
C프콘테 막문제였고 애 좀 먹었고 시험종료 3분전에 해결하고 제출함. 이건 해결 전 코드 - 이제해결함 ]
1. 이진주 22100579
2. 나 이진주는 이 문제를 풀어가는데에 하나님과 사람 앞에서 정직하게 임하였음을 선언합니다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*소문자로 이뤄진 영어 단어를 입력받은 후, 이 단어를 암호화한 단어와, 다시 복호화한 단어를 출력하시오.

단, main() 함수 내용은 수정하지 말고, 2개의 함수를 구현하여 완성할 것.
*/


char ref[26]="@BCD#FGH%JKLMN$PQRST&VWXYZ"; // 암호화 참조 문자열
char* encode(char* str);	// 암호화한 문자열 만들기
char* decode(char* str);	// 암호를 푼 문자열 만들기
int i, j;

int main(void) {	// 수정 금지
	char str[100]; // 원래 단어
	char* encoded; // 암호화된 단어
	char* decoded; // 복호화된 단어

	printf("Enter a word.\n");
	scanf("%s", str);

	encoded = encode(str);
	decoded = decode(encoded);

	printf("Encoded string > %s\n", encoded);
	printf("Decoded string > %s\n", decoded);

	return 0;
}

//----------------------------------------------------

char* encode(char* str){
  int num, len;
  for(i = 0; i < strlen(str); i++){
    if(str[i] >= 'a' && str[i] <= 'z'){ //소문자면  
      num = 97;
    }else if(str[i] >= 'A' && str[i] <= 'Z'){//대문자면 
      num = 65;
    }

    len = ((int)str[i]-num)+strlen(str);

    while(1){ //레퍼런스 인덱스 안에 들어가도록 조정 
      if(len < 26) break;
      len -= 26;
    }
    str[i] = ref[len];
    
  }

  return str;
}
/*암호화 규칙

char ref[26]="@BCD#FGH%JKLMN$PQRST&VWXYZ";
단어 각각의 글자들을 글자 알파벳 순서(0~25) + 단어길이를 구해서 이 위치의 암호화 참조 문자로 대체한다.
예를 들어 "abc" 라는 단어는 3글자이므로, 암호화 참조 문자열의 3번 인덱스부터 시작하게 되어 "D#F"로 대체된다.
참조 문자열은 계속 반복되어 연결된다고 가정하라.
*/

char* decode(char* str){

  char* strr = malloc(sizeof(char)*100);
  strcpy(strr, str);
  int index;
  for(i = 0; i < strlen(strr); i++){
    for(j = 0; j < 26; j++){
      if(ref[j] == strr[i]){
        index = j;
        break;
      }
    }
    
    index -= strlen(strr);
	if(index < 0) index +=26;
      

    strr[i] = (char)(index + 97);
  }
  
  return strr;
}
/*복호화 규칙

char ref[26]="@BCD#FGH%JKLMN$PQRST&VWXYZ";
암호화된 단어 각각의 글자들에 대해 암호화 참조 문자열의 위치를 찾아낸 후, 이 위치에서 단어길이만큼 뺀 위치값에 해당되는 알파벳 소문자로 대체한다.
예를 들어 "D#F" 라는 단어는 암호화 참조 문자열의 3,4,5번째 글자이지만, 단어의 길이 3만큼 빼면, 0,1,2번째 글자가 된다. 이에 따라 알파벳 소문자 중 0,1,2번째에 해당하는 "abc"로 대체된다.
참조 문자열은 계속 반복되어 연결된다고 가정하라.*/
