#include <stdio.h>

int main(void) {
  int family;                                // 총 가족  
  int children, adult, senior;               // 가족 별 아이, 어른, 노인 수
  int all_children=0, all_adult=0, all_senior=0;   // 아이, 어른, 노인의 합계
  int i, j;                                  // 반복문 사용을 위한 변수 

  printf("전체 가족수는? "); //가족의 수 입력받기 
  scanf("%d", &family);

  for(i = 0; i < family; i++){ //전체가족수만큼 가족구성원의 수 묻기 
    printf("%d번 가족의 아이, 어른, 노인의 숫자는? ", i + 1);
    scanf("%d %d %d", &children, &adult, &senior);

    for(j = 0; j < children; j++){ //아이 수만큼 @출력 
      printf("@");
      all_children += 1;
    }

    if(children != 0){
    printf(" ");
    }

    for(j = 0; j < adult; j++){ //어르 수만큼 # 출력
      printf("#");
      all_adult += 1;
    }

    if(adult != 0){
    printf(" ");
    }

    for(j = 0; j < senior; j++){ // 노인 수만큼 $출력 
      printf("$");
      all_senior += 1;
    }

    printf("\n");

  }


  printf("모든 가족들의 숫자는 다음과 같습니다.\n");

  for(i = 0; i < all_children; i++){
      printf("@");
    }
    if(all_children != 0){
    printf(" ");
    }
    for(i = 0; i < all_adult; i++){
      printf("#");
    }
    if(all_adult != 0){
    printf(" ");
    }
    for(i = 0; i < all_senior; i++){
      printf("$");
    }

  return 0;
}
