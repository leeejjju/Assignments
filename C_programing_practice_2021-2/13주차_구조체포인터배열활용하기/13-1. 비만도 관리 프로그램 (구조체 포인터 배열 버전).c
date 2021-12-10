#include <stdio.h>
#include <stdlib.h>
/*비만 판정 함수버전에서 키와 몸무게 데이터를 파일로부터 입력받아 비만도 데이터를 완성하여 출력하라. 제작할 함수는 다음과 같다.
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 이 때, 신장은 미터 단위로 환산해야 함을 유의 하라. 

비만도 수치에 따른 비만도 판정
18.5 미만 : 저체중
18.5 ~ 23 미만 : 정상체중
23~25미만 : 과체중
25이상 : 비만

단, main에서는 다음과 같이 구조체 포인터 배열만을 사용하고, load_bmi()를 통해 메모리를 할당받도록 한다.*/


struct st_bmi{
    int height, weight; 		// 키(cm), 몸무게(kg)
    float bmi; 				// 비만도
    int bmi_index; 			// 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

int loadBmi(struct st_bmi* list[], char* filename);
void evalBmi(struct st_bmi* p);

int main(void) {
	struct st_bmi* bmilist[50];  // 최대 50명의 비만도 데이터
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};
	int count = loadBmi(bmilist, "data.txt");
	// 이곳에 코드 작성!

  printf("%d명의 데이터를 읽었습니다.\n", count);
  for(int i = 0; i < count; i++){
    evalBmi(bmilist[i]);
    printf("%d번 분. 키: %d 몸무게: %d 비만도: %.1f 판정결과 : %s\n", i+1, bmilist[i]->height, bmilist[i]->weight, bmilist[i]->bmi, bmi_string[bmilist[i]->bmi_index-1]);
  }
	return 0;
}

int loadBmi(struct st_bmi* list[], char* filename){
  int count = 0;

  FILE* file;
  file = fopen(filename, "r");

  while(!feof(file)){
    list[count] = malloc(sizeof(struct st_bmi));
    int r = fscanf(file, "%d %d", &list[count]->height, &list[count]->weight);
    if(r < 2){
      break;
    }else{
      count++;
    }
  }

  fclose(file);
  return count;
}
// 파라미터 : 읽을 파일이름 
// 리턴값 : 만들어낸 구조체 데이터 세트의 갯수
// 수행내용 : 파일로부터 키와 몸무게의 데이터를 읽어 list 포인터 배열에 각각 메모리를 할당하여 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 데이터가 연결되도록 한 후, 완성한 데이터 갯수를 리턴

void evalBmi(struct st_bmi* p){

  p->bmi = (p->weight)/((p->height)*(p->height)*0.01*0.01);
  
  if(p->bmi < 18.5){
    p->bmi_index = 1;
  }else if(p->bmi < 23){
    p->bmi_index = 2;
  }else if(p->bmi < 25){
    p->bmi_index = 3;
  }else{
    p->bmi_index = 4;
  }
  
}
// 파라미터 : 비만도 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장 
