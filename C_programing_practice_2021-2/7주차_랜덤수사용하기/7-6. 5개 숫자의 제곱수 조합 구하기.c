#include <stdio.h>
#include <math.h>
// pow() 함수 활용

/*2에서 9사이의 숫자 5개를 입력받아 배열에 저장한 후, 이 5개의 숫자들 중 임의의 2개의 숫자 a와 b를 선택하여 a^b의 값을 계산하여 이 중에서 가장 큰 수와 가장 작은 수를 만들 수 있는 경우를 찾아내라. 계산 할 때에는 함수 pow()를 사용하라. 예를 들어 2, 3, 4, 5, 6을 입력한 경우에는 가장 작은 수는 2^3이고, 가장 큰 수는 5^6이 된다.*/

int main(void) {
  int number[5];        // 입력받은 5개의 숫자
  int pow_value[5][5];  // 임의의 두 수 a, b로 만들 수 있는 a^b의 값 들
  int max, min;         // 최댓값과 최솟값
  int max_a = 0, max_b = 0;     // 최댓값을 만들어 내는 경우의 a와 b의 값
  int min_a = 9999, min_b = 9999;     // 최솟값을 만들어 내는 경우의 a와 b의 값
  int i, j, k;             // 반복문을 위한 변수 
  int max_index, min_index; //차댓값 차소값 구하기 위한 인덱스 

  printf("2에서 9 사이의 숫자 5개를 입력 \n"); //입력받기 
  for(i = 0; i < 5; i++){
    scanf("%d", &number[i]);
  }

  //정렬하고 맨앞두값 맨뒤두값을 쓸까
  //아니면 최대값 두번쨰최대값 최소값 두번째최소값 일일히 구하기... 

  for(i = 0; i < 5; i++){ //최대 최소값과 그 인덱스 저장 
    if(max_b < number[i]){
      max_b = number[i];
      max_index = i;
    }
    if(min_a > number[i]){
      min_a = number[i];
      min_index = i;
    }
  }

  for(i = 0; i < 5; i++){ //차대 차소값과 구하기(최대최소 인덱스 제외하고 비교 )
    if(i != max_index && max_a < number[i]){
      max_a = number[i];
    }
    if(i != min_index && min_b > number[i]){
      min_b = number[i];
    }
  }

//최대제곱수와 최소제곱수 계산 
  max = (pow(max_a, max_b) > pow(max_b, max_a)) ? pow(max_a, max_b) : pow(max_b, max_a); 
  min = (pow(min_a, min_b) < pow(min_b, min_a)) ? pow(min_a, min_b) : pow(min_b, min_a);

  printf("입력하신 5개의 수로 제곱수를 만들면...\n");
  if(max == pow(max_a, max_b)){
    printf("가장 큰 수는 %d의 %d승인 %d입니다.\n", max_a, max_b, max);
  }else{
    printf("가장 큰 수는 %d의 %d승인 %d입니다.\n", max_b, max_a, max);
  }

  if(min == pow(min_b, min_a)){
    printf("가장 작은 수는 %d의 %d승인 %d입니다.", min_b, min_a, min);
  }else{
    printf("가장 작은 수는 %d의 %d승인 %d입니다.", min_a, min_b, min);
  }


  return 0;
}
