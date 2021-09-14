// c프로그래밍 과제1 
// //섭씨(Celsius) 온도를 화씨(Fahrenheit) 온도로 변환하는 프로그램을 작성 하시오.
// 입력 : 섭씨 온도의 값
// 출력 : 입력 값에 대한 화씨 온도 값
//℉ =℃ * 1.8000+ 32.00

#include <stdio.h>

int main(void){
    float cel, fah ;
    printf("섭씨 온도를 입력하세요 : ");
    scanf("%f", &cel );
    fah =(cel * 1.800) + 32.00;

    printf("%f ℉", fah);


    return 0;
}
