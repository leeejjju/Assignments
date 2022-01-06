#include <stdio.h>
#include <string.h>
/*코드 내에 다음과 같이 13개의 학부 이름이 주어졌을 때에, 3글자 이상의 단어를 하나 입력받은 후, 이 단어를 포함 하는 학부 이름을 모두 찾아내 각 학부 이름과 몇 개인지 출력하라.*/

int main(void) {

  char names[13][100]={"Global Leadership School",
  "International Studies, Languages and Literature",
  "Management and Economics",
  "Law",
  "Counseling Psychology and Social Welfare",
  "Communication Arts",
  "Spatial Environment System Engineering",
  "Mechanical and Control Engineering",
  "Contents Convergence Design",
  "Life Science",
  "Computer Science and Electrical Engineering",
  "Global Entrepreneurship and ICT",
  "Creative Convergence Education"};
  char word[100]; //입력받을 검색 단어 
  char same[13][100]; //검색어와 일치하는 전공을 복사, 저장할 공간 
  int count = 0; //일치하는 전공 수
  int i; //반복문 사용을 위한 변수 


  printf("Input >> ");
  scanf("%s", word);

  for(i = 0; i < 13; i++){ //검색어와 일치 검사 
    if(strstr(names[i], word)){
      strcpy(same[count], names[i]);
      count++;
    }
  }

  if(strlen(word) < 3){
    printf("3글자 이상 입력해주세요.");
  }else{
    printf("Matching : \n");
    if(count != 0){
      for(i = 0; i < count; i++){ //저장된 일치 전공 목록을 출력 
        printf("[%s]\n", same[i] );
      }
    }
    printf("%d major found", count);
  }

  return 0;
}

