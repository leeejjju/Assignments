// c프로그래밍 과제2
// 세 개의 정수를 입력 받아, 최대값, 최소값 및 평균값을 구하는 프로그램을 작성하시오.

#include <stdio.h>

int main(void){

    int fst, snd, trd;
    int max, min;
	float ave;
    int i;

    scanf("%d %d %d", &fst, &snd, &trd);
    
    max = fst;
    min = fst;
    ave = fst;
    
    if(fst > snd){ //최대값 찾기  
    	if(fst > trd){
    		max = fst;
		}else{
			max = trd;
		}
	}else if(snd > trd){
		max = snd;
	}else{
		max = trd;
	}
	
	if(fst < snd){ //최소값 찾기  
    	if(fst < trd){
    		min = fst;
		}else{
			min = trd;
		}
	}else if(snd < trd){
		min = snd;
	}else{
		min = trd;
	}
    
    ave = (fst + snd + trd) / 3.0 ; //평균값 구하기

    printf("최고값은 %d, 최솟값은 %d, 평균은 %f입니다.", max, min, ave ); //결과를 출력합니다 

    return 0;
}
