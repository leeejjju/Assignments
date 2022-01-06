#include <stdio.h>
#include <string.h>
/*제공된 소스 코드에 주어진 13개의 학부이름 중 가장 긴 것과 가장 짧은 것을 찾아내어 출력하라.*/

int main(void) {
  char names[13][100]={"Global Leadership School","International Studies, Languages and Literature","Management and Economics","Law","Counseling Psychology and Social Welfare", "Communication Arts","Spatial Environment System Engineering", "Mechanical and Control Engineering", "Contents Convergence Design","Life Science","Computer Science and Electrical Engineering", "Global Entrepreneurship and ICT","Creative Convergence Education"};
  char maxStr[100], minStr[100]; //가장 긴것과 짧은 것을 저장할 배열
  int i; //반복문 사용을 위한 변수 

  strcpy(maxStr, names[0]); //배열의 첫값으로 초기값 설정 
  strcpy(minStr, names[0]);
  

  for(i = 0; i < 13; i++){ //최대최소길이 검사, 복사 
    if(strlen(names[i]) > strlen(maxStr)){
      strcpy(maxStr, names[i]); //max에 해당 배열 복사 
    }
    if(strlen(names[i]) < strlen(minStr)){
      strcpy(minStr, names[i]); //min에 해당 배열 복사 
    }
  }
  

  printf("가장 긴 학부 이름은 %s\n", maxStr);
  printf("가장 짧은 학부 이름은 %s 입니다.", minStr);




  return 0;
}
