// c프로그래밍 과제2
// 세 개의 정수를 입력 받아, 최대값, 최소값 및 평균값을 구하는 프로그램을 작성하시오.

#include <stdio.h>
#include <limits.h>

int main(void){

    int array[3];
    int max = INT_MIN, min = INT_MAX, sum = 0;
    int i;

    scanf("%d %d %d", &array[0], &array[1], &array[2]); //배열에 순서대로 입력한 숫자를 저장 

    for(i = 0; i < 3; i++){ //최대값을 max에 저장합니다 
        if(max < array[i]){
            max = array[i];
        }
    }

    for(i = 0; i < 3; i++){ //최소값을 min에 저장합니다
        if(min > array[i]){
            min = array[i];
        }
    }

    for(i = 0; i < 3; i++){ //세 값을 더한 뭉치를 만듭니다
        sum += array[i];
    }

    printf("최고값은 %d, 최솟값은 %d, 평균은 %d입니다.", max, min, sum/3 ); //결과를 출력합니다 

    return 0;
}
