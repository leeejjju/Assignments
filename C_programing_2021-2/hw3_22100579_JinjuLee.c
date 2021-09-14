// c프로그래밍 과제3
// 성적 산출 프로그램
// -어떤 교과목의 성적 평가를 위하여 각 평가 요소에 대하여 다음과 같이 가중치 비율을 고려한다.

// -중간고사 : 35 %, 기말고사 : 45 %, 과제점수 : 20 %
// -학점의 부여는 총점 기준으로 아래와 같이 절대 평가를 적용한다.

//   - 90점 이상 : A
//   - 80점 이상 : B
//   - 70점 이상 : C
//   - 60점 이상 : D
//   - 60점 미만 : F

//  - 각 평가 요소의 점수를 입력 받아, 최종 학점을 출력하는 프로그램을 작성하시오. 
//   (입력)   중간고사 점수,  기말고사 점수, 과제 점수를 순서대로 입력
//   (출력)   입력된 점수에 대한 학점 (A, B, C, D, F)

#include <stdio.h>

int main(void){

    int middle, final, assign;
    float score;

    printf("중간고사, 기말고사, 과제 점수를 입력하세요. >> ");
    scanf("%d %d %d", &middle, &final, &assign);

    score = middle * 0.35 + final * 0.45 + assign * 0.2;


    if(score >= 90){
        printf("\nA");
    }else if(score >= 80){
        printf("\nB");
    }else if(score >= 70){
        printf("\nC");
    }else if(score >= 60){
        printf("\nD");
    }else{
        printf("\nF");
    }

    return 0;
}
